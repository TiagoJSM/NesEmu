#pragma once

#include "BaseAbsoluteInstructionParser.h"
#include "AbsoluteInstructionDescriptor.h"

namespace Assembler6502 {

	class AbsoluteInstructionParser : public BaseAbsoluteInstructionParser<AbsoluteInstructionDescriptor> {
	public:
		AbsoluteInstructionParser();
	};
}