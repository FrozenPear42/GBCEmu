//
// Created by Wojciech on 10.08.2016.
//

#include "CPU.hpp"
#include <iostream>

CPU::CPU() {
    mMainRegisters.PC = 0;
    mMainRegisters.SP = 0;
    mGPRegisters.F = 0;
    mMainRegisters.IE = 1;
}

void CPU::tick() {
    uint8_t OPCode;
    OPCode = mMemory.readByte(mMainRegisters.PC);

    if(mHalt)
        return;

    std::cout << std::hex << "PC: " << mMainRegisters.PC << " OPCODE: " << (unsigned) OPCode << "\n";

    switch (OPCode) {
        /* NOP */
        case 0x00:
            break;

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
            mGPRegisters.A = mMemory.readByte((uint16_t) (0xFF00 + mGPRegisters.C));
            break;
        case 0xE2:
            mMemory.writeByte((uint16_t) (0xFF00 + mGPRegisters.C), mGPRegisters.A);
            break;

        case 0xE0:
            mMemory.writeByte((uint16_t) (0xFF00 + mMemory.readByte(++mMainRegisters.PC)), mGPRegisters.A);
            break;
        case 0xF0:
            mGPRegisters.A = mMemory.readByte((uint16_t) (0xFF00 + mMemory.readByte(++mMainRegisters.PC)));
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
            mGPRegisters.HL = (uint16_t) ((int) mMainRegisters.SP +
                                          (signed char) mMemory.readByte(++mMainRegisters.PC));
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
#define ADD_R(reg) (\
            {\
            uint8_t el_a = mGPRegisters.A;\
            uint8_t el_b = reg;\
            mGPRegisters.A = el_a + el_b;\
            uint8_t zero = (uint8_t) (mGPRegisters.A == 0 ? 1 : 0);\
            uint8_t carry = (uint8_t) ((((unsigned) el_a + (unsigned) el_b) > 255) ? 1 : 0);\
            uint8_t half = (uint8_t) (((mGPRegisters.A ^ el_a ^ el_b) & 0x10) >> 4);\
            mGPRegisters.F = FLAGS(zero, 0, carry, half);\
    })

        case 0x87:
            ADD_R(mGPRegisters.A);
            break;
        case 0x80:
            ADD_R(mGPRegisters.B);
            break;
        case 0x81:
            ADD_R(mGPRegisters.C);
            break;
        case 0x82:
            ADD_R(mGPRegisters.D);
            break;
        case 0x83:
            ADD_R(mGPRegisters.E);
            break;
        case 0x84:
            ADD_R(mGPRegisters.H);
            break;
        case 0x85:
            ADD_R(mGPRegisters.L);
            break;
        case 0x86:
            ADD_R(mMemory.readByte(mGPRegisters.HL));
            break;
        case 0xC6:
            ADD_R(mMemory.readByte(++mMainRegisters.PC));
            break;

            /* ADD with carry */
#define ADC_R(reg) ( \
            {\
            uint8_t el_a = mGPRegisters.A;\
            uint8_t el_b = reg;\
            mGPRegisters.A = el_a + el_b + F_CARRY(mGPRegisters.F);\
            uint8_t zero = (uint8_t) (mGPRegisters.A == 0 ? 1 : 0);\
            uint8_t carry = (uint8_t) ((((unsigned) el_a + (unsigned) el_b + F_CARRY(mGPRegisters.F)) > 255) ? 1 : 0);\
            uint8_t half = (uint8_t) (((mGPRegisters.A ^ el_a ^ el_b) & 0x10) >> 4);\
            mGPRegisters.F = FLAGS(zero, 0, carry, half);\
    })
        case 0x8F:
            ADC_R(mGPRegisters.A);
            break;
        case 0x88:
            ADC_R(mGPRegisters.B);
            break;
        case 0x89:
            ADC_R(mGPRegisters.C);
            break;
        case 0x8A:
            ADC_R(mGPRegisters.D);
            break;
        case 0x8B:
            ADC_R(mGPRegisters.E);
            break;
        case 0x8C:
            ADC_R(mGPRegisters.H);
            break;
        case 0x8D:
            ADC_R(mGPRegisters.L);
            break;
        case 0x8E:
            ADC_R(mMemory.readByte(mGPRegisters.HL));
            break;
        case 0xCE:
            ADC_R(mMemory.readByte(++mMainRegisters.PC));
            break;

