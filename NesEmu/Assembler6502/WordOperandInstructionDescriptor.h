#pragma once

#include "BaseWordOperandInstructionDescriptor.h"

using namespace std;

namespace Assembler6502 {

	class WordOperandInstructionDescriptor : public BaseWordOperandInstructionDescriptor {
	public:
		WordOperandInstructionDescriptor(const string& instruction, const uint16_t operand);
	};
}