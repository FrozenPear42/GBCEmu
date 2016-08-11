//
// Created by Wojciech on 11.08.2016.
//

#ifndef GBCEMU_AUDIO_HPP
#define GBCEMU_AUDIO_HPP


#include "MemoryManager.hpp"

class Audio {
private:
    MemoryManager& mMemory;
    std::function<void (uint16_t, uint8_t)> mCallback;
public:
    Audio(MemoryManager& pMemory);
};


#endif //GBCEMU_AUDIO_HPP
