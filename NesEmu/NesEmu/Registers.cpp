#include "Registers.h"

namespace NesEmu {
	bool Registers::Carry() {
		return (this->P & CARRY_MASK);
	}

	bool Registers::Zero() {
		return (this->P & ZERO_MASK);
	}

	bool Registers::InterruptInhibit() {
		return (this->P & INTERRUPT_INHIBIT_MASK);
	}

	bool Registers::Decimal() {
		return (this->P & DECIMAL_MASK);
	}

	bool Registers::Overflow() {
		return (this->P & OVERFLOW_MASK);
	}

	bool Registers::Negative() {
		return (this->P & NEGATIVE_MASK);
	}
}