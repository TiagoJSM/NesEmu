#include "BaseZeroPageInstructionDescriptor.h"

namespace Assembler6502 {
	BaseZeroPageInstructionDescriptor::BaseZeroPageInstructionDescriptor(const string& instruction, const uint8_t operand)
		:_instruction(instruction), _operand(operand) {

	}

	string BaseZeroPageInstructionDescriptor::GetInstruction() {
		return _instruction;
	}

	uint8_t BaseZeroPageInstructionDescriptor::GetOperand() {
		return _operand;
	}
}