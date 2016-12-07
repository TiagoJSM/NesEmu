#include "ParameterlessInstructionParser.h"

namespace Assembler6502 {
	ParameterlessInstructionParser::ParameterlessInstructionParser() : BaseInstructionParser(regex("[a-zA-Z]{3}$")) { }

	BaseInstructionDescriptor* ParameterlessInstructionParser::Parse(const string& intruction) {
		if (BaseInstructionParser::CanParse(intruction)) {
			return new ParameterlessInstructionDescriptor(intruction);
		}
		return nullptr;
	}
}