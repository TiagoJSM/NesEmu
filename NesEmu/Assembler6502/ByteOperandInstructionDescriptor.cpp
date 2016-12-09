#include "ByteOperandInstructionDescriptor.h"

namespace Assembler6502 {
	ByteOperandInstructionDescriptor::ByteOperandInstructionDescriptor(const string& instruction, const uint8_t operand)
		:BaseByteOperandInstructionDescriptor(instruction, operand) {

	}
}