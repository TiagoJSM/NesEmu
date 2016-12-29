#pragma once

#pragma once

#include <gtest\gtest.h>

#include "../Assembler6502/AssemblyModule.h"
#include "../NesEmu/Emulator.h"

using namespace Assembler6502;
using namespace NesEmu;

namespace NesEmuTests {
	struct EmulationResult {
		vector<string> lines;
		CpuRegisters registers;
	};

	struct EmulatorTest : testing::Test, testing::WithParamInterface<EmulationResult> {
	};

	TEST_P(EmulatorTest, EmulatorRunTest) {
		auto param = GetParam();
		AssemblyModule module(param.lines);
		
		CpuRegisters registers;
		Memory memory(2 * KBYTE);
		MemoryMap memoryMap(memory);
		auto s = registers == registers;
		auto compilationResult = module.Compile(0x600);

		memory.Load(compilationResult.GetCompiledByteCode(), compilationResult.GetBaseAddress());
		registers.PC = compilationResult.GetBaseAddress();

		Emulator emulator(registers, memoryMap);
		emulator.RunTo(0x060d);
		EXPECT_TRUE(registers == param.registers);
	}
	INSTANTIATE_TEST_CASE_P(Default, EmulatorTest,
		testing::Values(
			EmulationResult{
		vector<string>{
			"LDX #$08",
			"decrement:",
			"DEX",
			"STX $0200",
			"CPX #$03",
			"BNE decrement",
			"STX $0201",
			"BRK",},
		CpuRegisters(
			0x00, //A
			0x03, //X
			0x00, //Y
			0x00, //S
			0b00000011, //P
			0x060d) //PC
		}
	));
}