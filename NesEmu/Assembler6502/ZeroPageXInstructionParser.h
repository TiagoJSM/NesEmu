#pragma once

#include "BaseZeroPageInstructionParser.h"
#include "ZeroPageXInstructionDescriptor.h"

namespace Assembler6502 {

	class ZeroPageXInstructionParser : public BaseZeroPageInstructionParser<ZeroPageXInstructionDescriptor> {
	public:
		ZeroPageXInstructionParser();
	};
}