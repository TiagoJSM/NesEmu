#pragma once

#include <gtest\gtest.h>
#include "../Assembler6502/ZeroPageYInstructionParser.h"

using namespace Assembler6502;

namespace Assembler6502Tests {
	struct ParsingResult {
		string line;
		bool result;
	};
	struct ZeroPageYInstructionParserTest : testing::Test, testing::WithParamInterface<ParsingResult> {
		ZeroPageYInstructionParser parser;
	};

	TEST_P(ZeroPageYInstructionParserTest, ZeroPageYParsing) {
		auto param = GetParam();
		EXPECT_EQ(param.result, parser.CanParse(param.line));
	}

	INSTANTIATE_TEST_CASE_P(Default, ZeroPageYInstructionParserTest,
		testing::Values(
			ParsingResult{ "lda $aa,y", true }
	));
}