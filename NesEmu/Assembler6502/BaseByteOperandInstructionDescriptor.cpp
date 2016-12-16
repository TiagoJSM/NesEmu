#include "BaseByteOperandInstructionDescriptor.h"

namespace Assembler6502 {
	BaseByteOperandInstructionDescriptor::BaseByteOperandInstructionDescriptor(
		const string& instruction, const AddressingMode addressMode, const InstructionToken operand)
		:TemplatedOperandInstructionDescriptor(instruction, addressMode, operand) {

	}

	uint8_t BaseByteOperandInstructionDescriptor::GetInstructionSize() {
		return 2;
	}
}