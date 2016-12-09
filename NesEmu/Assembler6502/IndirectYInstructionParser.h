#pragma once

#include "BaseIndirectInstructionParser.h"
#include "WordOperandYInstructionDescriptor.h"

namespace Assembler6502 {

	class IndirectYInstructionParser : public BaseIndirectInstructionParser<WordOperandYInstructionDescriptor> {
	public:
		IndirectYInstructionParser();
	};
}