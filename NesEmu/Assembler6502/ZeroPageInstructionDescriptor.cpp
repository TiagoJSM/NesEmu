#include "ZeroPageInstructionDescriptor.h"

namespace Assembler6502 {
	ZeroPageInstructionDescriptor::ZeroPageInstructionDescriptor(const string& instruction, const uint8_t operand)
		:BaseZeroPageInstructionDescriptor(instruction, operand) {

	}
}