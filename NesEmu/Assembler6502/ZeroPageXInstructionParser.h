#pragma once

#include "BaseZeroPageInstructionParser.h"
#include "ByteOperandXInstructionDescriptor.h"

namespace Assembler6502 {

	class ZeroPageXInstructionParser : public BaseZeroPageInstructionParser<ByteOperandXInstructionDescriptor> {
	public:
		ZeroPageXInstructionParser();
	};
}