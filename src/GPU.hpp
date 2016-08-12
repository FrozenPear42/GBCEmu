//
// Created by Wojciech on 11.08.2016.
//

#ifndef GBCEMU_GPU_HPP
#define GBCEMU_GPU_HPP

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>
#include "MemoryManager.hpp"

class GPU {
private:
    std::function<void(uint16_t, uint8_t)> mCallback;

    MemoryManager& mMemory;
    uint8_t mMode;
    unsigned mTicks;

    uint8_t mBGTileMap = 0;
    uint8_t mWindowTileMap = 0;
    uint8_t mTilesDataSet = 0;
    uint8_t mTiles0[256 * 8 * 8 * 4] = {0};
    uint8_t mTiles1[256 * 8 * 8 * 4] = {0};

    uint8_t mBGTiles[1024] = {0};

    sf::RenderWindow& mWindow;
    sf::Texture mBGTexture;
public:
    GPU(MemoryManager& pMemory, sf::RenderWindow& pWindow);

    ~GPU();

    void tick();

private:
    void draw();

    void generateTexture();

    void LCDCAccess(uint8_t pData);

    void reloadBGTileMap();

    void setTileLine(uint8_t* pTileSet, uint16_t pTileID, uint8_t pLine, uint8_t pFirst, uint8_t pSecond);
};


#endif //GBCEMU_GPU_HPP
