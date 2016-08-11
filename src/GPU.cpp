//
// Created by Wojciech on 11.08.2016.
//

#include "GPU.hpp"
#include "Log.hpp"


GPU::GPU(MemoryManager& pMemory) : mMemory(pMemory), mTicks(0), mMode(0) {

    mCallback = [&](uint16_t pAddr, uint8_t pData) {
        if ((pAddr & 0x00F0) == 0x0040) {
            Log::i("GPU register write!");
            std::cout << "ADDR: " << std::hex << pAddr << " VAL: " << (unsigned) pData << std::endl;
        }
    };

    pMemory.subscribeForIOChange(mCallback);
}

GPU::~GPU() {
    mMemory.unsubscribeForIOChange(mCallback);
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
            if (mTicks < 4560) // ?????????????? 456 ?????
                break;
            mTicks = 0;
            scanLine++;
            if (scanLine > 153) {
                mMode = 2;
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
    mMemory.writeByte(0xFF41, (uint8_t) ((STAT & 0x03) | mMode), true);

}

void GPU::draw() {
    //TODO: Draw
}

void GPU::generateTexture() {
    //TODO: Generate Texture
}
