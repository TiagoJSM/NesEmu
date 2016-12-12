#pragma once

#include "BaseWordOperandInstructionDescriptor.h"
#include "InstructionToken.h"

using namespace std;

namespace Assembler6502 {

	class WordOperandXInstructionDescriptor : public BaseWordOperandInstructionDescriptor {
	public:
		WordOperandXInstructionDescriptor(const string& instruction, const InstructionToken operand);
	};
}