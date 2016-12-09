#pragma once

#include <vector>

#include "BaseByteOperandInstructionDescriptor.h"

using namespace std;

namespace Assembler6502 {

	class ByteOperandInstructionDescriptor : public BaseByteOperandInstructionDescriptor {
	public:
		ByteOperandInstructionDescriptor(const string& instruction, const uint8_t operand);
		vector<uint8_t> GetOperationCodes();
	};
}