#define SUB_R(reg) (\
            {\
            uint8_t el_a = mGPRegisters.A;\
            uint8_t el_b = reg;\
            uint8_t res = el_a - el_b;\
            uint8_t zero = (uint8_t) (res == 0 ? 1 : 0);\
            uint8_t carry = (uint8_t) (((int) el_a + (int) el_b < 0) ? 1 : 0);\
            uint8_t half = (uint8_t) (((res ^ el_a ^ el_b) & 0x10) >> 4);\
            mGPRegisters.A = res;\
            mGPRegisters.F = FLAGS(zero, 1, carry, half);\
    })
        case 0x97:
            SUB_R(mGPRegisters.A);
            break;
        case 0x90:
            SUB_R(mGPRegisters.B);
            break;
        case 0x91:
            SUB_R(mGPRegisters.C);
            break;
        case 0x92:
            SUB_R(mGPRegisters.D);
            break;
        case 0x93:
            SUB_R(mGPRegisters.E);
            break;
        case 0x94:
            SUB_R(mGPRegisters.H);
            break;
        case 0x95:
            SUB_R(mGPRegisters.L);
            break;
        case 0x96:
            SUB_R(mMemory.readByte(mGPRegisters.HL));
            break;
        case 0xD6:
            SUB_R(mMemory.readByte(++mMainRegisters.PC));
            break;

            /* CP */
#define CP_R(reg) (\
            {\
            uint8_t el_a = mGPRegisters.A;\
            uint8_t el_b = reg;\
            uint8_t res = el_a - el_b;\
            uint8_t zero = (uint8_t) (res == 0 ? 1 : 0);\
            uint8_t carry = (uint8_t) (((int) el_a + (int) el_b < 0) ? 1 : 0);\
            uint8_t half = (uint8_t) (((res ^ el_a ^ el_b) & 0x10) >> 4);\
            mGPRegisters.F = FLAGS(zero, 1, carry, half);\
    })
        case 0xBF:
            CP_R(mGPRegisters.A);
            break;
        case 0xB8:
            CP_R(mGPRegisters.B);
            break;
        case 0xB9:
            CP_R(mGPRegisters.C);
            break;
        case 0xBA:
            CP_R(mGPRegisters.D);
            break;
        case 0xBB:
            CP_R(mGPRegisters.E);
            break;
        case 0xBC:
            CP_R(mGPRegisters.H);
            break;
        case 0xBD:
            CP_R(mGPRegisters.L);
            break;
        case 0xBE:
            CP_R(mMemory.readByte(mGPRegisters.HL));
            break;
        case 0xFE:
            CP_R(mMemory.readByte(++mMainRegisters.PC));
            break;

            /* SBC */
#define SBC_R(reg) (\
            {\
            uint8_t el_a = mGPRegisters.A;\
            uint8_t el_b = reg + F_CARRY(mGPRegisters.F);\
            mGPRegisters.A = el_a - el_b;\
            uint8_t zero = (uint8_t) (mGPRegisters.A == 0 ? 1 : 0);\
            uint8_t carry = (uint8_t) (((int) el_a + (int) el_b < 0) ? 1 : 0);\
            uint8_t half = (uint8_t) (((mGPRegisters.A ^ el_a ^ el_b) & 0x10) >> 4);\
            mGPRegisters.F = FLAGS(zero, 1, carry, half);\
    })
        case 0x9F:
            SBC_R(mGPRegisters.A);
            break;
        case 0x98:
            SBC_R(mGPRegisters.B);
            break;
        case 0x99:
            SBC_R(mGPRegisters.C);
            break;
        case 0x9A:
            SBC_R(mGPRegisters.D);
            break;
        case 0x9B:
            SBC_R(mGPRegisters.E);
            break;
        case 0x9C:
            SBC_R(mGPRegisters.H);
            break;
        case 0x9D:
            SBC_R(mGPRegisters.L);
            break;
        case 0x9E:
            SBC_R(mMemory.readByte(mGPRegisters.HL));
            break;
        case 0xDE:
            SBC_R(mMemory.readByte(++mMainRegisters.PC));
            break;

            /* AND */
