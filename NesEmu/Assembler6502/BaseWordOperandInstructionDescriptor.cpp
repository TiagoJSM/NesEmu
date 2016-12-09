#include "BaseWordOperandInstructionDescriptor.h"

namespace Assembler6502 {
	BaseWordOperandInstructionDescriptor::BaseWordOperandInstructionDescriptor(const string& instruction, const uint16_t operand)
		:TemplatedOperandInstructionDescriptor(instruction, operand) {

	}
}