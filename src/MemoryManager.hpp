//
// Created by Wojciech on 10.08.2016.
//

#ifndef GBCEMU_MEMORYMANAGER_HPP
#define GBCEMU_MEMORYMANAGER_HPP


#include <cstdint>

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

    uint8_t VRAM[8192];
    uint8_t IRAM[8192];
public:
    uint8_t readByte(uint16_t pAddr);
    uint16_t readWord(uint16_t pAddr);
    uint16_t readWordLS(uint16_t pAddr);
    void writeByte(uint16_t pAddr, uint8_t pValue);
    void writeWordLS(uint16_t pAddr, uint16_t pValue);
};


#endif //GBCEMU_MEMORYMANAGER_HPP
