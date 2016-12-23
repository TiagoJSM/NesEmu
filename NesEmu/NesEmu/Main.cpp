#include "CpuRegisters.h"
#include "Memory.h"
#include "OPCodes.h"
#include "MemoryMap.h"

//namespace NesEmu {
	int main() {
		NesEmu::CpuRegisters registers;
		NesEmu::Memory memory;
		NesEmu::MemoryMap memoryMap(memory);

		memory.data[1] = -1;
		registers.PC = 0;

		NesEmu::LDA_Immediate(registers, memoryMap);

		return 0;
	}
//}