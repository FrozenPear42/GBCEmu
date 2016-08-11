//
// Created by Wojciech on 10.08.2016.
//

#ifndef GBCEMU_MEMORYMANAGER_HPP
#define GBCEMU_MEMORYMANAGER_HPP


#include <cstdint>
#include <functional>
#include <vector>
#include "Cartridge.hpp"

class MemoryManager {
    /*
    uint8_t mIO[0x4c];

    struct {
        uint8_t *P = mIO + 0x00;     //FF00 Joypad reading

        uint8_t *SB     = mIO + 0x01;     //FF01 serial in/out
        uint8_t *SC     = mIO + 0x02;     //FF02 serial control

        uint8_t *DIV    = mIO + 0x04;    //FF04 divider register
        uint8_t *TIMA   = mIO + 0x05;   //FF05 Timer/Counter value
        uint8_t *TMA    = mIO + 0x06;    //FF06 Timer modulo - value to be loaded into TIMA after overflow
        uint8_t *TAC    = mIO + 0x07;    //FF07 Timer control register

        uint8_t *IF     = mIO + 0x0F;     //FF0F Interrupt flags

        uint8_t *NR10   = mIO + 0x10;   //FF10 Sound 1 - sweep
        uint8_t *NR11   = mIO + 0x11;   //FF11 Sound 1 - duty
        uint8_t *NR12   = mIO + 0x12;   //FF12 Sound 1 - envelope
        uint8_t *NR13   = mIO + 0x13;   //FF13 Sound 1 - freq low
        uint8_t *NR14   = mIO + 0x14;   //FF14 Sound 1 - freq high

        uint8_t *NR21   = mIO + 0x16;   //FF16 Sound 2 - duty
        uint8_t *NR22   = mIO + 0x17;   //FF17 Sound 2 - envelope
        uint8_t *NR23   = mIO + 0x18;   //FF18 Sound 2 - freq low
        uint8_t *NR24   = mIO + 0x19;   //FF19 Sound 2 - freq high

        uint8_t *NR30   = mIO + 0x1A;   //FF1A Sound 3 - on/off
        uint8_t *NR31   = mIO + 0x1B;   //FF1B Sound 3 - length
        uint8_t *NR32   = mIO + 0x1C;   //FF1C Sound 3 - output level
        uint8_t *NR33   = mIO + 0x1D;   //FF1D Sound 3 - freq low
        uint8_t *NR34   = mIO + 0x1E;   //FF1E Sound 3 - freq high

        uint8_t *NR41   = mIO + 0x20;   //FF20 Sound 4 - length
        uint8_t *NR42   = mIO + 0x21;   //FF21 Sound 4 - envelope
        uint8_t *NR43   = mIO + 0x22;   //FF22 Sound 4 - polynomial counter
        uint8_t *NR44   = mIO + 0x23;   //FF23 Sound 4 - counter control

        uint8_t *NR50   = mIO + 0x24;   //FF24 Sound - channel
        uint8_t *NR51   = mIO + 0x25;   //FF25 Sound - output
        uint8_t *NR52   = mIO + 0x26;   //FF26 Sound - sound control

        uint8_t *WAV    = mIO + 0x30;   //FF30-FF3F - wave pattern RAM

    } mIORegisters;
    */

