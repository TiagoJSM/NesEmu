#include "WordOperandXInstructionDescriptor.h"

namespace Assembler6502 {
	WordOperandXInstructionDescriptor::WordOperandXInstructionDescriptor(const string& instruction, const InstructionToken operand)
		:BaseWordOperandInstructionDescriptor(instruction, operand) {

	}
}