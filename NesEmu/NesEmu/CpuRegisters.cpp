#include "CpuRegisters.h"

namespace NesEmu {

	CpuRegisters::CpuRegisters() : A(0), X(0), Y(0), S(0), P(0), PC(0) { }
	CpuRegisters::CpuRegisters(uint8_t A, uint8_t X, uint8_t Y, uint8_t S, uint8_t P, uint16_t PC)
		: A(A), X(X), Y(Y), S(S), P(P), PC(PC) {}

	bool CpuRegisters::Carry() {
		return (this->P & CARRY_MASK);
	}

	bool CpuRegisters::Zero() {
		return (this->P & ZERO_MASK);
	}

	bool CpuRegisters::InterruptInhibit() {
		return (this->P & INTERRUPT_INHIBIT_MASK);
	}

	bool CpuRegisters::Decimal() {
		return (this->P & DECIMAL_MASK);
	}

	bool CpuRegisters::Overflow() {
		return (this->P & OVERFLOW_MASK);
	}

	bool CpuRegisters::Negative() {
		return (this->P & NEGATIVE_MASK);
	}

	void CpuRegisters::SetNegative(int8_t data) {
		this->SetBits(data < 0, NEGATIVE_MASK);
	}

	void CpuRegisters::SetNegative(bool set) {
		this->SetBits(set, NEGATIVE_MASK);
	}

	void CpuRegisters::SetZero(int8_t data) {
		this->SetBits(data == 0, ZERO_MASK);
	}

	void CpuRegisters::SetZero(bool set) {
		this->SetBits(set, ZERO_MASK);
	}

	void CpuRegisters::SetCarry(int16_t data) {
		this->SetBits(data > MAX_BYTE, CARRY_MASK);
	}

    void CpuRegisters::SetCarry(bool set) {
        this->SetBits(set, CARRY_MASK);
    }

	void CpuRegisters::SetOverflow(bool set) {
		this->SetBits(set, OVERFLOW_MASK);
	}

	void CpuRegisters::SetInterrupt(bool set) {
		this->SetBits(set, INTERRUPT_INHIBIT_MASK);
	}

	void CpuRegisters::SetDecimal(bool set) {
		this->SetBits(set, DECIMAL_MASK);
	}

	void CpuRegisters::SetBits(bool condition, uint8_t bitMask) {
		this->P = condition ? (this->P | bitMask) : (this->P & ~bitMask);
	}
}