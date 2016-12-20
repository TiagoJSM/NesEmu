#include "BaseWordOperandInstructionDescriptor.h"

namespace Assembler6502 {
	BaseWordOperandInstructionDescriptor::BaseWordOperandInstructionDescriptor(
		const string& instruction, const AddressingMode addressMode, const InstructionToken operand)
		:TemplatedOperandInstructionDescriptor(instruction, addressMode, operand) {

	}

	uint8_t BaseWordOperandInstructionDescriptor::GetInstructionSize() {
		return 3;
	}

	uint8_t BaseWordOperandInstructionDescriptor::GetOperandLowByte() {
		return GetOperand() & 0xFF;
	}
	uint8_t BaseWordOperandInstructionDescriptor::GetOperandHighByte() {
		return (GetOperand() >> 8) & 0xFF;
	}
}