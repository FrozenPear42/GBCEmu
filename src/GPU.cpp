//
// Created by Wojciech on 11.08.2016.
//

#include "GPU.hpp"
#include "Log.hpp"
#include <SFML/Graphics/Sprite.hpp>

GPU::GPU(MemoryManager& pMemory, sf::RenderWindow& pWindow) : mMemory(pMemory), mTicks(0), mMode(0), mWindow(pWindow) {

    mCallback = [&](uint16_t pAddr, uint8_t pData) {
        if ((pAddr & 0x00F0) == 0x0040) {
            // Log::i("GPU register write!");
            // std::cout << "ADDR: " << std::hex << pAddr << " VAL: " << (unsigned) pData << std::endl;
            switch (pAddr & 0x00FF) {
                case 0x40:
                    LCDCAccess(pData);
                    break;
                default:
                    break;
            }
        }
    };

    pMemory.subscribeIO(mCallback);

    pMemory.subscribeVRAM([&](uint16_t pAddr, uint8_t* pVRAM) {
        if (pAddr >= 0x8000 && pAddr < 0x9800) {
            //update tile data

            uint8_t tileID;
            uint8_t tileOffset;
            uint8_t tileFirst;
            uint8_t tileSecond;

            if (pAddr >= 0x8000 && pAddr < 0x8800) {
                //only Tiles1
                tileID = (uint8_t) ((pAddr - 0x8000) / 16);
                tileOffset = (uint8_t) ((pAddr - 0x8000) % 16);
                if (tileOffset % 2 == 0) {
                    tileFirst = pVRAM[(pAddr & 0x1FFF)];
                    tileSecond = pVRAM[(pAddr & 0x1FFF) + 1];
                } else {
                    tileFirst = pVRAM[(pAddr & 0x1FFF) - 1];
                    tileSecond = pVRAM[(pAddr & 0x1FFF)];
                }
                setTileLine(mTiles1, tileID, (uint8_t) (tileOffset / 2), tileFirst, tileSecond);
            } else if (pAddr >= 0x8800 && pAddr < 0x9000) {
                //Tiles0 + Tiles1
            } else if (pAddr >= 0x9000 && pAddr < 0x9800) {
                //only Tiles0
                tileID = (uint8_t) ((pAddr - 0x9000) / 16);
                tileOffset = (uint8_t) ((pAddr - 0x9000) % 16);
                tileID = (uint8_t) (((uint8_t) ((int) tileID - 128)) & 0xFF);

                if (tileOffset % 2 == 0) {
                    tileFirst = pVRAM[(pAddr & 0x1FFF)];
                    tileSecond = pVRAM[(pAddr & 0x1FFF) + 1];
                } else {
                    tileFirst = pVRAM[(pAddr & 0x1FFF) - 1];
                    tileSecond = pVRAM[(pAddr & 0x1FFF)];
                }
                setTileLine(mTiles1, tileID, (uint8_t) (tileOffset / 2), tileFirst, tileSecond);
            }

        } else if (pAddr >= 0x9800 && pAddr < 0x9C00) {
            if (mBGTileMap == 0) {
                mBGTiles[pAddr - 0x9800] = pVRAM[pAddr & 0x1FFF];
            }
        } else if (pAddr >= 0x9C00 && pAddr < 0xA000) {
            if (mBGTileMap == 1) {
                mBGTiles[pAddr - 0x9C00] = pVRAM[pAddr & 0x1FFF];
            }
        }

    });

}


