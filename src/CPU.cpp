//
// Created by Wojciech on 10.08.2016.
//

#include "CPU.hpp"

void CPU::tick() {
    uint8_t OPCode;
    OPCode = mMemory.readByte(mMainRegisters.PC);

    switch (OPCode) {
        /* LD */
        case 0x3E:
            mGPRegisters.A = mMemory.readByte(++mMainRegisters.PC);
            break;
        case 0x06:
            mGPRegisters.B = mMemory.readByte(++mMainRegisters.PC);
            break;
        case 0x0E:
            mGPRegisters.C = mMemory.readByte(++mMainRegisters.PC);
            break;
        case 0x16:
            mGPRegisters.D = mMemory.readByte(++mMainRegisters.PC);
            break;
        case 0x1E:
            mGPRegisters.E = mMemory.readByte(++mMainRegisters.PC);
            break;
        case 0x26:
            mGPRegisters.H = mMemory.readByte(++mMainRegisters.PC);
            break;
        case 0x2E:
            mGPRegisters.L = mMemory.readByte(++mMainRegisters.PC);
            break;

        case 0x7F:
            mGPRegisters.A = mGPRegisters.A;
            break;
        case 0x78:
            mGPRegisters.A = mGPRegisters.B;
            break;
        case 0x79:
            mGPRegisters.A = mGPRegisters.C;
            break;
        case 0x7A:
            mGPRegisters.A = mGPRegisters.D;
            break;
        case 0x7B:
            mGPRegisters.A = mGPRegisters.E;
            break;
        case 0x7C:
            mGPRegisters.A = mGPRegisters.H;
            break;
        case 0x7D:
            mGPRegisters.A = mGPRegisters.L;
            break;
        case 0x7E:
            mGPRegisters.A = mMemory.readByte(mGPRegisters.HL);
            break;
        case 0x0A:
            mGPRegisters.A = mMemory.readByte(mGPRegisters.BC);
            break;
        case 0x1A:
            mGPRegisters.A = mMemory.readByte(mGPRegisters.DE);
            break;
        case 0xFA:
            mGPRegisters.A = mMemory.readByte(mMemory.readWordLS(++mMainRegisters.PC));
            ++mMainRegisters.PC;
            break;

        case 0x47:
            mGPRegisters.B = mGPRegisters.A;
            break;
        case 0x40:
            mGPRegisters.B = mGPRegisters.B;
            break;
        case 0x41:
            mGPRegisters.B = mGPRegisters.C;
            break;
        case 0x42:
            mGPRegisters.B = mGPRegisters.D;
            break;
        case 0x43:
            mGPRegisters.B = mGPRegisters.E;
            break;
        case 0x44:
            mGPRegisters.B = mGPRegisters.H;
            break;
        case 0x45:
            mGPRegisters.B = mGPRegisters.L;
            break;
        case 0x46:
            mGPRegisters.B = mMemory.readByte(mGPRegisters.HL);
            break;

        case 0x4F:
            mGPRegisters.C = mGPRegisters.A;
            break;
        case 0x48:
            mGPRegisters.C = mGPRegisters.B;
            break;
        case 0x49:
            mGPRegisters.C = mGPRegisters.C;
            break;
        case 0x4A:
            mGPRegisters.C = mGPRegisters.D;
            break;
        case 0x4B:
            mGPRegisters.C = mGPRegisters.E;
            break;
        case 0x4C:
            mGPRegisters.C = mGPRegisters.H;
            break;
        case 0x4D:
            mGPRegisters.C = mGPRegisters.L;
            break;
        case 0x4E:
            mGPRegisters.C = mMemory.readByte(mGPRegisters.HL);
            break;

        case 0x57:
            mGPRegisters.D = mGPRegisters.A;
            break;
        case 0x50:
            mGPRegisters.D = mGPRegisters.B;
            break;
        case 0x51:
            mGPRegisters.D = mGPRegisters.C;
            break;
        case 0x52:
            mGPRegisters.D = mGPRegisters.D;
            break;
        case 0x53:
            mGPRegisters.D = mGPRegisters.E;
            break;
        case 0x54:
            mGPRegisters.D = mGPRegisters.H;
            break;
        case 0x55:
            mGPRegisters.D = mGPRegisters.L;
            break;
        case 0x56:
            mGPRegisters.D = mMemory.readByte(mGPRegisters.HL);
            break;

        case 0x5F:
            mGPRegisters.E = mGPRegisters.A;
            break;
        case 0x58:
            mGPRegisters.E = mGPRegisters.B;
            break;
        case 0x59:
            mGPRegisters.E = mGPRegisters.C;
            break;
        case 0x5A:
            mGPRegisters.E = mGPRegisters.D;
            break;
        case 0x5B:
            mGPRegisters.E = mGPRegisters.E;
            break;
        case 0x5C:
            mGPRegisters.E = mGPRegisters.H;
            break;
        case 0x5D:
            mGPRegisters.E = mGPRegisters.L;
            break;
        case 0x5E:
            mGPRegisters.E = mMemory.readByte(mGPRegisters.HL);
            break;

        case 0x67:
            mGPRegisters.H = mGPRegisters.A;
            break;
        case 0x60:
            mGPRegisters.H = mGPRegisters.B;
            break;
        case 0x61:
            mGPRegisters.H = mGPRegisters.C;
            break;
        case 0x62:
            mGPRegisters.H = mGPRegisters.D;
            break;
        case 0x63:
            mGPRegisters.H = mGPRegisters.E;
            break;
        case 0x64:
            mGPRegisters.H = mGPRegisters.H;
            break;
        case 0x65:
            mGPRegisters.H = mGPRegisters.L;
            break;
        case 0x66:
            mGPRegisters.H = mMemory.readByte(mGPRegisters.HL);
            break;

        case 0x6F:
            mGPRegisters.L = mGPRegisters.A;
            break;
        case 0x68:
            mGPRegisters.L = mGPRegisters.B;
            break;
        case 0x69:
            mGPRegisters.L = mGPRegisters.C;
            break;
        case 0x6A:
            mGPRegisters.L = mGPRegisters.D;
            break;
        case 0x6B:
            mGPRegisters.L = mGPRegisters.E;
            break;
        case 0x6C:
            mGPRegisters.L = mGPRegisters.H;
            break;
        case 0x6D:
            mGPRegisters.L = mGPRegisters.L;
            break;
        case 0x6E:
            mGPRegisters.L = mMemory.readByte(mGPRegisters.HL);
            break;

        case 0x01:
            mGPRegisters.BC = mMemory.readWordLS(++mMainRegisters.PC);
            ++mMainRegisters.PC;
            break;
        case 0x11:
            mGPRegisters.DE = mMemory.readWordLS(++mMainRegisters.PC);
            ++mMainRegisters.PC;
            break;
        case 0x21:
            mGPRegisters.HL = mMemory.readWordLS(++mMainRegisters.PC);
            ++mMainRegisters.PC;
            break;
        case 0x31:
            mMainRegisters.SP = mMemory.readWordLS(++mMainRegisters.PC);
            ++mMainRegisters.PC;
            break;

        case 0x77:
            mMemory.writeByte(mGPRegisters.HL, mGPRegisters.A);
            break;
        case 0x70:
            mMemory.writeByte(mGPRegisters.HL, mGPRegisters.B);
            break;
        case 0x71:
            mMemory.writeByte(mGPRegisters.HL, mGPRegisters.C);
            break;
        case 0x72:
            mMemory.writeByte(mGPRegisters.HL, mGPRegisters.D);
            break;
        case 0x73:
            mMemory.writeByte(mGPRegisters.HL, mGPRegisters.E);
            break;
        case 0x74:
            mMemory.writeByte(mGPRegisters.HL, mGPRegisters.H);
            break;
        case 0x75:
            mMemory.writeByte(mGPRegisters.HL, mGPRegisters.L);
            break;
        case 0x36:
            mMemory.writeByte(mGPRegisters.HL, mMemory.readByte(++mMainRegisters.PC));
            break;

        case 0x02:
            mMemory.writeByte(mGPRegisters.BC, mGPRegisters.A);
            break;
        case 0x12:
            mMemory.writeByte(mGPRegisters.DE, mGPRegisters.A);
            break;
        case 0xEA:
            mMemory.writeByte(mMemory.readWordLS(++mMainRegisters.PC), mGPRegisters.A);
            ++mMainRegisters.PC;
            break;

        case 0xF2:
            mGPRegisters.A = mMemory.readByte(0xFF00 + mGPRegisters.C);
            break;
        case 0xE2:
            mMemory.writeByte(0xFF00 + mGPRegisters.C, mGPRegisters.A);
            break;

        case 0xE0:
            mMemory.writeByte(0xFF00 + mMemory.readByte(++mMainRegisters.PC), mGPRegisters.A);
            break;
        case 0xF0:
            mGPRegisters.A = mMemory.readByte(0xFF00 + mMemory.readByte(++mMainRegisters.PC));
            break;

        case 0x3A:
            mGPRegisters.A = mMemory.readByte(mGPRegisters.HL--);
            break;
        case 0x32:
            mMemory.writeByte(mGPRegisters.HL--, mGPRegisters.A);
            break;

        case 0x2A:
            mGPRegisters.A = mMemory.readByte(mGPRegisters.HL++);
            break;
        case 0x22:
            mMemory.writeByte(mGPRegisters.HL++, mGPRegisters.A);
            break;

        case 0xF8:
            mGPRegisters.HL = mMainRegisters.SP + mMemory.readByte(++mMainRegisters.PC);
            break;
        case 0xF9:
            mMainRegisters.SP = mGPRegisters.HL;
            break;
        case 0x08:
            mMemory.writeWordLS(mMemory.readWordLS(++mMainRegisters.PC), mMainRegisters.SP);
            ++mMainRegisters.PC;

            /* Stack */
            /* Push */
        case 0xF5:
            mMemory.writeByte(--mMainRegisters.SP, mGPRegisters.A);
            mMemory.writeByte(--mMainRegisters.SP, mGPRegisters.F);
            break;
        case 0xC5:
            mMemory.writeByte(--mMainRegisters.SP, mGPRegisters.B);
            mMemory.writeByte(--mMainRegisters.SP, mGPRegisters.C);
            break;
        case 0xD5:
            mMemory.writeByte(--mMainRegisters.SP, mGPRegisters.D);
            mMemory.writeByte(--mMainRegisters.SP, mGPRegisters.E);
            break;
        case 0xE5:
            mMemory.writeByte(--mMainRegisters.SP, mGPRegisters.H);
            mMemory.writeByte(--mMainRegisters.SP, mGPRegisters.L);
            break;

            /* POP */
        case 0xF1:
            mGPRegisters.F = mMemory.readByte(mMainRegisters.SP++);
            mGPRegisters.A = mMemory.readByte(mMainRegisters.SP++);
            break;
        case 0xC1:
            mGPRegisters.C = mMemory.readByte(mMainRegisters.SP++);
            mGPRegisters.B = mMemory.readByte(mMainRegisters.SP++);
            break;
        case 0xD1:
            mGPRegisters.E = mMemory.readByte(mMainRegisters.SP++);
            mGPRegisters.D = mMemory.readByte(mMainRegisters.SP++);
            break;
        case 0xE1:
            mGPRegisters.L = mMemory.readByte(mMainRegisters.SP++);
            mGPRegisters.H = mMemory.readByte(mMainRegisters.SP++);
            break;

            /* ALU */
            /* ADD */
        case 0x87:
            break;

        default:
            throw "Unsupported OP code";
    }
}

