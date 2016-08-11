//
// Created by Wojciech on 11.08.2016.
//

#ifndef GBCEMU_GPU_HPP
#define GBCEMU_GPU_HPP

#include "MemoryManager.hpp"

class GPU {
private:
    std::function<void(uint16_t, uint8_t)> mCallback;
    MemoryManager& mMemory;
    uint8_t mMode;
    unsigned mTicks;
public:
    GPU(MemoryManager& pMemory);

    ~GPU();

    void tick();

private:
    void draw();
    void generateTexture();
};


#endif //GBCEMU_GPU_HPP
