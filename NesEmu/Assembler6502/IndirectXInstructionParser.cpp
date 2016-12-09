#include "IndirectXInstructionParser.h"

namespace Assembler6502 {

	IndirectXInstructionParser::IndirectXInstructionParser()
		: BaseIndirectInstructionParser(regex("[a-zA-Z]{3}[ |\t]+\\(\\$[0-9a-fA-F]{1,4},[ |\t]*[x|X]\\)$")) { }

}