#include "BranchInstructionParser.h"

namespace Assembler6502 {

	BranchInstructionParser::BranchInstructionParser()
		: BaseInstructionParser(regex("(BPL|BMI|BVC|BVS|BCC|BCS|BNE|BEQ)[ |\t]+(\\$)?\\w+$")) { }

	BaseInstructionDescriptor* BranchInstructionParser::DoParse(const string& intruction) {
		auto tokens = Tokenize(intruction, " \t$,");
		return new BranchInstructionDescriptor(tokens[0].AsString(), AddressingMode::None, tokens[1]);
	}
}