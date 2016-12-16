#include "AbsoluteYInstructionParser.h"

namespace Assembler6502 {

	AbsoluteYInstructionParser::AbsoluteYInstructionParser()
		: BaseAbsoluteInstructionParser(regex("[a-zA-Z]{3}[ |\t]+(\\$)?\\w+,[ |\t]*[y|Y]$")) { }

}