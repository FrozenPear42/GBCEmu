//
// Created by Wojciech on 10.08.2016.
//

#ifndef GBCEMU_CPU_HPP
#define GBCEMU_CPU_HPP

#include <cstdint>
#include "MemoryManager.hpp"

#define FLAGS(z, n, h, c) ((uint8_t) ( (z & 0x01) << 7 | (n & 0x01) << 6 | (h & 0x01) << 5 | (c & 0x01) << 4) )
#define F_ZERO(flags) ((flags >> 7) & 0x01)
#define F_SUB(flags) ((flags >> 6) & 0x01)
#define F_HALF(flags) ((flags >> 5) & 0x01)
#define F_CARRY(flags) ((uint8_t)((flags >> 4) & 0x01))


class CPU {
private:
    /** Struct for CPU registers */
    struct {
        union {
            uint16_t AF;
            struct {
                uint8_t A;
                uint8_t F;
            };
        };
        union {
            uint16_t BC;
            struct {
                uint8_t B;
                uint8_t C;
            };
        };
        union {
            uint16_t DE;
            struct {
                uint8_t D;
                uint8_t E;
            };
        };
        union {
            uint16_t HL;
            struct {
                uint8_t H;
                uint8_t L;
            };
        };
    } mGPRegisters;

    struct {
        uint16_t SP;
        uint16_t PC;
        uint8_t FLAG;
        uint8_t IE;
    } mMainRegisters;

    uint8_t mJump = 0;
    uint8_t mHalt = 0;


    MemoryManager mMemory;
public:
    CPU();
    void tick();
    void log();
private:
    void wait(uint8_t pCycles);
};


#endif //GBCEMU_CPU_HPP
