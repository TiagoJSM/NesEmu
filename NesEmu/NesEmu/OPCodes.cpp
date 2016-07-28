#include "OPCodes.h"

unsigned char LD_Immediate_Helper(NesEmu::Registers& registers, NesEmu::Memory& memory) {
	auto operand = static_cast<char>(memory.GetByte(registers.PC + 1));
	registers.SetNegative(operand);
	registers.SetZero(operand);
	return static_cast<unsigned char>(operand);
}

unsigned char LD_Absolute_Helper(NesEmu::Registers& registers, NesEmu::Memory& memory, unsigned char registerValue = 0) {
	auto operand = memory.GetWord(registers.PC + 1);
	auto address = operand + registerValue;
	auto value = static_cast<char>(memory.GetByte(address));
	registers.SetNegative(value);
	registers.SetZero(value);
	return static_cast<unsigned char>(value);
}

unsigned char LD_ZeroPage_Helper(NesEmu::Registers& registers, NesEmu::Memory& memory, unsigned char registerValue = 0) {
	auto operand = memory.GetByte(registers.PC + 1);
	auto value = static_cast<char>(memory.GetByte(operand)) + registerValue;
	registers.A = value;
	registers.SetNegative(value);
	registers.SetZero(value);
	return static_cast<unsigned char>(value);
}



void NesEmu::LDA_Immediate(Registers& registers, Memory& memory) {
	registers.A = LD_Immediate_Helper(registers, memory);
}

void NesEmu::LDA_ZeroPage(Registers& registers, Memory& memory) {
	registers.A = LD_ZeroPage_Helper(registers, memory);
}

void NesEmu::LDA_ZeroPage_X(Registers& registers, Memory& memory) {
	registers.A = LD_ZeroPage_Helper(registers, memory, registers.X);
}

void NesEmu::LDA_Absolute(Registers& registers, Memory& memory) {
	registers.A = LD_Absolute_Helper(registers, memory);
}

void NesEmu::LDA_Absolute_X(Registers& registers, Memory& memory) {
	registers.A = LD_Absolute_Helper(registers, memory, registers.X);
}

void NesEmu::LDA_Absolute_Y(Registers& registers, Memory& memory) {
	registers.A = LD_Absolute_Helper(registers, memory, registers.Y);
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
	auto address = memory.GetWord(operand) + registers.Y;
	auto value = static_cast<char>(memory.GetByte(address));
	registers.A = value;
	registers.SetNegative(value);
	registers.SetZero(value);
}

void NesEmu::LDX_Immediate(Registers& registers, Memory& memory) {
	registers.X = LD_Immediate_Helper(registers, memory);
}

void NesEmu::LDX_ZeroPage(Registers& registers, Memory& memory) {
	registers.X = LD_ZeroPage_Helper(registers, memory);
}

void NesEmu::LDX_ZeroPage_Y(Registers& registers, Memory& memory) {
	registers.X = LD_ZeroPage_Helper(registers, memory, registers.Y);
}

void NesEmu::LDX_Absolute(Registers& registers, Memory& memory) {
	registers.X = LD_Absolute_Helper(registers, memory);
}

void NesEmu::LDX_Absolute_Y(Registers& registers, Memory& memory) {
	registers.X = LD_Absolute_Helper(registers, memory, registers.Y);
}

void NesEmu::LDY_Immediate(Registers& registers, Memory& memory) {
	registers.Y = LD_Immediate_Helper(registers, memory);
}

void NesEmu::LDY_ZeroPage(Registers& registers, Memory& memory) {
	registers.Y = LD_ZeroPage_Helper(registers, memory);
}

void NesEmu::LDY_ZeroPage_X(Registers& registers, Memory& memory) {
	registers.Y = LD_ZeroPage_Helper(registers, memory, registers.X);
}

void NesEmu::LDY_Absolute(Registers& registers, Memory& memory) {
	registers.Y = LD_Absolute_Helper(registers, memory);
}

void NesEmu::LDY_Absolute_X(Registers& registers, Memory& memory) {
	registers.Y = LD_Absolute_Helper(registers, memory, registers.X);
}