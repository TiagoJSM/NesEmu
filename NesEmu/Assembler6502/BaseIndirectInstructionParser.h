#pragma once

#include "BaseInstructionParser.h"
#include "InstructionToken.h"

namespace Assembler6502 {

	template <typename TIndirectDescriptor>
	class BaseIndirectInstructionParser : public BaseInstructionParser {
	public:
		BaseIndirectInstructionParser(regex reg) : BaseInstructionParser(reg) {}
	protected:
		BaseInstructionDescriptor* DoParse(const string& intruction) override {
			auto tokens = Tokenize(intruction, " \t()$,");
			return new TIndirectDescriptor(tokens[0].AsString(), tokens[1]);
		}
	};
}