    uint8_t mBIOS[256] = {
            0x31, 0xFE, 0xFF, 0xAF, 0x21, 0xFF, 0x9F, 0x32, 0xCB, 0x7C, 0x20, 0xFB, 0x21, 0x26, 0xFF, 0x0E,
            0x11, 0x3E, 0x80, 0x32, 0xE2, 0x0C, 0x3E, 0xF3, 0xE2, 0x32, 0x3E, 0x77, 0x77, 0x3E, 0xFC, 0xE0,
            0x47, 0x11, 0x04, 0x01, 0x21, 0x10, 0x80, 0x1A, 0xCD, 0x95, 0x00, 0xCD, 0x96, 0x00, 0x13, 0x7B,
            0xFE, 0x34, 0x20, 0xF3, 0x11, 0xD8, 0x00, 0x06, 0x08, 0x1A, 0x13, 0x22, 0x23, 0x05, 0x20, 0xF9,
            0x3E, 0x19, 0xEA, 0x10, 0x99, 0x21, 0x2F, 0x99, 0x0E, 0x0C, 0x3D, 0x28, 0x08, 0x32, 0x0D, 0x20,
            0xF9, 0x2E, 0x0F, 0x18, 0xF3, 0x67, 0x3E, 0x64, 0x57, 0xE0, 0x42, 0x3E, 0x91, 0xE0, 0x40, 0x04,
            0x1E, 0x02, 0x0E, 0x0C, 0xF0, 0x44, 0xFE, 0x90, 0x20, 0xFA, 0x0D, 0x20, 0xF7, 0x1D, 0x20, 0xF2,
            0x0E, 0x13, 0x24, 0x7C, 0x1E, 0x83, 0xFE, 0x62, 0x28, 0x06, 0x1E, 0xC1, 0xFE, 0x64, 0x20, 0x06,
            0x7B, 0xE2, 0x0C, 0x3E, 0x87, 0xF2, 0xF0, 0x42, 0x90, 0xE0, 0x42, 0x15, 0x20, 0xD2, 0x05, 0x20,
            0x4F, 0x16, 0x20, 0x18, 0xCB, 0x4F, 0x06, 0x04, 0xC5, 0xCB, 0x11, 0x17, 0xC1, 0xCB, 0x11, 0x17,
            0x05, 0x20, 0xF5, 0x22, 0x23, 0x22, 0x23, 0xC9, 0xCE, 0xED, 0x66, 0x66, 0xCC, 0x0D, 0x00, 0x0B,
            0x03, 0x73, 0x00, 0x83, 0x00, 0x0C, 0x00, 0x0D, 0x00, 0x08, 0x11, 0x1F, 0x88, 0x89, 0x00, 0x0E,
            0xDC, 0xCC, 0x6E, 0xE6, 0xDD, 0xDD, 0xD9, 0x99, 0xBB, 0xBB, 0x67, 0x63, 0x6E, 0x0E, 0xEC, 0xCC,
            0xDD, 0xDC, 0x99, 0x9F, 0xBB, 0xB9, 0x33, 0x3E, 0x3c, 0x42, 0xB9, 0xA5, 0xB9, 0xA5, 0x42, 0x4C,
            0x21, 0x04, 0x01, 0x11, 0xA8, 0x00, 0x1A, 0x13, 0xBE, 0x20, 0xFE, 0x23, 0x7D, 0xFE, 0x34, 0x20,
            0xF5, 0x06, 0x19, 0x78, 0x86, 0x23, 0x05, 0x20, 0xFB, 0x86, 0x20, 0xFE, 0x3E, 0x01, 0xE0, 0x50,
    };

/*
    uint8_t mBIOS[17] = {
            0x00, 0x3E, 0x11, 0xE0, 0x44, 0x00, 0x76
    };
*/
    Cartridge mCartridge;
    bool mStartup = true;

    uint8_t mVRAM[0x2000] = {0};
    uint8_t mIRAM[0x2000] = {0};
    uint8_t mORAM[0xA0] = {0};
    uint8_t mIO[0x4C] = {0};
    uint8_t mZRAM[0x80] = {0};
    uint8_t mInterruptFlags = 0;
    std::vector<std::function<void(uint16_t, uint8_t)> > mCallbacks;

public:
    uint8_t readByte(uint16_t pAddr);

    uint16_t readWordLS(uint16_t pAddr);

    void writeByte(uint16_t pAddr, uint8_t pValue);

    void writeWordLS(uint16_t pAddr, uint16_t pValue);

    void subscribeForIOChange(std::function<void(uint16_t, uint8_t)>& pCallback);

    void unsubscribeForIOChange(std::function<void(uint16_t, uint8_t)>& pCallback);
};


#endif //GBCEMU_MEMORYMANAGER_HPP
