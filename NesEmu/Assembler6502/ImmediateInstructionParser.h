#pragma once

#include "BaseInstructionParser.h"
#include "ByteOperandInstructionDescriptor.h"
#include "InstructionToken.h"

namespace Assembler6502 {

	class ImmediateInstructionParser : public BaseInstructionParser {
	public:
		ImmediateInstructionParser() : BaseInstructionParser(regex("[a-zA-Z]{3}[ |\t]+#\\$[0-9a-fA-F]{1,2}$")) {}
	protected:
		BaseInstructionDescriptor* DoParse(const string& intruction) override {
			auto tokens = Tokenize(intruction, " \t#$,");
			return new ByteOperandInstructionDescriptor(tokens[0].AsString(), AddressingMode::Immediate, tokens[1]);
		}
	};
}