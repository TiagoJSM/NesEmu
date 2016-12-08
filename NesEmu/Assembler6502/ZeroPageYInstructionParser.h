#pragma once

#include "BaseInstructionParser.h"
#include "ZeroPageYInstructionDescriptor.h"

namespace Assembler6502 {

	class ZeroPageYInstructionParser : public BaseInstructionParser {
	public:
		ZeroPageYInstructionParser();

		BaseInstructionDescriptor* Parse(const string& intruction) override;
	};
}