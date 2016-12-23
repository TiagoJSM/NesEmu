#include "Emulator.h"

namespace NesEmu {
	Emulator::Emulator(CpuRegisters& registers, MemoryMap& memoryMap)
		: _registers(registers), _memoryMap(memoryMap) {}

	void Emulator::RunTo(uint16_t targetProgramCounter) {
		while (_registers.PC != targetProgramCounter) {
			RunSingleInstruction();
		}
	}

	void Emulator::Step() {
		RunSingleInstruction();
	}

	void Emulator::RunSingleInstruction() {
		auto instruction = Decode(_memoryMap.GetByte(_registers.PC));
		_registers.PC++;
		instruction(_registers, _memoryMap);
	}
}