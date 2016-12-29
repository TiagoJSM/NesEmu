#pragma once

#pragma once

#include <gtest\gtest.h>

#include "../NesEmu/PpuRegisters.h"

using namespace NesEmu;

namespace NesEmuTests {
	struct PpuMemoryResult {
	};

	struct PpuOAMDATATest : testing::Test, testing::WithParamInterface<PpuMemoryResult> {
	};

	TEST_P(PpuOAMDATATest, EmulatorRunTest) {
		auto param = GetParam();
		//Memory
		//EXPECT_TRUE(registers == param.registers);
	}
	INSTANTIATE_TEST_CASE_P(Default, PpuOAMDATATest,
		testing::Values(
			PpuMemoryResult{})
	));
}