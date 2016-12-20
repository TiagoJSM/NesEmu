#pragma once

#include <gtest\gtest.h>
#include "../Assembler6502/ZeroPageYInstructionParser.h"
#include "../Assembler6502/ZeroPageXInstructionParser.h"
#include "../Assembler6502/IndirectYInstructionParser.h"
#include "../Assembler6502/ZeroPageInstructionParser.h"
#include "../Assembler6502/MacroParser.h"

using namespace Assembler6502;

namespace Assembler6502Tests {
	struct ParsingResult {
		string line;
		bool result;
	};
	template <typename TParser>
	struct ParserTest : testing::Test, testing::WithParamInterface<ParsingResult> {
		TParser parser;
	};

	struct ZeroPageYInstructionParserTest : public ParserTest<ZeroPageYInstructionParser> {};
	TEST_P(ZeroPageYInstructionParserTest, ZeroPageYParsing) {
		auto param = GetParam();
		EXPECT_EQ(param.result, parser.CanParse(param.line));
	}
	INSTANTIATE_TEST_CASE_P(Default, ZeroPageYInstructionParserTest,
		testing::Values(
			ParsingResult{ "lda $aa,y", true }
	));

	struct ZeroPageXInstructionParserTest : public ParserTest<ZeroPageXInstructionParser> {};
	TEST_P(ZeroPageXInstructionParserTest, ZeroPageXParsing) {
		auto param = GetParam();
		EXPECT_EQ(param.result, parser.CanParse(param.line));
	}
	INSTANTIATE_TEST_CASE_P(Default, ZeroPageXInstructionParserTest,
		testing::Values(
			ParsingResult{ "lda $aa,x", true }
	));

	struct IndirectYInstructionParserTest : public ParserTest<IndirectYInstructionParser> {};
	TEST_P(IndirectYInstructionParserTest, IndirectYIParsing) {
		auto param = GetParam();
		EXPECT_EQ(param.result, parser.CanParse(param.line));
	}
	INSTANTIATE_TEST_CASE_P(Default, IndirectYInstructionParserTest,
		testing::Values(
			ParsingResult{ "EOR ($44),Y", true }
	));

	struct ZeroPageInstructionParserTest : public ParserTest<ZeroPageInstructionParser> {};
	TEST_P(ZeroPageInstructionParserTest, ZeroPageParsing) {
		auto param = GetParam();
		EXPECT_EQ(param.result, parser.CanParse(param.line));
	}
	INSTANTIATE_TEST_CASE_P(Default, ZeroPageInstructionParserTest,
		testing::Values(
			ParsingResult{ "EOR $44", true }
	));

	struct MacroParserTest : public ParserTest<MacroParser> {};
	TEST_P(MacroParserTest, MacroParsing) {
		auto param = GetParam();
		EXPECT_EQ(param.result, parser.CanParse(param.line));
	}
	INSTANTIATE_TEST_CASE_P(Default, MacroParserTest,
		testing::Values(
			ParsingResult{ "define Val $21", true }
	));
}