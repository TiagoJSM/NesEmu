#pragma once

#include "BaseZeroPageInstructionDescriptor.h"

using namespace std;

namespace Assembler6502 {

	class ZeroPageYInstructionDescriptor : public BaseZeroPageInstructionDescriptor {
	public:
		ZeroPageYInstructionDescriptor(const string& instruction, const uint8_t operand);
	};
}