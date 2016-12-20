#pragma once

#include <gtest\gtest.h>

#include "../Assembler6502/AssemblyModule.h"

using namespace Assembler6502;

namespace Assembler6502Tests {
	struct CompilationResult {
		vector<string> lines;
		vector<uint8_t> bytecode;
	};

	struct AssemblyModuleTest : testing::Test, testing::WithParamInterface<CompilationResult> {
	};

	TEST_P(AssemblyModuleTest, AssemblyModuleCompilation) {
		auto param = GetParam();
		AssemblyModule module(param.lines);
		EXPECT_EQ(module.Compile().GetCompiledByteCode(), param.bytecode);
	}
	INSTANTIATE_TEST_CASE_P(Default, AssemblyModuleTest,
		testing::Values(
			CompilationResult { 
			vector<string>{
				"LDX #$08",
				"decrement:",
				"DEX",
				"STX $0200",
				"CPX #$03",
				"BNE decrement",
				"STX $0201",
				"BRK",},
			vector<uint8_t>{0xa2, 0x08, 0xca, 0x8e, 0x00, 0x02, 0xe0, 0x03, 0xd0, 0xf8, 0x8e, 0x01, 0x02, 0x00 } }
	));
}