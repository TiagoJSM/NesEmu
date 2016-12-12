#pragma once

#include "BaseInstructionParser.h"
#include "InstructionToken.h"

namespace Assembler6502 {

	template <typename TAbsoluteDescriptor>
	class BaseAbsoluteInstructionParser : public BaseInstructionParser {
	public:
		BaseAbsoluteInstructionParser(regex reg) : BaseInstructionParser(reg) {}
	protected:
		BaseInstructionDescriptor* DoParse(const string& intruction) override {
			auto tokens = Tokenize(intruction, " \t$,");
			return new TAbsoluteDescriptor(tokens[0].AsString(), tokens[1]);
		}
	};
}