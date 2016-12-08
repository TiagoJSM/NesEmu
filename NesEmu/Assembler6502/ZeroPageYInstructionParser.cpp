#include "ZeroPageYInstructionParser.h"

namespace Assembler6502 {
	ZeroPageYInstructionParser::ZeroPageYInstructionParser() 
		: BaseInstructionParser(regex("[a-zA-Z]{3}[ |\t]+\\$[0-9a-fA-F]{1,2}[ |\t]*,[ |\t]*[y|Y]$")) { }

	BaseInstructionDescriptor* ZeroPageYInstructionParser::Parse(const string& intruction) {
		if (BaseInstructionParser::CanParse(intruction)) {
			auto tokens = Tokenize(intruction, " \t$,");
			auto operand = static_cast<uint8_t>(strtol(tokens[1].c_str(), NULL, 16));
			return new ZeroPageYInstructionDescriptor(tokens[0], operand);
		}
		return nullptr;
	}
}