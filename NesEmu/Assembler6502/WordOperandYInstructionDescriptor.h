#pragma once

#include <vector>

#include "BaseWordOperandInstructionDescriptor.h"
#include "InstructionToken.h"

using namespace std;

namespace Assembler6502 {

	class WordOperandYInstructionDescriptor : public BaseWordOperandInstructionDescriptor {
	public:
		WordOperandYInstructionDescriptor(const string& instruction, const AddressingMode addressMode, const InstructionToken operand);
		vector<uint8_t> GetOperationCodes(const Labels& labels) override;
	};
}