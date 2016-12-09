#pragma once

#include "BaseZeroPageInstructionParser.h"
#include "ByteOperandInstructionDescriptor.h"

namespace Assembler6502 {

	class ZeroPageInstructionParser : public BaseZeroPageInstructionParser<ByteOperandInstructionDescriptor> {
	public:
		ZeroPageInstructionParser();
	};
}