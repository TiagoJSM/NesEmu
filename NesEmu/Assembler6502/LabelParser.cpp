#include "LabelParser.h"

namespace Assembler6502 {
	LabelParser::LabelParser() {
		_labelFormat = regex("\\w+:$");
	}

	bool LabelParser::CanParse(const string& intruction) {
		return regex_match(intruction, _labelFormat);
	}

	string LabelParser::Parse(const string& intruction) {
		if (CanParse(intruction)) {
			auto tokens = Tokenize(intruction, ":");
			return tokens[0].AsString();
		}
		return string();
	}
}