#include "BaseWordOperandInstructionDescriptor.h"

namespace Assembler6502 {
	BaseWordOperandInstructionDescriptor::BaseWordOperandInstructionDescriptor(
		const string& instruction, const AddressingMode addressMode, const InstructionToken operand)
		:TemplatedOperandInstructionDescriptor(instruction, addressMode, operand) {

	}

	uint8_t BaseWordOperandInstructionDescriptor::GetInstructionSize() {
		return 3;
	}

	uint8_t BaseWordOperandInstructionDescriptor::GetOperandLowByte(const Labels& labels) {
		return GetOperand(labels) & 0xFF;
	}
	uint8_t BaseWordOperandInstructionDescriptor::GetOperandHighByte(const Labels& labels) {
		return (GetOperand(labels) >> 8) & 0xFF;
	}
}