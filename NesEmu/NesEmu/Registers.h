#pragma once

#include "StatusFlags.h"

namespace NesEmu {
	// http://wiki.nesdev.com/w/index.php/CPU_status_flag_behavior
	class Registers {
	public:
		unsigned char A, X, Y, S, P;
		unsigned short PC;

		Registers();

		bool Carry();
		bool Zero();
		bool InterruptInhibit();
		bool Decimal();
		bool Overflow();
		bool Negative();

		void SetNegative(char data);
		void SetZero(char data);

	private:
		inline void SetBits(bool condition, char bitMask);
	};

}
