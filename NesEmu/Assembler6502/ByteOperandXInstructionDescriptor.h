#pragma once

#include "BaseByteOperandInstructionDescriptor.h"

using namespace std;

namespace Assembler6502 {

	class ByteOperandXInstructionDescriptor : public BaseByteOperandInstructionDescriptor {
	public:
		ByteOperandXInstructionDescriptor(const string& instruction, const uint8_t operand);
	};
}