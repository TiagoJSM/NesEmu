#pragma once

#include <sstream>
#include <regex>
#include <iterator>
#include <iostream>
#include <string>

#include "BaseInstructionDescriptor.h"
#include "InstructionToken.h"

using namespace std;

namespace Assembler6502 {
	class BaseInstructionParser {
	public:
		BaseInstructionParser(regex intructionFormat);

		virtual bool CanParse(const string& intruction);
		virtual BaseInstructionDescriptor* Parse(const string& intruction);
	protected:
		regex GetInstructionFormat();
		vector<InstructionToken> Tokenize(const string& input, const string& delimiters);
		virtual BaseInstructionDescriptor* DoParse(const string& intruction) = 0;
	private:
		regex _intructionFormat;
	};
}