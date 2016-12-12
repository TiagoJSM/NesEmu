#include "BaseWordOperandInstructionDescriptor.h"

namespace Assembler6502 {
	BaseWordOperandInstructionDescriptor::BaseWordOperandInstructionDescriptor(const string& instruction, const InstructionToken operand)
		:TemplatedOperandInstructionDescriptor(instruction, operand) {

	}

	uint8_t BaseWordOperandInstructionDescriptor::GetInstructionSize() {
		return 3;
	}
}