#include "BaseInstructionParser.h"

namespace Assembler6502 {
	BaseInstructionParser::BaseInstructionParser(regex intructionFormat) :_intructionFormat(intructionFormat) {
	}

	bool BaseInstructionParser::CanParse(const string& intruction) {
		return regex_match(intruction, _intructionFormat);
	}

	BaseInstructionDescriptor* BaseInstructionParser::Parse(const string& intruction) {
		if (CanParse(intruction)) {
			return DoParse(intruction);
		}
		return nullptr;
	}

	regex BaseInstructionParser::GetInstructionFormat() {
		return _intructionFormat;
	}

	vector<InstructionToken> BaseInstructionParser::Tokenize(const string& input, const string& delimiters) {
		stringstream stringStream(input);
		vector<InstructionToken> result;
		string line;
		while (getline(stringStream, line))
		{
			size_t prev = 0, pos;
			while ((pos = line.find_first_of(delimiters, prev)) != std::string::npos)
			{
				if (pos > prev) {

					result.push_back(InstructionToken(line.substr(prev, pos - prev)));
				}
					
				prev = pos + 1;
			}
			if (prev < line.length()) {
				result.push_back(InstructionToken(line.substr(prev, std::string::npos)));
			}
				
		}
		return result;
	}
}