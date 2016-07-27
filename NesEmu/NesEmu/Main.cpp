#include "Registers.h"
#include "Memory.h"
#include "OPCodes.h"

//namespace NesEmu {
	int main() {
		NesEmu::Registers registers;
		NesEmu::Memory memory;

		registers.PC = 0;
		memory.data[1] = -1;

		NesEmu::LDA_Immediate(registers, memory);
		return 0;
	}
//}