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

void ST_ZeroPage_Helper(NesEmu::Registers& registers, NesEmu::Memory& memory, unsigned char registerValue, unsigned short offset = 0) {
	auto operand = memory.GetByte(registers.PC + 1);
	memory.StoreByte(operand + offset, registerValue);
}

void ST_Absolute_Helper(NesEmu::Registers& registers, NesEmu::Memory& memory, unsigned char registerValue, unsigned short offset = 0) {
	auto operand = memory.GetWord(registers.PC + 1);
	memory.StoreByte(operand + offset, registerValue);
}

unsigned short GetIndirectXAddress(NesEmu::Registers& registers, NesEmu::Memory& memory) {
	auto operand = memory.GetByte(registers.PC + 1);
	auto address = operand + registers.X;
	auto indirectAddress = memory.GetWord(address);
	return indirectAddress;
}

unsigned short GetIndirectYAddress(NesEmu::Registers& registers, NesEmu::Memory& memory) {
	auto operand = memory.GetByte(registers.PC + 1);
	auto indirectAddress = memory.GetWord(operand) + registers.Y;
	return indirectAddress;
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
	auto indirectAddress = GetIndirectXAddress(registers, memory);
	auto value = static_cast<char>(memory.GetByte(indirectAddress));
	registers.A = value;
	registers.SetNegative(value);
	registers.SetZero(value);
}

void NesEmu::LDA_Indirect_Y(Registers& registers, Memory& memory) {
	auto indirectAddress = GetIndirectYAddress(registers, memory);
	auto value = static_cast<char>(memory.GetByte(indirectAddress));
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

void NesEmu::STA_ZeroPage(Registers& registers, Memory& memory) {
	ST_ZeroPage_Helper(registers, memory, registers.A);
}

void NesEmu::STA_ZeroPage_X(Registers& registers, Memory& memory) {
	ST_ZeroPage_Helper(registers, memory, registers.A, registers.X);
}

void NesEmu::STA_Absolute(Registers& registers, Memory& memory) {
	ST_Absolute_Helper(registers, memory, registers.A);
}

void NesEmu::STA_Absolute_X(Registers& registers, Memory& memory) {
	ST_Absolute_Helper(registers, memory, registers.A, registers.X);
}

void NesEmu::STA_Absolute_Y(Registers& registers, Memory& memory) {
	ST_Absolute_Helper(registers, memory, registers.A, registers.Y);
}

void NesEmu::STA_Indirect_X(Registers& registers, Memory& memory) {
	auto indirectAddress = GetIndirectXAddress(registers, memory);
	memory.StoreByte(indirectAddress, registers.A);
}

void NesEmu::STA_Indirect_Y(Registers& registers, Memory& memory) {
	auto indirectAddress = GetIndirectYAddress(registers, memory);
	memory.StoreByte(indirectAddress, registers.A);
}

void NesEmu::STX_ZeroPage(Registers& registers, Memory& memory) {
	ST_ZeroPage_Helper(registers, memory, registers.X);
}

void NesEmu::STX_ZeroPage_Y(Registers& registers, Memory& memory) {
	ST_ZeroPage_Helper(registers, memory, registers.X, registers.Y);
}

void NesEmu::STX_Absolute(Registers& registers, Memory& memory) {
	ST_Absolute_Helper(registers, memory, registers.X);
}

void NesEmu::STY_ZeroPage(Registers& registers, Memory& memory) {
	ST_ZeroPage_Helper(registers, memory, registers.Y);
}

void NesEmu::STY_ZeroPage_X(Registers& registers, Memory& memory) {
	ST_ZeroPage_Helper(registers, memory, registers.Y, registers.X);
}

void NesEmu::STY_Absolute(Registers& registers, Memory& memory) {
	ST_Absolute_Helper(registers, memory, registers.X);
}