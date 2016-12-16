#pragma once

#include "BaseByteOperandInstructionDescriptor.h"

using namespace std;

namespace Assembler6502 {

	class ByteOperandXInstructionDescriptor : public BaseByteOperandInstructionDescriptor {
	public:
		ByteOperandXInstructionDescriptor(const string& instruction, const AddressingMode addressMode, const InstructionToken operand);
		vector<uint8_t> GetOperationCodes(const Labels& labels) override;
	};
}