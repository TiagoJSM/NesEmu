#include "WordOperandInstructionDescriptor.h"

namespace Assembler6502 {
	WordOperandInstructionDescriptor::WordOperandInstructionDescriptor(const string& instruction, const InstructionToken operand)
		:BaseWordOperandInstructionDescriptor(instruction, operand) {

	}
}