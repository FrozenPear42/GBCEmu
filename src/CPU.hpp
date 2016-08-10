//
// Created by Wojciech on 10.08.2016.
//

#ifndef GBCEMU_CPU_HPP
#define GBCEMU_CPU_HPP

#include <cstdint>
#include "MemoryManager.hpp"

class CPU {
private:
    /** Struct for CPU registers */
    struct {
        union {
            uint16_t AF;
            struct {
                uint8_t A : 8;
                uint8_t F : 8;
            };
        };
        union {
            uint16_t BC;
            struct {
                uint8_t B : 8;
                uint8_t C : 8;
            };
        };
        union {
            uint16_t DE;
            struct {
                uint8_t D : 8;
                uint8_t E : 8;
            };
        };
        union {
            uint16_t HL;
            struct {
                uint8_t H : 8;
                uint8_t L : 8;
            };
        };
    } mGPRegisters;

    struct {
        uint16_t SP;
        uint16_t PC;
        uint8_t FLAG;
    } mMainRegisters;

    MemoryManager mMemory;
public:
    void tick();

private:
    void wait(uint8_t pCycles);
};


#endif //GBCEMU_CPU_HPP
