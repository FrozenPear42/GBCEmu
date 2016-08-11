//
// Created by Wojciech on 11.08.2016.
//

#ifndef GBCEMU_GAMEBOY_HPP
#define GBCEMU_GAMEBOY_HPP


#include "CPU.hpp"
#include "GPU.hpp"

class GameBoy {
private:
    MemoryManager mMemoryManager;
    CPU mCPU;
    GPU mGPU;
public:
    GameBoy();
    void tick();
};


#endif //GBCEMU_GAMEBOY_HPP
