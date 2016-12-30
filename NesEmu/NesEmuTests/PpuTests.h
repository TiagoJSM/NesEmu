#pragma once

#pragma once

#include <gtest\gtest.h>

#include "../NesEmu/PpuRegisters.h"
#include "../NesEmu/PpuMemoryResourceMapping.h"

using namespace NesEmu;

namespace NesEmuTests {
	struct PpuMemoryResult {
	};

	struct PpuOAMDMATest : testing::Test, testing::WithParamInterface<PpuMemoryResult> {
	};

	TEST_P(PpuOAMDMATest, PPU_Tests) {
		auto param = GetParam();
		Memory cpuMemory(2 * KBYTE);
		Memory ppuMemory(16 * KBYTE);

		fill(cpuMemory.data.begin(), cpuMemory.data.end(), 0);
		fill(cpuMemory.data.begin(), cpuMemory.data.begin() + 128, 1);
		fill(ppuMemory.data.begin(), ppuMemory.data.end(), 0);

		CpuMemoryResourceMapping cpuMapping(cpuMemory);
		PpuMemoryResourceMapping ppuMapping(ppuMemory);

		PpuRegisters ppuRegisters;
		ppuRegisters.OAMADDR = 0x00;
		ppuRegisters.SetOAMDMA(0, ppuMapping, cpuMapping);
		for (auto idx = 0; idx < 256; idx++) {
			EXPECT_TRUE(cpuMemory.data[idx] == ppuMemory.data[idx]);
		}
	}
	INSTANTIATE_TEST_CASE_P(Default, PpuOAMDMATest,
		testing::Values(
			PpuMemoryResult{})
	);
}