#pragma once

#include "BaseZeroPageInstructionDescriptor.h"

using namespace std;

namespace Assembler6502 {

	class ZeroPageInstructionDescriptor : public BaseZeroPageInstructionDescriptor {
	public:
		ZeroPageInstructionDescriptor(const string& instruction, const uint8_t operand);
	};
}