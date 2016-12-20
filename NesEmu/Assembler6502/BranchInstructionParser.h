#pragma once

#include "BaseAbsoluteInstructionParser.h"
#include "BranchInstructionDescriptor.h"

namespace Assembler6502 {

	class BranchInstructionParser : public BaseInstructionParser {
	public:
		BranchInstructionParser();
	protected:
		BaseInstructionDescriptor* DoParse(const string& intruction) override;
	};
}