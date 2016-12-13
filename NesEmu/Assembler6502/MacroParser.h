#pragma once

#include <sstream>
#include <regex>
#include <iterator>
#include <iostream>
#include <string>

#include "BaseParser.h"
#include "InstructionToken.h"
#include "Labels.h"

using namespace std;

namespace Assembler6502 {
	class MacroParser : public BaseParser {
	public:
		MacroParser();

		bool CanParse(const string& intruction);
		void Parse(const string& intruction, Labels<string>& symbols);
	private:
		regex _macroFormat;
	};
}