#include "ByteOperandXInstructionDescriptor.h"

namespace Assembler6502 {
	ByteOperandXInstructionDescriptor::ByteOperandXInstructionDescriptor(const string& instruction, const InstructionToken operand)
		:BaseByteOperandInstructionDescriptor(instruction, operand) {

	}
}