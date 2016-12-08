#pragma once

#include <sstream>
#include <regex>
#include <iterator>
#include <iostream>
#include <string>

#include "BaseInstructionDescriptor.h"

using namespace std;

namespace Assembler6502 {
	class BaseInstructionParser {
	public:
		BaseInstructionParser(regex intructionFormat);

		virtual bool CanParse(const string& intruction);
		virtual BaseInstructionDescriptor* Parse(const string& intruction) = 0;
	protected:
		regex GetInstructionFormat();
		vector<string> Tokenize(const string& input, const string& delimiters);
	private:
		regex _intructionFormat;
	};
}