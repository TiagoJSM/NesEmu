#include "WordOperandXInstructionDescriptor.h"

namespace Assembler6502 {
	WordOperandXInstructionDescriptor::WordOperandXInstructionDescriptor(const string& instruction, const uint16_t operand)
		:BaseWordOperandInstructionDescriptor(instruction, operand) {

	}
}