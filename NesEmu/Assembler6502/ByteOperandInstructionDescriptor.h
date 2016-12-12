#pragma once

#include <vector>

#include "BaseByteOperandInstructionDescriptor.h"

using namespace std;

namespace Assembler6502 {

	class ByteOperandInstructionDescriptor : public BaseByteOperandInstructionDescriptor {
	public:
		ByteOperandInstructionDescriptor(const string& instruction, const InstructionToken operand);
		vector<uint8_t> GetOperationCodes(const Labels& labels);
	};
}