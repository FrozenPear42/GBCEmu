//
// Created by Wojciech on 10.08.2016.
//

#ifndef GBCEMU_CARTRIDGE_HPP
#define GBCEMU_CARTRIDGE_HPP


#include <cstdint>

class Cartridge {
    uint8_t* mROM;
    uint8_t* mRAM;
public:
    Cartridge() {
        mRAM = new uint8_t[0x2000];
        mROM = new uint8_t[0x4000];
    }
    ~Cartridge() {
        delete mRAM;
        delete mROM;
    }
    void writeByte(uint16_t pAddr, uint8_t pValue);
    uint8_t readByte(uint16_t pAddr);
};


#endif //GBCEMU_CARTRIDGE_HPP
