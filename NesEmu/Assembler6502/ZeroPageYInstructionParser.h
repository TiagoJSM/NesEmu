#pragma once

#include "BaseZeroPageInstructionParser.h"
#include "ByteOperandYInstructionDescriptor.h"

namespace Assembler6502 {

	class ZeroPageYInstructionParser : public BaseZeroPageInstructionParser<ByteOperandYInstructionDescriptor> {
	public:
		ZeroPageYInstructionParser();
	};
}