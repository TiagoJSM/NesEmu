#pragma once

#include "BaseIndirectInstructionParser.h"
#include "WordOperandXInstructionDescriptor.h"

namespace Assembler6502 {

	class IndirectXInstructionParser : public BaseIndirectInstructionParser<WordOperandXInstructionDescriptor> {
	public:
		IndirectXInstructionParser();
	};
}