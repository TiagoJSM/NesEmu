#pragma once

#include <stdint.h>
#include "StatusFlags.h"
#include "Macros.h"

namespace NesEmu {
	// http://wiki.nesdev.com/w/index.php/CPU_status_flag_behavior
    // http://nesdev.com/6502.txt
    //Flags:
    // 7   6   5   4   3   2   1   0
    // S   V       B   D   I   Z   C
    // C - Carry flag
    // Z - Zero flag
    // I - this is an interrupt enable/disable flag
    // D - this is the decimal mode status flag
    // B - this is set when a software interrupt (BRK instruction) is executed
    // V - Overflow flag
    // S - Sign flag
	class Registers {
	public:
		uint8_t A, X, Y, S, P; //s = stack pointer, P = processor status
		uint16_t PC;

		Registers();
		Registers(uint8_t A, uint8_t X, uint8_t Y, uint8_t SP, uint8_t P, uint16_t PC);

		bool Carry();
		bool Zero();
		bool InterruptInhibit();
		bool Decimal();
		bool Overflow();
		bool Negative();

		void SetNegative(int8_t data);
		void SetNegative(bool set);
		void SetZero(int8_t data);
		void SetZero(bool set);
		void SetCarry(int16_t data);
        void SetCarry(bool set);
		void SetOverflow(bool set);
		void SetInterrupt(bool set);
		void SetDecimal(bool set);

		bool operator==(const Registers& other) {
			return 
				A == other.A &&
				X == other.X &&
				Y == other.Y &&
				S == other.S &&
				P == other.P &&
				PC == other.PC;
		}

	private:
		inline void SetBits(bool condition, uint8_t bitMask);
	};

}