void GPU::setTileLine(uint8_t* pTileSet, uint16_t pTileID, uint8_t pLine, uint8_t pFirst, uint8_t pSecond) {
    for (int i = 0; i < 8; i++) {
        uint8_t color = (uint8_t) (((pFirst >> (7 - i)) & 0x01) | ( ((pSecond >> (7 - i)) & 0x01) << 1)  );

        switch (color) {
            case 0x00:
                pTileSet[pTileID * 256 + 32 * pLine + 4 * i + 0] = 0xFF;
                pTileSet[pTileID * 256 + 32 * pLine + 4 * i + 1] = 0xFF;
                pTileSet[pTileID * 256 + 32 * pLine + 4 * i + 2] = 0xFF;
                pTileSet[pTileID * 256 + 32 * pLine + 4 * i + 3] = 0xFF;
                break;
            case 0x01:
                pTileSet[pTileID * 256 + 32 * pLine + 4 * i + 0] = 0xA0;
                pTileSet[pTileID * 256 + 32 * pLine + 4 * i + 1] = 0xA0;
                pTileSet[pTileID * 256 + 32 * pLine + 4 * i + 2] = 0xA0;
                pTileSet[pTileID * 256 + 32 * pLine + 4 * i + 3] = 0xFF;
                break;
            case 0x02:
                pTileSet[pTileID * 256 + 32 * pLine + 4 * i + 0] = 0x69;
                pTileSet[pTileID * 256 + 32 * pLine + 4 * i + 1] = 0x69;
                pTileSet[pTileID * 256 + 32 * pLine + 4 * i + 2] = 0x69;
                pTileSet[pTileID * 256 + 32 * pLine + 4 * i + 3] = 0xFF;
                break;
            case 0x03:
                pTileSet[pTileID * 256 + 32 * pLine + 4 * i + 0] = 0x00;
                pTileSet[pTileID * 256 + 32 * pLine + 4 * i + 1] = 0x00;
                pTileSet[pTileID * 256 + 32 * pLine + 4 * i + 2] = 0x00;
                pTileSet[pTileID * 256 + 32 * pLine + 4 * i + 3] = 0xFF;
                break;
            default:
                break;
        }
    }
}

GPU::~GPU() {
    mMemory.unsubscribeIO(mCallback);
}

void GPU::LCDCAccess(uint8_t pData) {
    if (((pData & 0x08) >> 3) != mBGTileMap) {
        mBGTileMap = (uint8_t) ((~mBGTileMap) & 0xFE);
        reloadBGTileMap();
    }

    if (((pData & 0x10) >> 4) != mTilesDataSet) {
        mTilesDataSet = (uint8_t) ((~mTilesDataSet) & 0x01);
        reloadBGTileMap();
    }

}

void GPU::tick() {
    mTicks++;

    uint8_t scanLine = mMemory.readByte(0xFF44);
    uint8_t STAT = mMemory.readByte(0xFF41);
    uint8_t interruptMode = (uint8_t) ((STAT & 0x78) >> 3);
    bool interrupt = false;

    switch (mMode) {

        case 0: //in H-BLANK
            if (mTicks < 205)
                break;
            mTicks = 0;
            scanLine++;
            if (scanLine == mMemory.readByte(0xFF45)) //LYC==LC
            {
                STAT |= 0x04;
                if (interruptMode & 0x08)
                    interrupt = true;
            } else {
                STAT &= 0xFB;
            }
            if (scanLine == 144) {
                draw();
                mMode = 1;
                if (interruptMode & 0x02)
                    interrupt = true;
            } else {
                mMode = 2;
                if (interruptMode & 0x04)
                    interrupt = true;
            }
            break;

        case 1: //in V-BLANK
            if (mTicks < 456) // ?????????????? 4560 ?????
                break;
            mTicks = 0;
            scanLine++;
            if (scanLine > 153) {
                mMode = 2;
                if (interruptMode & 0x04)
                    interrupt = true;
                scanLine = 0;
            }
            break;


        case 2: //in OAM Read
            if (mTicks < 80)
                break;
            mTicks = 0;
            mMode = 3;
            break;

        case 3: //in VRAM Read
            if (mTicks < 171)
                break;
            mTicks = 0;
            mMode = 0;
            generateTexture();
            if (interruptMode & 0x01)
                interrupt = true;
            break;

        default:
            throw std::string("Invalid video mode");
    }

    if (interrupt)
        mMemory.writeByte(0xFF0F, (uint8_t) (mMemory.readByte(0xFF0F) | 0x01), true);

    mMemory.writeByte(0xFF44, scanLine, true);
    mMemory.writeByte(0xFF41, (uint8_t) ((STAT & 0xFC) | mMode), true);

}

void GPU::draw() {
    mWindow.clear(sf::Color::White);
    auto bg = sf::Sprite(mBGTexture);
    mWindow.draw(bg);
    mWindow.display();
    //TODO: Draw
}

void GPU::generateTexture() {
    //TODO: Generate Texture
    mBGTexture.create(256, 256);
    for (uint32_t x = 0; x < 32; x++) {
        for (uint32_t y = 0; y < 32; y++) {
            uint8_t tileID = mBGTiles[y * 32 + x];
            if (mTilesDataSet == 0) {
                mBGTexture.update(mTiles0 + 256 * tileID, 8, 8, x * 8, y * 8);
            }
            else if (mTilesDataSet == 1) {
                mBGTexture.update(mTiles1 + 256 * tileID, 8, 8, x * 8, y * 8);
            }
        }
    }

}

void GPU::reloadBGTileMap() {

}
