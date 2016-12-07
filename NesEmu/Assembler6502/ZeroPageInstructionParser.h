#pragma once

#include "BaseInstructionParser.h"
#include "ZeroPageInstructionDescriptor.h"

namespace Assembler6502 {

	class ZeroPageInstructionParser : public BaseInstructionParser {
	public:
		ZeroPageInstructionParser();

		BaseInstructionDescriptor* Parse(const string& intruction) override;
	};
}