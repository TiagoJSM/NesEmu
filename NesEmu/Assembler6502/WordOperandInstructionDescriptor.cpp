#include "WordOperandInstructionDescriptor.h"

namespace Assembler6502 {
	WordOperandInstructionDescriptor::WordOperandInstructionDescriptor(const string& instruction, const uint16_t operand)
		:BaseWordOperandInstructionDescriptor(instruction, operand) {

	}
}