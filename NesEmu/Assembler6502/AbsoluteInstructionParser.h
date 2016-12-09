#pragma once

#include "BaseAbsoluteInstructionParser.h"
#include "WordOperandInstructionDescriptor.h"

namespace Assembler6502 {

	class AbsoluteInstructionParser : public BaseAbsoluteInstructionParser<WordOperandInstructionDescriptor> {
	public:
		AbsoluteInstructionParser();
	};
}