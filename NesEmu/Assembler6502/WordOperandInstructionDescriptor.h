#pragma once

#include "BaseWordOperandInstructionDescriptor.h"

using namespace std;

namespace Assembler6502 {

	class WordOperandInstructionDescriptor : public BaseWordOperandInstructionDescriptor {
	public:
		WordOperandInstructionDescriptor(const string& instruction, const AddressingMode addressMode, const InstructionToken operand);
		vector<uint8_t> GetOperationCodes(const Labels& labels) override;
	};
}