#define AND_R(reg) (\
            {\
            uint8_t el_a = mGPRegisters.A;\
            uint8_t el_b = reg;\
            mGPRegisters.A = el_a & el_b;\
            mGPRegisters.F = FLAGS((mGPRegisters.A == 0 ? 1 : 0), 0, 1, 0);\
    })
        case 0xA7:
            AND_R(mGPRegisters.A);
            break;
        case 0xA0:
            AND_R(mGPRegisters.B);
            break;
        case 0xA1:
            AND_R(mGPRegisters.C);
            break;
        case 0xA2:
            AND_R(mGPRegisters.D);
            break;
        case 0xA3:
            AND_R(mGPRegisters.E);
            break;
        case 0xA4:
            AND_R(mGPRegisters.H);
            break;
        case 0xA5:
            AND_R(mGPRegisters.L);
            break;
        case 0xA6:
            AND_R(mMemory.readByte(mGPRegisters.HL));
            break;
        case 0xE6:
            AND_R(mMemory.readByte(++mMainRegisters.PC));
            break;
            /* OR */
#define OR_R(reg) (\
            {\
            uint8_t el_a = mGPRegisters.A;\
            uint8_t el_b = reg;\
            mGPRegisters.A = el_a | el_b;\
            mGPRegisters.F = FLAGS((mGPRegisters.A == 0 ? 1 : 0), 0, 1, 0);\
            })
        case 0xB7:
            OR_R(mGPRegisters.A);
            break;
        case 0xB0:
            OR_R(mGPRegisters.B);
            break;
        case 0xB1:
            OR_R(mGPRegisters.C);
            break;
        case 0xB2:
            OR_R(mGPRegisters.D);
            break;
        case 0xB3:
            OR_R(mGPRegisters.E);
            break;
        case 0xB4:
            OR_R(mGPRegisters.H);
            break;
        case 0xB5:
            OR_R(mGPRegisters.L);
            break;
        case 0xB6:
            OR_R(mMemory.readByte(mGPRegisters.HL));
            break;
        case 0xF6:
            OR_R(mMemory.readByte(++mMainRegisters.PC));
            break;
            /* XOR */
#define XOR_R(reg) (\
            {\
            uint8_t el_a = mGPRegisters.A;\
            uint8_t el_b = reg;\
            mGPRegisters.A = el_a ^ el_b;\
            mGPRegisters.F = FLAGS((mGPRegisters.A == 0 ? 1 : 0), 0, 1, 0);\
    })
        case 0xAF:
            XOR_R(mGPRegisters.A);
            break;
        case 0xA8:
            XOR_R(mGPRegisters.B);
            break;
        case 0xA9:
            XOR_R(mGPRegisters.C);
            break;
        case 0xAA:
            XOR_R(mGPRegisters.D);
            break;
        case 0xAB:
            XOR_R(mGPRegisters.E);
            break;
        case 0xAC:
            XOR_R(mGPRegisters.H);
            break;
        case 0xAD:
            XOR_R(mGPRegisters.L);
            break;
        case 0xAE:
            XOR_R(mMemory.readByte(mGPRegisters.HL));
            break;
        case 0xEE:
            XOR_R(mMemory.readByte(++mMainRegisters.PC));
            break;

            /* INC */
#define INC_R(reg) ( \
            { \
            uint8_t el_a = reg; \
            uint8_t el_b = 1; \
            reg = el_a + el_b; \
            uint8_t zero = (uint8_t) (reg == 0 ? 1 : 0); \
            uint8_t half = (uint8_t) (((reg ^ el_a ^ el_b) & 0x10) >> 4); \
            mGPRegisters.F = FLAGS(zero, 0, F_CARRY(mGPRegisters.F), half); \
    })
        case 0x3C:
            INC_R(mGPRegisters.A);
            break;
        case 0x04:
            INC_R(mGPRegisters.B);
            break;
        case 0x0C:
            INC_R(mGPRegisters.C);
            break;
        case 0x14:
            INC_R(mGPRegisters.D);
            break;
        case 0x1C:
            INC_R(mGPRegisters.E);
            break;
        case 0x24:
            INC_R(mGPRegisters.H);
            break;
        case 0x2C:
            INC_R(mGPRegisters.L);
            break;
        case 0x34: {
            uint8_t el_a = mMemory.readByte(mGPRegisters.HL);
            uint8_t el_b = 1;
            uint8_t reg = el_a + el_b;
            mMemory.writeByte(mGPRegisters.HL, reg);
            uint8_t zero = (uint8_t) (reg == 0 ? 1 : 0);
            uint8_t half = (uint8_t) (((reg ^ el_a ^ el_b) & 0x10) >> 4);
            mGPRegisters.F = FLAGS(zero, 0, F_CARRY(mGPRegisters.F), half);
        }
            break;

            /* DEC */
