#pragma once

#include <regex>

#include "BaseInstructionDescriptor.h"

using namespace std;

namespace Assembler6502 {
	class BaseInstructionParser {
	public:
		BaseInstructionParser(regex intructionFormat);

		virtual bool CanParse(const string& intruction);
		virtual BaseInstructionDescriptor* Parse(const string& intruction) = 0;
	private:
		regex _intructionFormat;
	};
}