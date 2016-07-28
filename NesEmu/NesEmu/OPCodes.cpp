#include "OPCodes.h"

void NesEmu::LDA_Immediate(Registers& registers, Memory& memory) {
	auto operand = static_cast<char>(memory.GetByte(registers.PC + 1));
	registers.A = operand;
	registers.SetNegative(operand);
	registers.SetZero(operand);
}

void NesEmu::LDA_ZeroPage(Registers& registers, Memory& memory) {
	auto operand = memory.GetByte(registers.PC + 1);
	auto value = static_cast<char>(memory.GetByte(operand));
	registers.A = value;
	registers.SetNegative(value);
	registers.SetZero(value);
}

void NesEmu::LDA_ZeroPage_X(Registers& registers, Memory& memory) {
	auto operand = memory.GetByte(registers.PC + 1);
	auto value = static_cast<char>(memory.GetByte(operand)) + registers.X;
	registers.A = value;
	registers.SetNegative(value);
	registers.SetZero(value);
}

void NesEmu::LDA_Absolute(Registers& registers, Memory& memory) {
	auto operand = memory.GetWord(registers.PC + 1);
	auto value = static_cast<char>(memory.GetByte(operand));
	registers.A = value;
	registers.SetNegative(value);
	registers.SetZero(value);
}

void NesEmu::LDA_Indirect_X(Registers& registers, Memory& memory) {
	auto operand = memory.GetByte(registers.PC + 1);
	auto address = operand + registers.X;
	auto indirectAddress = memory.GetWord(address);
	auto value = static_cast<char>(memory.GetByte(indirectAddress));
	registers.A = value;
	registers.SetNegative(value);
	registers.SetZero(value);
}

void NesEmu::LDA_Indirect_Y(Registers& registers, Memory& memory) {
	auto operand = memory.GetByte(registers.PC + 1);
	auto indirectAddress = memory.GetWord(operand) + registers.Y;
	auto value = static_cast<char>(memory.GetByte(indirectAddress));
	registers.A = value;
	registers.SetNegative(value);
	registers.SetZero(value);
}