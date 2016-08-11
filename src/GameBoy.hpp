//
// Created by Wojciech on 11.08.2016.
//

#ifndef GBCEMU_GAMEBOY_HPP
#define GBCEMU_GAMEBOY_HPP


#include "CPU.hpp"
#include "GPU.hpp"

class GameBoy {
private:
    CPU mCPU;
    GPU mGPU;
    MemoryManager mMemoryManager;
public:
    GameBoy();
    void tick();
};


#endif //GBCEMU_GAMEBOY_HPP
