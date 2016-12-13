#include "BaseInstructionParser.h"

namespace Assembler6502 {
	BaseInstructionParser::BaseInstructionParser(regex intructionFormat) :_intructionFormat(intructionFormat) {
	}

	bool BaseInstructionParser::CanParse(const string& intruction) {
		return regex_match(intruction, _intructionFormat);
	}

	BaseInstructionDescriptor* BaseInstructionParser::Parse(const string& intruction) {
		if (CanParse(intruction)) {
			return DoParse(intruction);
		}
		return nullptr;
	}

	regex BaseInstructionParser::GetInstructionFormat() {
		return _intructionFormat;
	}

}