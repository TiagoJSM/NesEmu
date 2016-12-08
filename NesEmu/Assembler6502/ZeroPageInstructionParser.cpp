#include "ZeroPageInstructionParser.h"

namespace Assembler6502 {

	ZeroPageInstructionParser::ZeroPageInstructionParser() 
		: BaseZeroPageInstructionParser(regex("[a-zA-Z]{3}[ |\t]+\\$[0-9a-fA-F]{1,2}$")) { }

}