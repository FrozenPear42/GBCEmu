//
// Created by Wojciech on 11.08.2016.
//

#include "Audio.hpp"
#include "Log.hpp"

Audio::Audio(MemoryManager& pMemory) : mMemory(pMemory) {
    mCallback = [&](uint16_t pAddr, uint8_t pData) {
        if (!(pAddr & 0x00C0) && pAddr >= 0xFF10) {
            Log::i("AUDIO register write!");
            std::cout << "ADDR: " << std::hex << pAddr << " VAL: " << (unsigned) pData << std::endl;
        }
    };
    pMemory.subscribeForIOChange(mCallback);
}