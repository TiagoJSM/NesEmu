#pragma once

#include "Registers.h"
#include "Memory.h"
#include "OPCodes.h"
#include "MemoryMap.h"
#include "Decoder.h"

namespace NesEmu {
	class Emulator {
	public:
		Emulator(Registers& registers, MemoryMap& memoryMap);

		void RunTo(uint16_t targetProgramCounter);
		void Step();
	private:
		Registers& _registers;
		MemoryMap& _memoryMap;

		void RunSingleInstruction();
	};
}