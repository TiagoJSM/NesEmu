#include "ZeroPageYInstructionDescriptor.h"

namespace Assembler6502 {
	ZeroPageYInstructionDescriptor::ZeroPageYInstructionDescriptor(const string& instruction, const uint8_t operand)
		:_instruction(instruction), _operand(operand) {

	}
}