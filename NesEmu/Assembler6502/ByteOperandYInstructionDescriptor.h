#pragma once

#include "BaseByteOperandInstructionDescriptor.h"

using namespace std;

namespace Assembler6502 {

	class ByteOperandYInstructionDescriptor : public BaseByteOperandInstructionDescriptor {
	public:
		ByteOperandYInstructionDescriptor(const string& instruction, const InstructionToken operand);
	};
}