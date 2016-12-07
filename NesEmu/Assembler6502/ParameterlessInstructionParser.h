#pragma once

#include "BaseInstructionParser.h"
#include "ParameterlessInstructionDescriptor.h"

namespace Assembler6502 {

	class ParameterlessInstructionParser : public BaseInstructionParser {
	public:
		ParameterlessInstructionParser();

		BaseInstructionDescriptor* Parse(const string& intruction) override;
	};
}