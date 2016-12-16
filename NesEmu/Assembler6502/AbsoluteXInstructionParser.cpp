#include "AbsoluteXInstructionParser.h"

namespace Assembler6502 {

	AbsoluteXInstructionParser::AbsoluteXInstructionParser()
		: BaseAbsoluteInstructionParser(regex("[a-zA-Z]{3}[ |\t]+(\\$)?\\w+,[ |\t]*[x|X]$")) { }

}