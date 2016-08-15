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
                uint8_t F;
                uint8_t A;
            };
        };
        union {
            uint16_t BC;
            struct {
                uint8_t C;
                uint8_t B;
            };
        };
        union {
            uint16_t DE;
            struct {
                uint8_t E;
                uint8_t D;
            };
        };
        union {
            uint16_t HL;
            struct {
                uint8_t L;
                uint8_t H;
            };
        };
    } mGPRegisters;

    struct {
        uint16_t SP;
        uint16_t PC;
        bool IME;
    } mMainRegisters;

    std::array<std::function<uint8_t(void)>, 256> mOPTable;
    uint8_t mWait = 0;
    uint8_t mJump = 0;
    uint8_t mHalt = 0;

    MemoryManager &mMemory;
public:
    CPU(MemoryManager &pMemory);
    void tick();
    void log();

private:
    void initTables();
};


#endif //GBCEMU_CPU_HPP
