#pragma once

#include <stdint.h>
#include "StatusFlags.h"

namespace NesEmu {
	// http://wiki.nesdev.com/w/index.php/CPU_status_flag_behavior
	class Registers {
	public:
		uint8_t A, X, Y, S, P;
		uint16_t PC;

		Registers();

		bool Carry();
		bool Zero();
		bool InterruptInhibit();
		bool Decimal();
		bool Overflow();
		bool Negative();

		void SetNegative(int8_t data);
		void SetZero(int8_t data);

	private:
		inline void SetBits(bool condition, uint8_t bitMask);
	};

}
