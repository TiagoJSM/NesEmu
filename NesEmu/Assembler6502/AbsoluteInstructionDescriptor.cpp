#include "AbsoluteInstructionDescriptor.h"

namespace Assembler6502 {
	AbsoluteInstructionDescriptor::AbsoluteInstructionDescriptor(const string& instruction, const uint16_t operand)
		:BaseAbsoluteInstructionDescriptor(instruction, operand) {

	}
}