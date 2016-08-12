//
// Created by Wojciech on 10.08.2016.
//

#include "MemoryManager.hpp"
#include "Log.hpp"

MemoryManager::MemoryManager() : mCartridge("C:\\rom.gb") { }

uint8_t MemoryManager::readByte(uint16_t pAddr) {

    if (mStartup && pAddr <= 0x00FF)
        return mBIOS[pAddr];

    switch (pAddr & 0xF000) {
        /* ROM0 */
        case 0x0000:
        case 0x1000:
        case 0x2000:
        case 0x3000:
            /* ROM switchable */
        case 0x4000:
        case 0x5000:
        case 0x6000:
        case 0x7000:
            /* External RAM */
        case 0xA000:
        case 0xB000:
            return mCartridge.readByte(pAddr);

            /* Video RAM */
        case 0x8000:
        case 0x9000:
            return mVRAM[pAddr & 0x1FFF];

            /* Internal RAM */
        case 0xC000:
        case 0xD000:
        case 0xE000:
            return mIRAM[pAddr & 0x1FFF];
        case 0xF000:
            switch (pAddr & 0x0F00) {
                /* Internal RAM + Echo */
                case 0x0000:
                case 0x0100:
                case 0x0200:
                case 0x0300:
                case 0x0400:
                case 0x0500:
                case 0x0600:
                case 0x0700:
                case 0x0800:
                case 0x0900:
                case 0x0A00:
                case 0x0B00:
                case 0x0C00:
                case 0x0D00:
                    return mIRAM[pAddr & 0x1FFF];

                    /* OBJ RAM */
                case 0x0E00:
                    if ((pAddr & 0xFF) < 0xA0)
                        return mORAM[pAddr & 0xFF];
                    else
                        return 0x00;
                    /* I/O, Zero Page, Interrupts */
                case 0x0F00:
                    if (pAddr == 0xFFFF) return mInterruptEnable;
                    else if (pAddr >= 0xFF80) return mZRAM[pAddr & 0x007F];
                    else return mIO[pAddr & 0x00FF];
            }
            break;

    }
    return 0;
}

uint16_t MemoryManager::readWordLS(uint16_t pAddr) {

    uint8_t a = readByte(pAddr);
    uint8_t b = readByte((uint16_t) (pAddr + 1));

    return ((b << 8) | a);
}

void MemoryManager::writeByte(uint16_t pAddr, uint8_t pValue, bool pSilent) {
    switch (pAddr & 0xF000) {
        case 0x0000:
        case 0x1000:
        case 0x2000:
        case 0x3000:
        case 0x4000:
        case 0x5000:
        case 0x6000:
        case 0x7000:
        case 0xA000:
        case 0xB000:
            mCartridge.writeByte(pAddr, pValue);
            break;
        case 0x8000:
        case 0x9000:
            mVRAM[pAddr & 0x1FFF] = pValue;
            break;
        case 0xC000:
        case 0xD000:
        case 0xE000:
            mIRAM[pAddr & 0x1FFF] = pValue;
            break;
        case 0xF000:
            switch (pAddr & 0x0F00) {
                /* Internal RAM + Echo */
                case 0x0000:
                case 0x0100:
                case 0x0200:
                case 0x0300:
                case 0x0400:
                case 0x0500:
                case 0x0600:
                case 0x0700:
                case 0x0800:
                case 0x0900:
                case 0x0A00:
                case 0x0B00:
                case 0x0C00:
                case 0x0D00:
                    mIRAM[pAddr & 0x1FFF] = pValue;
                    break;
                case 0x0E00:
                    mORAM[pAddr & 0x00FF] = pValue;
                    break;
                case 0x0F00:
                    if (pAddr == 0xFFFF) mInterruptEnable = pValue;
                    else if (pAddr >= 0xFF80) mZRAM[pAddr & 0x007F] = pValue;
                    else {
                        mIO[pAddr & 0x00FF] = pValue;
                        for (auto call : mCallbacks) {
                            if (call && !pSilent)
                                call(pAddr, pValue);
                        }
                    }
                    break;
            }
            break;
    }
}

void MemoryManager::writeWordLS(uint16_t pAddr, uint16_t pValue) {
    writeByte(pAddr, (uint8_t) (pValue & 0x00FF));
    writeByte((uint16_t) (pAddr + 1), (uint8_t) ((pValue & 0xFF00) >> 8));
}

void MemoryManager::subscribeForIOChange(std::function<void(uint16_t, uint8_t)>& pCallback) {
    mCallbacks.push_back(pCallback);
    Log::i("Gotta new callback");
}

void MemoryManager::unsubscribeForIOChange(std::function<void(uint16_t, uint8_t)>& pCallback) {
    //TODO: remove pCallback from mCallbacks
}

void MemoryManager::finishStartup() {
    mStartup = false;
}




