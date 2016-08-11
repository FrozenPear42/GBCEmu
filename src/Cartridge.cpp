//
// Created by Wojciech on 10.08.2016.
//

#include <bits/ios_base.h>
#include <ios>
#include <fstream>
#include "Cartridge.hpp"
#include "Log.hpp"


Cartridge::Cartridge(std::string pFileName) {
    std::ifstream stream(pFileName.c_str(), std::ios::binary);
    if (!stream.is_open())
        throw std::string("Could not open file");
    mROM0 = new uint8_t[0x4000];
    stream.read((char*) mROM0, 0x4000);

    mGameName = std::string((char*) (mROM0 + 0x0134), 15);
    Log::i("Game: " + mGameName);

    mColor = (mROM0[0x0143] == 0x80);
    mSGB = (mROM0[0x0146] == 0x03);
    mType = mROM0[0x0147];

    switch (mType) {
        case 0x00:
        case 0x08:
        case 0x09:
            mController = CartridgeController::NONE;
            break;
        case 0x01:
        case 0x02:
        case 0x03:
            mController = CartridgeController::MBC1;
            break;
        case 0x05:
        case 0x06:
            mController = CartridgeController::MBC2;
            break;
        case 0x0B:
        case 0x0C:
        case 0x0D:
            mController = CartridgeController::MMM01;
            throw std::string("unsupported controller type");
            break;
        case 0x0F:
        case 0x10:
        case 0x11:
        case 0x12:
        case 0x13:
            mController = CartridgeController::MBC3;
            break;
        case 0x19:
        case 0x1A:
        case 0x1B:
        case 0x1C:
        case 0x1D:
        case 0x1E:
            mController = CartridgeController::MBC5;
            throw std::string("unsupported controller type");
            break;
        case 0xFE:
            mController = CartridgeController::HUC3;
            break;
        default:
            throw std::string("Invalid controller type");
    }


    switch (mROM0[0x0148]) {
        case 0x00:
        case 0x01:
        case 0x02:
        case 0x03:
        case 0x04:
        case 0x05:
        case 0x06:
            mROMBanks = (uint8_t) (2 << mROM0[0x0148]);
            break;
        case 0x52:
            mROMBanks = 72;
            break;
        case 0x53:
            mROMBanks = 80;
            break;
        case 0x54:
            mROMBanks = 96;
            break;
        default:
            throw std::string("Invalid ROM size");
    }

    switch (mROM0[0x0149]) {
        case 0x00:
            mRAMBanks = 0;
            break;
        case 0x01:
        case 0x02:
            mRAMBanks = 1;
            break;
        case 0x03:
            mRAMBanks = 4;
            break;
        case 0x04:
            mRAMBanks = 16;
            break;
        default:
            throw std::string("Invalid RAM size");
    }

    mROM1 = new uint8_t[(mROMBanks - 1) * 0x4000];
    stream.read((char*) mROM1, (mROMBanks - 1) * 0x4000);
    stream.close();

    mRAM = new uint8_t[mRAMBanks * 0x2000];

    mSelectedROMBank = 1;
    mSelectedRAMBank = 0;
}

uint8_t Cartridge::readByte(uint16_t pAddr) {
    switch (pAddr & 0xF000) {
        case 0x0000:
        case 0x1000:
        case 0x2000:
        case 0x3000:
            return mROM0[pAddr];
        case 0x4000:
        case 0x5000:
        case 0x6000:
        case 0x7000:
            return mROM1[pAddr - 0x4000 + (mSelectedROMBank - 1) * 0x4000];
        case 0xA000:
        case 0xB000:
            return mRAM[pAddr - 0x2000 + mSelectedRAMBank * 0x2000];
        default:
            throw std::string("Trying to read invalid address in cartridge");
    }
}

void Cartridge::writeByte(uint16_t pAddr, uint8_t pValue) {
    switch (pAddr & 0xF000) {
        case 0x0000:
        case 0x1000:
            break;
        case 0x2000:
        case 0x3000:
            if (static_cast<int>(mController) & (static_cast<int>(CartridgeController::MBC1) |
                                                 static_cast<int>(CartridgeController::MBC2) |
                                                 static_cast<int>(CartridgeController::MBC3) |
                                                 static_cast<int>(CartridgeController::HUC3))) {
                mSelectedROMBank = (uint8_t) (pValue & 0x1F);
                if (mSelectedROMBank == 0) mSelectedROMBank = 1;
            }
            break;
        case 0x4000:
        case 0x5000:
            break;
        case 0x6000:
        case 0x7000:
            break;
        case 0xA000:
        case 0xB000:
            mRAM[pAddr - 0x2000 + mSelectedRAMBank * 0x2000] = pValue;
            break;
        default:
            throw std::string("Trying to write invalid address in cartridge");
    }
}
