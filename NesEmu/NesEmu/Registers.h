#pragma once

#include "StatusFlags.h"

namespace NesEmu {
	// http://wiki.nesdev.com/w/index.php/CPU_status_flag_behavior
	struct Registers {
		unsigned char A, X, Y, S, P;
		unsigned short PC;

		inline bool Carry();
		inline bool Zero();
		inline bool InterruptInhibit();
		inline bool Decimal();
		inline bool Overflow();
		inline bool Negative();
	};

}
