#include "AbsoluteYInstructionParser.h"

namespace Assembler6502 {

	AbsoluteYInstructionParser::AbsoluteYInstructionParser()
		: BaseAbsoluteInstructionParser(regex("[a-zA-Z]{3}[ |\t]+\\$[0-9a-fA-F]{1,4},[ |\t]*[y|Y]$")) { }

}