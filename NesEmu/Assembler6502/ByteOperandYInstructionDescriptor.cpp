#include "ByteOperandYInstructionDescriptor.h"

namespace Assembler6502 {
	ByteOperandYInstructionDescriptor::ByteOperandYInstructionDescriptor(const string& instruction, const uint8_t operand)
		:BaseByteOperandInstructionDescriptor(instruction, operand) {

	}
}