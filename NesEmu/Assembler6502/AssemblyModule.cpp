#include "AssemblyModule.h"

namespace Assembler6502 {
	typedef void(*Validate)(const string&);
	const char SINGLE_LINE_COMMENT_IDENTIFIER = ';';

	AssemblyModule::AssemblyModule(const vector<string>& intructionLines) :_intructionLines(intructionLines){
	}

	vector<uint8_t> AssemblyModule::Compile() {
		auto uncommented = RemoveComments();
		auto preProcessedCode = PreProcess(uncommented);
		ValidateUnknownInstructions(preProcessedCode);
		auto labels = CollectLabels(preProcessedCode);
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
		auto linesWithoutMacros = RemoveMacros(lines);
		auto replacedCode = macros.Replace(linesWithoutMacros);
		return RemoveEmptyLinesAndTrim(replacedCode);
	}

	Macros AssemblyModule::ProcessMacros(const vector<string>& lines) {
		Macros macros;
		MacroParser macroParser;
		for (auto iterator = lines.begin(); iterator != lines.end(); iterator++) {
			if (macroParser.CanParse(*iterator)) {
				macroParser.Parse(*iterator, macros);
			}
		}
		return macros;
	}

	vector<string> AssemblyModule::RemoveMacros(const vector<string>& lines) {
		MacroParser macroParser;
		auto linesWithoutMacros = lines;
		linesWithoutMacros
			.erase(
				remove_if(
					linesWithoutMacros.begin(), 
					linesWithoutMacros.end(), 
					[&macroParser](string line) { return macroParser.CanParse(line); }));
		return linesWithoutMacros;
	}

	vector<string> AssemblyModule::RemoveEmptyLinesAndTrim(const vector<string>& lines) {
		auto nonEmptyLines = lines;
		return from(nonEmptyLines)
			>> select([](string line) {
				line.erase(remove(line.begin(), line.end(), '\n\v\f\r'), line.end());
				return line; })
			>> select([](string line) { return trimmed(line); })
			>> where([](string line) {return !line.empty(); })
			>> to_vector();
	}

	void AssemblyModule::ValidateUnknownInstructions(const vector<string>& lines) {
		LabelParser labelParser;
		ZeroPageInstructionParser zeroPageParser;
		ZeroPageXInstructionParser zeroPageXParser;
		ZeroPageYInstructionParser zeroPageYParser;
		IndirectInstructionParser indirectParser;
		IndirectXInstructionParser indirectXParser;
		IndirectYInstructionParser indirectYParser;
		AbsoluteInstructionParser absoluteParser;
		AbsoluteXInstructionParser absoluteXParser;
		AbsoluteYInstructionParser absoluteYParser;
		
		vector<function<bool(const string&)>> validators = {
			[&](const string& line) {return labelParser.CanParse(line); },

			[&](const string& line) {return zeroPageParser.CanParse(line); },
			[&](const string& line) {return zeroPageXParser.CanParse(line); },
			[&](const string& line) {return zeroPageYParser.CanParse(line); },

			[&](const string& line) {return indirectParser.CanParse(line); },
			[&](const string& line) {return indirectXParser.CanParse(line); },
			[&](const string& line) {return indirectYParser.CanParse(line); },

			[&](const string& line) {return absoluteParser.CanParse(line); },
			[&](const string& line) {return absoluteXParser.CanParse(line); },
			[&](const string& line) {return absoluteYParser.CanParse(line); },
		};

		auto isValid = [&](const string& line) {
			return from(validators) >> any([&](function<bool(const string&)> validator) { return validator(line); });
		};

		auto valid =
			from(lines)
			>> any([&](const string& line) {
				return isValid(line); }
		);

		if (!valid) {
			cout << "error" << endl;
		}
	}

	Labels AssemblyModule::CollectLabels(const vector<string>& lines) {
		return Labels();
	}
}