#define DEC_R(reg) ( \
            { \
            uint8_t el_a = reg; \
            uint8_t el_b = 1; \
            reg = el_a - el_b; \
            uint8_t zero = (uint8_t) (reg == 0 ? 1 : 0); \
            uint8_t half = (uint8_t) (((reg ^ el_a ^ el_b) & 0x10) >> 4); \
            mGPRegisters.F = FLAGS(zero, 1, F_CARRY(mGPRegisters.F), half); \
    })
        case 0x3D:
            DEC_R(mGPRegisters.A);
            break;
        case 0x05:
            DEC_R(mGPRegisters.B);
            break;
        case 0x0D:
            DEC_R(mGPRegisters.C);
            break;
        case 0x15:
            DEC_R(mGPRegisters.D);
            break;
        case 0x1D:
            DEC_R(mGPRegisters.E);
            break;
        case 0x25:
            DEC_R(mGPRegisters.H);
            break;
        case 0x2D:
            DEC_R(mGPRegisters.L);
            break;
        case 0x35: {
            uint8_t el_a = mMemory.readByte(mGPRegisters.HL);
            uint8_t el_b = 1;
            uint8_t reg = el_a - el_b;
            mMemory.writeByte(mGPRegisters.HL, reg);
            uint8_t zero = (uint8_t) (reg == 0 ? 1 : 0);
            uint8_t half = (uint8_t) (((reg ^ el_a ^ el_b) & 0x10) >> 4);
            mGPRegisters.F = FLAGS(zero, 1, F_CARRY(mGPRegisters.F), half);
        }
            break;

            /* 16-bit ALU */
            /* ADD */
#define ADD_16_R(reg) ( \
            {\
            uint16_t el_a = mGPRegisters.HL;\
            uint16_t el_b = reg;\
            mGPRegisters.HL = el_a + el_b;\
            uint8_t zero = (uint8_t) (mGPRegisters.A == 0 ? 1 : 0); \
            uint8_t carry = (uint8_t) ((((uint32_t) el_a + (uint32_t) el_b) > 65535) ? 1 : 0);\
            uint8_t half = (uint8_t) (((mGPRegisters.HL ^ el_a ^ el_b) & 0x0400) >> 10);\
            mGPRegisters.F = FLAGS(zero, 0, carry, half);\
            })
        case 0x09:
            ADD_16_R(mGPRegisters.BC);
            break;
        case 0x19:
            ADD_16_R(mGPRegisters.DE);
            break;
        case 0x29:
            ADD_16_R(mGPRegisters.HL);
            break;
        case 0x39:
            ADD_16_R(mMainRegisters.SP);
            break;
            /* ADD SP, n */
            //FIXME: not sure if ok
        case 0xE8: {

            int el_a = mMainRegisters.SP;
            int n = (int) (mMemory.readByte(++mMainRegisters.PC));
            mMainRegisters.SP = (uint16_t) ((int) mMainRegisters.SP + n);
            uint8_t carry = (uint8_t) (((el_a + n) > 65535 || (el_a + n) < 0) ? 1 : 0);
            uint8_t half = (uint8_t) (((mMainRegisters.SP ^ el_a ^ n) & 0x0400) >> 10);
            mGPRegisters.F = FLAGS(0, 0, carry, half);
        }
            break;

#define INC_16_R(reg) { reg++; }

        case 0x03: INC_16_R(mGPRegisters.BC);
            break;
        case 0x13: INC_16_R(mGPRegisters.DE);
            break;
        case 0x23: INC_16_R(mGPRegisters.HL);
            break;
        case 0x33: INC_16_R(mMainRegisters.SP);
            break;

