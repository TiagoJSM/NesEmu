#pragma once

#include "BaseAbsoluteInstructionDescriptor.h"

using namespace std;

namespace Assembler6502 {

	class AbsoluteInstructionDescriptor : public BaseAbsoluteInstructionDescriptor {
	public:
		AbsoluteInstructionDescriptor(const string& instruction, const uint16_t operand);
	};
}