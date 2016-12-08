#pragma once

#include "BaseZeroPageInstructionDescriptor.h"

using namespace std;

namespace Assembler6502 {

	class ZeroPageXInstructionDescriptor : public BaseZeroPageInstructionDescriptor {
	public:
		ZeroPageXInstructionDescriptor(const string& instruction, const uint8_t operand);
	};
}