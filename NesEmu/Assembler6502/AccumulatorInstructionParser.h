#pragma once

#include "BaseInstructionParser.h"
#include "ParameterlessInstructionDescriptor.h"
#include "InstructionToken.h"

namespace Assembler6502 {

	class AccumulatorInstructionParser : public BaseInstructionParser {
	public:
		AccumulatorInstructionParser();
	protected:
		BaseInstructionDescriptor* DoParse(const string& intruction) override;
	};
}