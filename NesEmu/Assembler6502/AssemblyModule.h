#pragma once

#include <vector>
#include <stdexcept>

#include "Symbols.h"
#include "MacroParser.h"
#include "StringHelpers.h"
#include "cpplinq.hpp"

using namespace std;
using namespace cpplinq;

namespace Assembler6502 {
	class AssemblyModule {
	public:
		AssemblyModule(const vector<string>& intructionLines);

		vector<uint8_t> Compile();
	
	private:
		vector<string> _intructionLines;

		vector<string> RemoveComments();
		string RemoveSingleLineComment(const string& line);
		vector<string> PreProcess(const vector<string>& lines);
		Macros ProcessMacros(const vector<string>& lines);
		vector<string> RemoveMacros(const vector<string>& lines);
		vector<string> RemoveEmptyLinesAndTrim(const vector<string>& lines);
	};
}