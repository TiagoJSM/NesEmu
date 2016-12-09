#pragma once

#include "BaseWordOperandInstructionDescriptor.h"

using namespace std;

namespace Assembler6502 {

	class WordOperandXInstructionDescriptor : public BaseWordOperandInstructionDescriptor {
	public:
		WordOperandXInstructionDescriptor(const string& instruction, const uint16_t operand);
	};
}