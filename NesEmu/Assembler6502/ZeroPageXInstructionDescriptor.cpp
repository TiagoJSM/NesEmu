#include "ZeroPageXInstructionDescriptor.h"

namespace Assembler6502 {
	ZeroPageXInstructionDescriptor::ZeroPageXInstructionDescriptor(const string& instruction, const uint8_t operand)
		:BaseZeroPageInstructionDescriptor(instruction, operand) {

	}
}