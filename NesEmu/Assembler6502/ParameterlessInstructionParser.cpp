#include "ParameterlessInstructionParser.h"

namespace Assembler6502 {
	ParameterlessInstructionParser::ParameterlessInstructionParser() : BaseInstructionParser(regex("[a-zA-Z]{3}$")) { }

	BaseInstructionDescriptor* ParameterlessInstructionParser::DoParse(const string& intruction) {
		return new ParameterlessInstructionDescriptor(intruction);
	}
}