#include "ZeroPageInstructionParser.h"

namespace Assembler6502 {
	ZeroPageInstructionParser::ZeroPageInstructionParser() 
		: BaseInstructionParser(regex("[a-zA-Z]{3}[ |\t]+\\$[0-9a-fA-F]{1,2}$")) { }

	BaseInstructionDescriptor* ZeroPageInstructionParser::Parse(const string& intruction) {
		if (BaseInstructionParser::CanParse(intruction)) {
			return new ZeroPageInstructionDescriptor(intruction);
		}
		return nullptr;
	}
}