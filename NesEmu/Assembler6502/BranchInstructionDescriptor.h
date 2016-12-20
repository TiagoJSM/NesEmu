#pragma once

#include <vector>

#include "TemplatedOperandInstructionDescriptor.h"

using namespace std;

namespace Assembler6502 {

	class BranchInstructionDescriptor : public TemplatedOperandInstructionDescriptor<uint16_t> {
	public:
		BranchInstructionDescriptor(const string& instruction, const AddressingMode addressMode, const InstructionToken operand);
		uint8_t GetInstructionSize() override;
		vector<uint8_t> GetOperationCodes(const OperationCodeContext& context) override;
	};
}