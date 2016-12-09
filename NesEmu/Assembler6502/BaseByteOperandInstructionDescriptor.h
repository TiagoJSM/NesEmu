#pragma once

#include "TemplatedOperandInstructionDescriptor.h"

using namespace std;

namespace Assembler6502 {
	class BaseByteOperandInstructionDescriptor : public TemplatedOperandInstructionDescriptor<uint8_t> {
	public:
		BaseByteOperandInstructionDescriptor(const string& instruction, const uint8_t operand);
	};
}