#include "AccumulatorInstructionParser.h"

namespace Assembler6502 {
	AccumulatorInstructionParser::AccumulatorInstructionParser() : BaseInstructionParser(regex("[a-zA-Z]{3}[ |\t]+[a|A]$")) {}

	BaseInstructionDescriptor* AccumulatorInstructionParser::DoParse(const string& intruction) {
		auto tokens = Tokenize(intruction, " ");
		return new ParameterlessInstructionDescriptor(tokens[0].AsString(), AddressingMode::Accumulator);
	}
}