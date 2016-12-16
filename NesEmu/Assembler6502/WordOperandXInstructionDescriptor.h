#pragma once

#include "BaseWordOperandInstructionDescriptor.h"
#include "InstructionToken.h"

using namespace std;

namespace Assembler6502 {

	class WordOperandXInstructionDescriptor : public BaseWordOperandInstructionDescriptor {
	public:
		WordOperandXInstructionDescriptor(const string& instruction, const AddressingMode addressMode, const InstructionToken operand);
		vector<uint8_t> GetOperationCodes(const Labels& labels) override;
	};
}