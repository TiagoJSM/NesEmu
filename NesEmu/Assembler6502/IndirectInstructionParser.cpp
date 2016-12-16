#include "IndirectInstructionParser.h"

namespace Assembler6502 {

	IndirectInstructionParser::IndirectInstructionParser()
		: BaseIndirectInstructionParser(regex("[a-zA-Z]{3}[ |\t]+\\((\\$)?\\w+\\)$")) { }

}