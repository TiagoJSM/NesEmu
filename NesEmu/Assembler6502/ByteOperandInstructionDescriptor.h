#pragma once

#include <vector>

#include "BaseByteOperandInstructionDescriptor.h"

using namespace std;

namespace Assembler6502 {

	class ByteOperandInstructionDescriptor : public BaseByteOperandInstructionDescriptor {
	public:
		ByteOperandInstructionDescriptor(const string& instruction, const AddressingMode addressMode, const InstructionToken operand);
		vector<uint8_t> GetOperationCodes(const OperationCodeContext& context) override;
	};
}