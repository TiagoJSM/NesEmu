#pragma once

#include <sstream>
#include <regex>
#include <iterator>
#include <iostream>
#include <string>

#include "BaseParser.h"
#include "InstructionToken.h"
#include "Symbols.h"

using namespace std;

namespace Assembler6502 {
	class LabelParser : public BaseParser {
	public:
		LabelParser();

		bool CanParse(const string& intruction);
		string Parse(const string& intruction);
	private:
		regex _labelFormat;
	};
}