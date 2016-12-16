#include "IndirectYInstructionParser.h"

namespace Assembler6502 {

	IndirectYInstructionParser::IndirectYInstructionParser()
		: BaseIndirectInstructionParser(regex("[a-zA-Z]{3}[ |\t]+\\((\\$)?\\w+\\),[ |\t]*[y|Y]$")) { }

}