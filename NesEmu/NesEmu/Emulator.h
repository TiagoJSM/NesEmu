#pragma once

#include "CpuRegisters.h"
#include "Memory.h"
#include "OPCodes.h"
#include "MemoryMap.h"
#include "Decoder.h"

namespace NesEmu {
	class Emulator {
	public:
		Emulator(CpuRegisters& registers, MemoryMap& memoryMap);

		void RunTo(uint16_t targetProgramCounter);
		void Step();
	private:
		CpuRegisters& _registers;
		MemoryMap& _memoryMap;

		void RunSingleInstruction();
	};
}