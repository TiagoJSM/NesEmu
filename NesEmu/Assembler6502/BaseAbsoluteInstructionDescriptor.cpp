#include "BaseAbsoluteInstructionDescriptor.h"

namespace Assembler6502 {
	BaseAbsoluteInstructionDescriptor::BaseAbsoluteInstructionDescriptor(const string& instruction, const uint16_t operand)
		:_instruction(instruction), _operand(operand) {

	}

	string BaseAbsoluteInstructionDescriptor::GetInstruction() {
		return _instruction;
	}

	uint16_t BaseAbsoluteInstructionDescriptor::GetOperand() {
		return _operand;
	}
}