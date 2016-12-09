#pragma once

#include "BaseAbsoluteInstructionParser.h"
#include "WordOperandYInstructionDescriptor.h"

namespace Assembler6502 {

	class AbsoluteYInstructionParser : public BaseAbsoluteInstructionParser<WordOperandYInstructionDescriptor> {
	public:
		AbsoluteYInstructionParser();
	};
}