#include "ZeroPageXInstructionParser.h"

namespace Assembler6502 {
	ZeroPageXInstructionParser::ZeroPageXInstructionParser()
		: BaseZeroPageInstructionParser<ZeroPageXInstructionDescriptor>(regex("[a-zA-Z]{3}[ |\t]+\\$[0-9a-fA-F]{1,2}[ |\t]*,[ |\t]*[x|X]$")) { }
}