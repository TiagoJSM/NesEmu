#include <regex>

#include "ZeroPageInstructionParser.h"
#include "ZeroPageYInstructionParser.h"

using namespace Assembler6502;

int main() {
	ZeroPageYInstructionParser parser1;
	auto canParse = parser1.CanParse("lda $aa,y");
	auto parse = parser1.Parse("lda $aa,y");
	return 0;
}