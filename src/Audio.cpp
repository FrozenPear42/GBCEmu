//
// Created by Wojciech on 11.08.2016.
//

#include "Audio.hpp"
#include "Log.hpp"

Audio::Audio(MemoryManager& pMemory) : mMemory(pMemory) {
    mCallback = [&](uint16_t pAddr, uint8_t pData) {
        if ((pAddr & 0x00F0) < 0x0040 && (pAddr & 0x00F0) >= 0x0010) {
            Log::i("AUDIO register write!");
            std::cout << "ADDR: " << std::hex << pAddr << " VAL: " << (unsigned) pData << std::endl;
        }
    };
    pMemory.subscribeForIOChange(mCallback);
}