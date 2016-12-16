#include "IndirectXInstructionParser.h"

namespace Assembler6502 {

	IndirectXInstructionParser::IndirectXInstructionParser()
		: BaseIndirectInstructionParser(regex("[a-zA-Z]{3}[ |\t]+\\((\\$)?\\w+,[ |\t]*[x|X]\\)$")) { }

}