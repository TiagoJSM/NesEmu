#pragma once

#include "BaseZeroPageInstructionParser.h"
#include "ZeroPageInstructionDescriptor.h"

namespace Assembler6502 {

	class ZeroPageInstructionParser : public BaseZeroPageInstructionParser<ZeroPageInstructionDescriptor> {
	public:
		ZeroPageInstructionParser();
	};
}