#define DEC_16_R(reg) ({ reg--; })

        case 0x0B:
            DEC_16_R(mGPRegisters.BC);
            break;
        case 0x1B:
            DEC_16_R(mGPRegisters.DE);
            break;
        case 0x2B:
            DEC_16_R(mGPRegisters.HL);
            break;
        case 0x3B:
            DEC_16_R(mMainRegisters.SP);
            break;

            /* DDA */
        case 0x27: {
            uint8_t reg = mGPRegisters.A;
            if (F_HALF(mGPRegisters.F) || (reg & 0x0F) > 9)
                mGPRegisters.A += 6;

            mGPRegisters.F &= 0xEF; //reset carry flag

            if (F_HALF(mGPRegisters.F) || reg > 0x99) {
                mGPRegisters.A += 0x60;
                mGPRegisters.F |= 0x10; //set carry flag
            }
            mGPRegisters.F = FLAGS((mGPRegisters.A == 0 ? 1 : 0), F_SUB(mGPRegisters.F), 0,
                                        F_CARRY(mGPRegisters.F));
        }
            break;
        case 0x2F:
            mGPRegisters.A = ~mGPRegisters.A;
            break;
        case 0x3F:
            if (F_CARRY(mGPRegisters.F))
                mGPRegisters.F &= 0xEF;
            else
                mGPRegisters.F |= 0x10;
            break;

        case 0x37:
            mGPRegisters.F |= 0x10;
            break;

        case 0x76:
            mHalt = 1;
            break;

        case 0x10:
            if (mMemory.readByte(++mMainRegisters.PC) == 0x00) {
                mHalt = 1;
                //TODO: STOP
            }
            break;

        case 0xF3:
            mMainRegisters.IE = 0;
            break;

        case 0xFB:
            mMainRegisters.IE = 1;
            break;


#define JMP_R(cond) ({\
            if (cond) {\
                mMainRegisters.PC = mMemory.readWordLS(++mMainRegisters.PC);\
                mJump = 1;\
            }else{\
                ++mMainRegisters.PC;\
                ++mMainRegisters.PC;\
            }       \
    })
            /* JMP */
        case 0xC3:
            JMP_R(true);
            break;
        case 0xC2:
            JMP_R(!F_ZERO(mGPRegisters.F));
            break;
        case 0xCA:
            JMP_R(F_ZERO(mGPRegisters.F));
            break;
        case 0xD2:
            JMP_R(!F_CARRY(mGPRegisters.F));
            break;
        case 0xDA:
            JMP_R(F_CARRY(mGPRegisters.F));
            break;
        case 0xE9:
            mMainRegisters.PC = mGPRegisters.HL;
            mJump = 1;
            break;

            /* JR */
#define JR_R(cond)({\
            if(cond){\
                int8_t offset = (int8_t) mMemory.readByte(++mMainRegisters.PC);\
                mMainRegisters.PC = (uint16_t) ((int16_t) mMainRegisters.PC + offset);\
                mMainRegisters.PC++;\
                mJump = 1;\
            } else {\
                ++mMainRegisters.PC;\
            }\
            })

        case 0x18: {
            JR_R(true);
        }
            break;
        case 0x20:
            JR_R(!F_ZERO(mGPRegisters.F));
            break;
        case 0x28:
            JR_R(F_ZERO(mGPRegisters.F));
            break;
        case 0x30:
            JR_R(!F_CARRY(mGPRegisters.F));
            break;
        case 0x38:
            JR_R(F_CARRY(mGPRegisters.F));
            break;

#define CALL_R(cond) ({\
            uint16_t next = (uint16_t) (mMainRegisters.PC + 3);\
            mMemory.writeByte(--mMainRegisters.SP, (uint8_t) ((next & 0xFF00) >> 8));\
            mMemory.writeByte(--mMainRegisters.SP, (uint8_t) (next & 0x00FF));\
            mMainRegisters.PC = mMemory.readWordLS(++mMainRegisters.PC);\
            mJump = 1;\
            })

            /* CALL */
        case 0xCD:
            CALL_R(true);
            break;

        case 0xC4:
            CALL_R(!F_ZERO(mGPRegisters.F));
            break;

        case 0xCC:
            CALL_R(F_ZERO(mGPRegisters.F));
            break;

        case 0xD4:
            CALL_R(!F_CARRY(mGPRegisters.F));
            break;

        case 0xDC:
            CALL_R(F_CARRY(mGPRegisters.F));
            break;

#define RET_R(cond) ({\
            if(cond) {\
                uint16_t next;\
            next = mMemory.readByte(mMainRegisters.SP++);\
            next |= mMemory.readByte(mMainRegisters.SP++) << 8;\
            mMainRegisters.PC = next;\
            mJump = 1;\
            }\
    })

            /* RET */
        case 0xC9:
            RET_R(true);
            break;
            /* RETI */
        case 0xD9:
            RET_R(true);
            mMainRegisters.IE = 1;
            break;

        case 0xC0:
            RET_R(!F_ZERO(mGPRegisters.F));
            break;
        case 0xC8:
            RET_R(F_ZERO(mGPRegisters.F));
            break;
        case 0xD0:
            RET_R(!F_CARRY(mGPRegisters.F));
            break;
        case 0xD8:
            RET_R(F_CARRY(mGPRegisters.F));
            break;

            /* RST */
