#pragma once

#include <vector>

#include "BaseWordOperandInstructionDescriptor.h"
#include "InstructionToken.h"

using namespace std;

namespace Assembler6502 {

	class WordOperandYInstructionDescriptor : public BaseWordOperandInstructionDescriptor {
	public:
		WordOperandYInstructionDescriptor(const string& instruction, const InstructionToken operand);
	};
}