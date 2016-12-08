#include "AbsoluteInstructionParser.h"

namespace Assembler6502 {

	AbsoluteInstructionParser::AbsoluteInstructionParser()
		: BaseAbsoluteInstructionParser(regex("[a-zA-Z]{3}[ |\t]+\\$[0-9a-fA-F]{1,4}$")) { }

}