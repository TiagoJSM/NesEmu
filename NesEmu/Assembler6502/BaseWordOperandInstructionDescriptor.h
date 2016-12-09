#pragma once

#include "TemplatedOperandInstructionDescriptor.h"

using namespace std;

namespace Assembler6502 {
	class BaseWordOperandInstructionDescriptor : public TemplatedOperandInstructionDescriptor<uint16_t> {
	public:
		BaseWordOperandInstructionDescriptor(const string& instruction, const uint16_t operand);
	};
}