#include "OPCodes.h"

void NesEmu::LDA_Immediate(Registers& registers, Memory& memory) {
	auto value = static_cast<char>(memory.data[registers.PC + 1]);
	registers.SetNegative(value);
	registers.SetZero(value);
}