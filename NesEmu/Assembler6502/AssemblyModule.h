#pragma once

#include <vector>

#include "Symbols.h"
#include "MacroParser.h"

using namespace std;

namespace Assembler6502 {
	class AssemblyModule {
	public:
		AssemblyModule(vector<string>& intructionLines);

		vector<uint8_t> Compile();
	
	private:
		vector<string> _intructionLines;

		vector<string> RemoveComments();
		string RemoveSingleLineComment(const string& line);
		vector<string> PreProcess(const vector<string>& lines);
		Macros ProcessMacros(const vector<string>& lines);
	};
}