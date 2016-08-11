//
// Created by Wojciech on 11.08.2016.
//

#ifndef GBCEMU_GPU_HPP
#define GBCEMU_GPU_HPP

#include "MemoryManager.hpp"

class GPU {
private:
    MemoryManager& mMemory;
public:
    GPU(MemoryManager& pMemory);
    void tick();
};


#endif //GBCEMU_GPU_HPP
