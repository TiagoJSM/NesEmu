#include "BaseByteOperandInstructionDescriptor.h"

namespace Assembler6502 {
	BaseByteOperandInstructionDescriptor::BaseByteOperandInstructionDescriptor(const string& instruction, const InstructionToken operand)
		:TemplatedOperandInstructionDescriptor(instruction, operand) {

	}

	uint8_t BaseByteOperandInstructionDescriptor::GetInstructionSize() {
		return 2;
	}
}