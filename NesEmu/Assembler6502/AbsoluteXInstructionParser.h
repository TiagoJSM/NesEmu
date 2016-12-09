#pragma once

#include "BaseAbsoluteInstructionParser.h"
#include "WordOperandXInstructionDescriptor.h"

namespace Assembler6502 {

	class AbsoluteXInstructionParser : public BaseAbsoluteInstructionParser<WordOperandXInstructionDescriptor> {
	public:
		AbsoluteXInstructionParser();
	};
}