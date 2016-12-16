#include "MacroParser.h"

namespace Assembler6502 {
	MacroParser::MacroParser() {
		_macroFormat = regex("define[ |\t]+\\w+[ |\t]+[^\\s|^\t]+$");
	}

	bool MacroParser::CanParse(const string& intruction) {
		return regex_match(intruction, _macroFormat);
	}

	void MacroParser::Parse(const string& intruction, Symbols<string>& symbols) {
		if (CanParse(intruction)) {
			auto tokens = Tokenize(intruction, " \t,");
			symbols.AddLabel(tokens[1].AsString(), tokens[2].AsString());
		}
	}
}