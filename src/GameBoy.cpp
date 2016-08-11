//
// Created by Wojciech on 11.08.2016.
//

#include "GameBoy.hpp"

GameBoy::GameBoy() : mMemoryManager(), mCPU(mMemoryManager), mGPU(mMemoryManager), mAudio(mMemoryManager) {
    Cartridge("C:\\rom.gb");
}

void GameBoy::tick() {
    mCPU.tick();
    mGPU.tick();
   // mCPU.log();
}



