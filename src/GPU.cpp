//
// Created by Wojciech on 11.08.2016.
//

#include "GPU.hpp"
#include "Log.hpp"


GPU::GPU(MemoryManager& pMemory) : mMemory(pMemory) {

    mCallback = [&](uint16_t pAddr, uint8_t pData) {
        if ((pAddr & 0x00F0) == 0x0040) {
            Log::i("GPU register write!");
        }
    };

    pMemory.subscribeForIOChange(mCallback);
}

GPU::~GPU() {
    mMemory.unsubscribeForIOChange(mCallback);
}

void GPU::tick() {

}
