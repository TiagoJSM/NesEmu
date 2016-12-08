#include "ZeroPageYInstructionParser.h"

namespace Assembler6502 {
	ZeroPageYInstructionParser::ZeroPageYInstructionParser() 
		: BaseZeroPageInstructionParser<ZeroPageYInstructionDescriptor>(regex("[a-zA-Z]{3}[ |\t]+\\$[0-9a-fA-F]{1,2}[ |\t]*,[ |\t]*[y|Y]$")) { }

}