#pragma once

#include <vector>

#include "BaseInstructionDescriptor.h"

using namespace std;

namespace Assembler6502 {

	class ParameterlessInstructionDescriptor : public BaseInstructionDescriptor {
	public:
		ParameterlessInstructionDescriptor(const string& instruction, const AddressingMode addressMode);
		uint8_t GetInstructionSize() override;
		vector<uint8_t> GetOperationCodes(const Labels& labels) override;
	private:
		string _instruction;
		AddressingMode _addressMode;
	};
}