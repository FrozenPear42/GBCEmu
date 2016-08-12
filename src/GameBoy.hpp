//
// Created by Wojciech on 11.08.2016.
//

#ifndef GBCEMU_GAMEBOY_HPP
#define GBCEMU_GAMEBOY_HPP


#include "CPU.hpp"
#include "GPU.hpp"
#include "Audio.hpp"

class GameBoy {
private:
    sf::Window mWindow;

    MemoryManager mMemoryManager;
    CPU mCPU;
    GPU mGPU;
    Audio mAudio;
public:
    GameBoy(std::string pName);
    ~GameBoy();
    int tick();
};


#endif //GBCEMU_GAMEBOY_HPP
