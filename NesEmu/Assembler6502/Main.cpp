#include <regex>

#include "ZeroPageInstructionParser.h"
#include "ZeroPageYInstructionParser.h"
#include "ZeroPageXInstructionParser.h"
#include "IndirectYInstructionParser.h"

using namespace Assembler6502;

int main() {
	ZeroPageYInstructionParser parser1;
	auto canParseY = parser1.CanParse("lda $aa,y");
	auto parseY = (ByteOperandYInstructionDescriptor*)parser1.Parse("lda $aa,y");

	ZeroPageXInstructionParser parser2;
	auto canParseX = parser2.CanParse("lda $aa,x");
	auto parseX = (ByteOperandXInstructionDescriptor*)parser2.Parse("lda $aa,x");

	IndirectYInstructionParser parser3;
	auto canParseIndirectY = parser3.CanParse("EOR ($44),Y");
	auto parseIndirectX = (WordOperandYInstructionDescriptor*)parser3.Parse("EOR ($44),Y");

	return 0;
}