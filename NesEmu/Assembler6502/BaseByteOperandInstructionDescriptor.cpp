#include "BaseByteOperandInstructionDescriptor.h"

namespace Assembler6502 {
	BaseByteOperandInstructionDescriptor::BaseByteOperandInstructionDescriptor(const string& instruction, const uint8_t operand) 
		:TemplatedOperandInstructionDescriptor(instruction, operand) {

	}
}