#define RST(addr) ({\
            mMemory.writeByte(--mMainRegisters.SP, (uint8_t) (mMainRegisters.PC & 0xFF00 >> 8));\
            mMemory.writeByte(--mMainRegisters.SP, (uint8_t) (mMainRegisters.PC & 0x00FF));\
            mMainRegisters.PC = addr;\
            mJump = 1;\
    })
        case 0xC7:
            RST(0x0000);
            break;
        case 0xCF:
            RST(0x0008);
            break;
        case 0xD7:
            RST(0x0010);
            break;
        case 0xDF:
            RST(0x0018);
            break;
        case 0xE7:
            RST(0x0020);
            break;
        case 0xEF:
            RST(0x0028);
            break;
        case 0xF7:
            RST(0x0030);
            break;
        case 0xFF:
            RST(0x0038);
            break;

#define RLC_R(reg) ({\
            uint8_t c = (uint8_t) (((reg) & 0x80) >> 7);\
            (reg) <<= 1;\
            (reg) |= c;\
            mGPRegisters.F = FLAGS((reg) == 0 ? 1 : 0, 0, 0, c);\
    })

#define RL_R(reg) ({\
            uint8_t c = (uint8_t) (((reg) & 0x80) >> 7);\
            (reg) <<= 1;\
            (reg) |= F_CARRY(mGPRegisters.F);\
            mGPRegisters.F = FLAGS((reg) == 0 ? 1 : 0, 0, 0, c);\
    })

#define RRC_R(reg) ({\
            uint8_t c = (uint8_t) ((reg) & 0x01);\
            (reg) >>= 1;\
            (reg) |= (c << 7);\
            mGPRegisters.F = FLAGS((reg) == 0 ? 1 : 0, 0, 0, c);\
    })

#define RR_R(reg) ({\
            uint8_t c = (uint8_t) ((reg) & 0x01);\
            (reg) >>= 1;\
            (reg) |= F_CARRY(mGPRegisters.F);\
            mGPRegisters.F = FLAGS((reg) == 0 ? 1 : 0, 0, 0, c);\
    })

#define SLA_R(reg) ({\
            uint8_t c = (uint8_t) (((reg) & 0x80) >> 7);\
            (reg) <<= 1;\
            mGPRegisters.F = FLAGS((reg) == 0 ? 1 : 0, 0, 0, c);\
    })

#define SRA_R(reg) ({\
            uint8_t c = (uint8_t) ((reg) & 0x01);\
            (reg) >>= 1;\
            (reg) |= 0x80;\
            mGPRegisters.F = FLAGS((reg) == 0 ? 1 : 0, 0, 0, c);\
    })

#define SRL_R(reg) ({\
            uint8_t c = (uint8_t) ((reg) & 0x01);\
            (reg) >>= 1;\
            mGPRegisters.F = FLAGS((reg) == 0 ? 1 : 0, 0, 0, c);\
    })

#define BIT_R(reg, id) ({\
            uint8_t zero = (reg >> id) & 0x01;\
            mGPRegisters.F = FLAGS(zero == 0 ? 1 : 0, 0, 1, F_CARRY(mGPRegisters.F));  \
    })

#define SET_R(reg, id) ({\
            reg |= (0x01 << id);\
    })

