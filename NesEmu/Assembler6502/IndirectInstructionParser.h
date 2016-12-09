#pragma once

#include "BaseIndirectInstructionParser.h"
#include "WordOperandInstructionDescriptor.h"

namespace Assembler6502 {

	class IndirectInstructionParser : public BaseIndirectInstructionParser<WordOperandInstructionDescriptor> {
	public:
		IndirectInstructionParser();
	};
}