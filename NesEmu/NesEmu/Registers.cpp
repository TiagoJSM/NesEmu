#include "Registers.h"

namespace NesEmu {

	Registers::Registers() : A(0), X(0), Y(0), S(0), P(0), PC(0) { }

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

	void Registers::SetNegative(int8_t data) {
		this->SetBits(data < 0, NEGATIVE_MASK);
	}

	void Registers::SetZero(int8_t data) {
		this->SetBits(data == 0, ZERO_MASK);
	}

	void Registers::SetCarry(int16_t data) {
		this->SetBits(data > MAX_BYTE, CARRY_MASK);
	}

    void Registers::SetCarry(bool set) {
        this->SetBits(set, CARRY_MASK);
    }

	void Registers::SetOverflow(bool set) {
		this->SetBits(set, OVERFLOW_MASK);
	}

	void Registers::SetBits(bool condition, uint8_t bitMask) {
		this->P = condition ? (this->P | bitMask) : (this->P & !bitMask);
	}
}