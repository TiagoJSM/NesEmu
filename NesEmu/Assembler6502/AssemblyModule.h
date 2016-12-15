#pragma once

#include <vector>
#include <stdexcept>

#include "Symbols.h"
#include "MacroParser.h"
#include "StringHelpers.h"
#include "LabelParser.h"
#include "ZeroPageInstructionParser.h"
#include "ZeroPageXInstructionParser.h"
#include "ZeroPageYInstructionParser.h"
#include "IndirectInstructionParser.h"
#include "IndirectXInstructionParser.h"
#include "IndirectYInstructionParser.h"
#include "AbsoluteInstructionParser.h"
#include "AbsoluteXInstructionParser.h"
#include "AbsoluteYInstructionParser.h"

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
		void ValidateUnknownInstructions(const vector<string>& lines);
		Labels CollectLabels(const vector<string>& lines);
	};
}