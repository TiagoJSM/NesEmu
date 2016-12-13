#include "AssemblyModule.h"

namespace Assembler6502 {
	const char SINGLE_LINE_COMMENT_IDENTIFIER = ';';

	AssemblyModule::AssemblyModule(vector<string>& intructionLines) :_intructionLines(intructionLines){
	}

	vector<uint8_t> AssemblyModule::Compile() {
		auto uncommented = RemoveComments();
		auto prerocessedCode = PreProcess(uncommented);
		return vector<uint8_t>();
	}

	vector<string> AssemblyModule::RemoveComments() {
		auto uncommented = vector<string>();
		for (auto iterator = _intructionLines.begin(); iterator != _intructionLines.end(); iterator++) {
			uncommented.push_back(RemoveSingleLineComment(*iterator));
		}
		return uncommented;
	}

	string AssemblyModule::RemoveSingleLineComment(const string& line) {
		auto pos = line.find(SINGLE_LINE_COMMENT_IDENTIFIER);
		if (pos == string::npos) {
			return line;
		}
		return line.substr(0, pos);
	}

	vector<string> AssemblyModule::PreProcess(const vector<string>& lines) {
		auto macros = ProcessMacros(lines);
		return ReplaceWithMacros(lines, macros);
	}

	Symbols<string> AssemblyModule::ProcessMacros(const vector<string>& lines) {
		Symbols<string> macros;
		MacroParser macroParser;
		for (auto iterator = lines.begin(); iterator != lines.end(); iterator++) {
			if (macroParser.CanParse(*iterator)) {
				macroParser.Parse(*iterator, macros);
			}
		}
		return macros;
	}

	vector<string> AssemblyModule::ReplaceWithMacros(const vector<string>& lines, const Symbols<string>& macros) {
		return lines;
	}
}