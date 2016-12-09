#include "ByteOperandXInstructionDescriptor.h"

namespace Assembler6502 {
	ByteOperandXInstructionDescriptor::ByteOperandXInstructionDescriptor(const string& instruction, const uint8_t operand)
		:BaseByteOperandInstructionDescriptor(instruction, operand) {

	}
}