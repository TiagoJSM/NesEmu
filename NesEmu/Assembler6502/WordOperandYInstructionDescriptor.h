#pragma once

#include "BaseWordOperandInstructionDescriptor.h"

using namespace std;

namespace Assembler6502 {

	class WordOperandYInstructionDescriptor : public BaseWordOperandInstructionDescriptor {
	public:
		WordOperandYInstructionDescriptor(const string& instruction, const uint16_t operand);
	};
}