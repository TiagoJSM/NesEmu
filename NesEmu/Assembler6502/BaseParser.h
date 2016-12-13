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
	class BaseParser {
	protected:
		vector<InstructionToken> Tokenize(const string& input, const string& delimiters);
	};
}