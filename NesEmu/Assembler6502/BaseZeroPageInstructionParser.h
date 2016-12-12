#pragma once

#include "BaseInstructionParser.h"
#include "InstructionToken.h"

namespace Assembler6502 {

	template <typename TZeroPageDescriptor>
	class BaseZeroPageInstructionParser : public BaseInstructionParser {
	public:
		BaseZeroPageInstructionParser(regex reg) : BaseInstructionParser(reg) {}
	protected:
		BaseInstructionDescriptor* DoParse(const string& intruction) override {
			auto tokens = Tokenize(intruction, " \t$,");
			return new TZeroPageDescriptor(tokens[0].AsString(), tokens[1]);
		}
	};
}