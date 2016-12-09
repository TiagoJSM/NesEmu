#include "WordOperandYInstructionDescriptor.h"

namespace Assembler6502 {
	WordOperandYInstructionDescriptor::WordOperandYInstructionDescriptor(const string& instruction, const uint16_t operand)
		:BaseWordOperandInstructionDescriptor(instruction, operand) {

	}
}