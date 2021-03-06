#include <regex>

#include "ZeroPageInstructionParser.h"
#include "ZeroPageYInstructionParser.h"
#include "ZeroPageXInstructionParser.h"
#include "IndirectYInstructionParser.h"
#include "MacroParser.h"
#include "AssemblyModule.h"

using namespace Assembler6502;

int main() {
	Labels labels;
	Macros macros;
	OperationCodeContext context(labels, 0);

	/*ZeroPageYInstructionParser parser1;
	auto canParseY = parser1.CanParse("lda $aa,y");
	auto parseY = (ByteOperandYInstructionDescriptor*)parser1.Parse("lda $aa,y");

	ZeroPageXInstructionParser parser2;
	auto canParseX = parser2.CanParse("lda $aa,x");
	auto parseX = (ByteOperandXInstructionDescriptor*)parser2.Parse("lda $aa,x");*/

	/*IndirectYInstructionParser parser3;
	auto canParseIndirectY = parser3.CanParse("EOR ($44),Y");
	auto parseIndirectX = (WordOperandYInstructionDescriptor*)parser3.Parse("EOR ($44),Y");*/

	/*ZeroPageInstructionParser parser4;
	auto canParseZeroPage = parser4.CanParse("EOR $44");
	auto zeroPageParsed = (ByteOperandInstructionDescriptor*)parser4.Parse("EOR $40");
	auto data = zeroPageParsed->GetOperationCodes(context);*/

	ByteOperandInstructionDescriptor descriptor("LDX", AddressingMode::Immediate, InstructionToken("44"));
	auto codes = descriptor.GetOperationCodes(context);

	/*MacroParser macroParser;
	auto canParseMacro = macroParser.CanParse("define Val $21");
	macroParser.Parse("define Val $21", macros);
*/
	auto preprocessed = macros.Replace("lda Val, $4");

	AssemblyModule module1(vector<string> {
			"define VAL $44",
			"",
			"  LDA VAL, X",
			"dum dum"
	});

	auto compiled1 = module1.Compile();

	AssemblyModule module2(vector<string> {
		"LDX #$08",
		"decrement:",
		"DEX",
		"STX $0200",
		"CPX #$03",
		"BNE decrement",
		"STX $0201",
		"BRK",
	});

	auto compiled2 = module2.Compile(0x600);

	return 0;
}