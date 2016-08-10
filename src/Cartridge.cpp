//
// Created by Wojciech on 10.08.2016.
//

#include "Cartridge.hpp"

uint8_t Cartridge::readByte(uint16_t pAddr) {
    return mROM[pAddr];
}

void Cartridge::writeByte(uint16_t pAddr, uint8_t pValue) {
}