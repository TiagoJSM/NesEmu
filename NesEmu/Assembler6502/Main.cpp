#include <regex>

#include "ZeroPageInstructionParser.h"
#include "ZeroPageYInstructionParser.h"
#include "ZeroPageXInstructionParser.h"

using namespace Assembler6502;

int main() {
	ZeroPageYInstructionParser parser1;
	auto canParseY = parser1.CanParse("lda $aa,y");
	auto parseY = (ZeroPageYInstructionDescriptor*)parser1.Parse("lda $aa,y");

	ZeroPageXInstructionParser parser2;
	auto canParseX = parser2.CanParse("lda $aa,x");
	auto parseX = (ZeroPageXInstructionDescriptor*)parser2.Parse("lda $aa,x");
	return 0;
}