#define RES_R(reg, id) ({\
        reg &= ~(0x01 << id);\
    })

            /* ROTATIONS */
        case 0x07:
            RLC_R(mGPRegisters.A);
            break;

        case 0x17:
            RL_R(mGPRegisters.A);
            break;

        case 0x0F:
            RRC_R(mGPRegisters.A);
            break;

        case 0x1F:
            RR_R(mGPRegisters.A);
            break;


        case 0xCB: {
            uint8_t bitOP = mMemory.readByte(++mMainRegisters.PC);
            uint8_t hl = mMemory.readByte(mGPRegisters.HL);
            uint8_t *target;

            switch (bitOP & 0x0F) {
                case 0x07:
                case 0x0F:
                    target = &mGPRegisters.A;
                    break;
                case 0x00:
                case 0x08:
                    target = &mGPRegisters.B;
                    break;
                case 0x01:
                case 0x09:
                    target = &mGPRegisters.C;
                    break;
                case 0x02:
                case 0x0A:
                    target = &mGPRegisters.D;
                    break;
                case 0x03:
                case 0x0B:
                    target = &mGPRegisters.E;
                    break;
                case 0x04:
                case 0x0C:
                    target = &mGPRegisters.H;
                    break;
                case 0x05:
                case 0x0D:
                    target = &mGPRegisters.L;
                    break;
                case 0x06:
                case 0x0E:
                    target = &hl;
                    break;
                default:
                    throw "Unsuppeorted bit code";
            }

            switch (OPCode & 0xF8) {
                case 0x00:
                    RLC_R(*target);
                    break;
                case 0x08:
                    RRC_R(*target);
                    break;
                case 0x10:
                    RL_R(*target);
                    break;
                case 0x18:
                    RR_R(*target);
                    break;
                case 0x20:
                    SLA_R(*target);
                    break;
                case 0x28:
                    SRA_R(*target);
                    break;
                case 0x30:
                    //SWAP
                    *target = (uint8_t) (((*target & 0x0F) << 4) | ((*target & 0xF0) >> 4));
                    mGPRegisters.F = FLAGS((*target == 0 ? 1 : 0), 0, 0, 0);
                    break;
                case 0x38:
                    SRL_R(*target);
                    break;
                case 0x40:
                    BIT_R(*target, 0);
                    break;
                case 0x48:
                    BIT_R(*target, 1);
                    break;
                case 0x50:
                    BIT_R(*target, 2);
                    break;
                case 0x58:
                    BIT_R(*target, 3);
                    break;
                case 0x60:
                    BIT_R(*target, 4);
                    break;
                case 0x68:
                    BIT_R(*target, 5);
                    break;
                case 0x70:
                    BIT_R(*target, 6);
                    break;
                case 0x78:
                    BIT_R(*target, 7);
                    break;
                case 0x80:
                    RES_R(*target, 0);
                    break;
                case 0x88:
                    RES_R(*target, 1);
                    break;
                case 0x90:
                    RES_R(*target, 2);
                    break;
                case 0x98:
                    RES_R(*target, 3);
                    break;
                case 0xA0:
                    RES_R(*target, 4);
                    break;
                case 0xA8:
                    RES_R(*target, 5);
                    break;
                case 0xB0:
                    RES_R(*target, 6);
                    break;
                case 0xB8:
                    RES_R(*target, 7);
                    break;
                case 0xC0:
                    SET_R(*target, 0);
                    break;
                case 0xC8:
                    SET_R(*target, 1);
                    break;
                case 0xD0:
                    SET_R(*target, 2);
                    break;
                case 0xD8:
                    SET_R(*target, 3);
                    break;
                case 0xE0:
                    SET_R(*target, 4);
                    break;
                case 0xE8:
                    SET_R(*target, 5);
                    break;
                case 0xF0:
                    SET_R(*target, 6);
                    break;
                case 0xF8:
                    SET_R(*target, 7);
                    break;
                default:
                    throw "Could not happen";

            }
            mMemory.writeByte(mGPRegisters.HL, hl);
        }
            break;

        default:
            throw "Unsupported OP code";
    }
    if (!mJump) mMainRegisters.PC++;
    mJump = 0;
}

void CPU::log() {
    std::cout << "PC: " << mMainRegisters.PC << "\t SP: " << mMainRegisters.SP << "\t FLAG: " <<
    (unsigned) mGPRegisters.F << std::hex << "\n";
    std::cout << "A:  " << (unsigned) mGPRegisters.A << "\t F: " << (unsigned) mGPRegisters.F << "\t AF: " <<
    mGPRegisters.AF << "\n";
    std::cout << "B:  " << (unsigned) mGPRegisters.B << "\t C: " << (unsigned) mGPRegisters.C << "\t BC: " <<
    mGPRegisters.BC << "\n";
    std::cout << "D:  " << (unsigned) mGPRegisters.D << "\t E: " << (unsigned) mGPRegisters.E << "\t DE: " <<
    mGPRegisters.DE << "\n";
    std::cout << "H:  " << (unsigned) mGPRegisters.H << "\t L: " << (unsigned) mGPRegisters.L << "\t HL: " <<
    mGPRegisters.HL << "\n";


}


