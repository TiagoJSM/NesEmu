#include "ParameterlessInstructionDescriptor.h"

namespace Assembler6502 {
	ParameterlessInstructionDescriptor::ParameterlessInstructionDescriptor(const string& instruction) :_instruction(instruction) {

	}

	uint8_t ParameterlessInstructionDescriptor::GetInstructionSize() {
		return 1;
	}
}