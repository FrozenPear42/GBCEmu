//
// Created by Wojciech on 10.08.2016.
//

#ifndef GBCEMU_CARTRIDGE_HPP
#define GBCEMU_CARTRIDGE_HPP


#include <cstdint>
#include <string>

class Cartridge {

    enum class CartridgeController {
        NONE = 0x01,
        MBC1 = 0x02,
        MBC2 = 0x04,
        MMM01 = 0x08,
        MBC3 = 0x10,
        MBC5 = 0x20,
        HUC3 = 0x40
    };

    uint8_t* mROM0;
    uint8_t* mROM1;
    uint8_t* mRAM;

    uint8_t mROMBanks;
    uint8_t mRAMBanks;
    uint8_t mSelectedROMBank;
    uint8_t mSelectedRAMBank;

    std::string mGameName;
    bool mColor;
    bool mSGB;
    uint8_t mType;
    CartridgeController mController;

public:
    Cartridge() {
        mROM0 = new uint8_t[0x4000];
        mRAM = new uint8_t[0x2000];
    }

    Cartridge(std::string pFileName);

    ~Cartridge() {
        delete mRAM;
        delete mROM0;
    }

    void writeByte(uint16_t pAddr, uint8_t pValue);

    uint8_t readByte(uint16_t pAddr);
};


#endif //GBCEMU_CARTRIDGE_HPP
