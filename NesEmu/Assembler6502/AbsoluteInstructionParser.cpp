#include "AbsoluteInstructionParser.h"

namespace Assembler6502 {

	AbsoluteInstructionParser::AbsoluteInstructionParser()
		: BaseAbsoluteInstructionParser(regex("[a-zA-Z]{3}[ |\t]+(\\$)?\\w+$")) { }

}