#pragma once

#include <vector>
#include <stdexcept>

#include "Symbols.h"
#include "MacroParser.h"
#include "StringHelpers.h"
#include "LabelParser.h"
#include "ParameterlessInstructionParser.h"
#include "ImmediateInstructionParser.h"
#include "ZeroPageInstructionParser.h"
#include "ZeroPageXInstructionParser.h"
#include "ZeroPageYInstructionParser.h"
#include "IndirectInstructionParser.h"
#include "IndirectXInstructionParser.h"
#include "IndirectYInstructionParser.h"
#include "AbsoluteInstructionParser.h"
#include "AbsoluteXInstructionParser.h"
#include "AbsoluteYInstructionParser.h"
#include "CompilationResult.h"

#include "cpplinq.hpp"

using namespace std;
using namespace cpplinq;

namespace Assembler6502 {
	class AssemblyModule {
	public:
		AssemblyModule(const vector<string>& intructionLines);

		CompilationResult Compile(const uint16_t baseAddress = 0);
	
	private:
		vector<string> _intructionLines;

		LabelParser _labelParser;
		MacroParser _macroParser;
		ParameterlessInstructionParser _parameterlessParser;
		ImmediateInstructionParser _immediateParser;
		ZeroPageInstructionParser _zeroPageParser;
		ZeroPageXInstructionParser _zeroPageXParser;
		ZeroPageYInstructionParser _zeroPageYParser;
		IndirectInstructionParser _indirectParser;
		IndirectXInstructionParser _indirectXParser;
		IndirectYInstructionParser _indirectYParser;
		AbsoluteInstructionParser _absoluteParser;
		AbsoluteXInstructionParser _absoluteXParser;
		AbsoluteYInstructionParser _absoluteYParser;

		vector<function<bool(const string&)>> _unknownLinesValidators;
		vector<BaseInstructionParser*> _instructionParsers;

		vector<string> RemoveComments();
		string RemoveSingleLineComment(const string& line);
		vector<string> PreProcess(const vector<string>& lines);
		Macros ProcessMacros(const vector<string>& lines);
		vector<string> RemoveMacros(const vector<string>& lines);
		vector<string> RemoveEmptyLinesAndTrim(const vector<string>& lines);
		vector<string> ValidateUnknownLines(const vector<string>& lines);
		Labels CollectLabels(const vector<string>& lines, const uint16_t baseAddress);
		BaseInstructionParser* GetParser(const string& line);
		vector<uint8_t> GenerateByteCode(const vector<string>& lines, const Labels& labels);
	};
}