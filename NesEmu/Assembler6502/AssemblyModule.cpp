#include "AssemblyModule.h"

namespace Assembler6502 {
	typedef void(*Validate)(const string&);
	const char SINGLE_LINE_COMMENT_IDENTIFIER = ';';

	AssemblyModule::AssemblyModule(const vector<string>& intructionLines) :_intructionLines(intructionLines) {
		_unknownLinesValidators = {
			[&](const string& line) {return _labelParser.CanParse(line); },

			[&](const string& line) {return _zeroPageParser.CanParse(line); },
			[&](const string& line) {return _zeroPageXParser.CanParse(line); },
			[&](const string& line) {return _zeroPageYParser.CanParse(line); },

			[&](const string& line) {return _indirectParser.CanParse(line); },
			[&](const string& line) {return _indirectXParser.CanParse(line); },
			[&](const string& line) {return _indirectYParser.CanParse(line); },

			[&](const string& line) {return _absoluteParser.CanParse(line); },
			[&](const string& line) {return _absoluteXParser.CanParse(line); },
			[&](const string& line) {return _absoluteYParser.CanParse(line); },
		};

		_instructionParsers = {
			&_zeroPageParser,
			&_zeroPageXParser,
			&_zeroPageYParser,
			&_indirectParser,
			&_indirectXParser,
			&_indirectYParser,
			&_absoluteParser,
			&_absoluteXParser,
			&_absoluteYParser,
		};
	}

	CompilationResult AssemblyModule::Compile(const uint16_t baseAddress) {
		auto uncommented = RemoveComments();
		auto preProcessedCode = PreProcess(uncommented);
		auto invalidLines = ValidateUnknownLines(preProcessedCode);

		if (!invalidLines.empty()) {
			return CompilationResult(invalidLines);
		}

		auto labels = CollectLabels(preProcessedCode, baseAddress);
		return CompilationResult(vector<uint8_t>());
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
		for (auto iterator = lines.begin(); iterator != lines.end(); iterator++) {
			if (_macroParser.CanParse(*iterator)) {
				_macroParser.Parse(*iterator, macros);
			}
		}
		return macros;
	}

	vector<string> AssemblyModule::RemoveMacros(const vector<string>& lines) {
		auto linesWithoutMacros = lines;
		linesWithoutMacros
			.erase(
				remove_if(
					linesWithoutMacros.begin(), 
					linesWithoutMacros.end(), 
					[&](string line) { return _macroParser.CanParse(line); }));
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

	vector<string> AssemblyModule::ValidateUnknownLines(const vector<string>& lines) {
		auto isValid = [&](const string& line) {
			return from(_unknownLinesValidators) >> any([&](function<bool(const string&)> validator) { return validator(line); });
		};

		auto invalidLines =
			from(lines)
			>> where([&](const string& line) { return !isValid(line); })
			>> to_vector();

		return invalidLines;
	}

	Labels AssemblyModule::CollectLabels(const vector<string>& lines, const uint16_t baseAddress) {
		auto currentAddress = baseAddress;
		return Labels();
	}
}