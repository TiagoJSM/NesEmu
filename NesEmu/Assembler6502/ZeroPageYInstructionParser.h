#pragma once

#include "BaseZeroPageInstructionParser.h"
#include "ZeroPageYInstructionDescriptor.h"

namespace Assembler6502 {

	class ZeroPageYInstructionParser : public BaseZeroPageInstructionParser<ZeroPageYInstructionDescriptor> {
	public:
		ZeroPageYInstructionParser();
	};
}