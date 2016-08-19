#include "OPCodes.h"

#define CARRY_VALUE(registers) static_cast<uint8_t>((registers.Carry() ? 1 : 0))

uint16_t ZeroPage_Helper(NesEmu::Registers& registers, NesEmu::Memory& memory, uint16_t offset = 0) {
    auto operand = memory.GetByte(registers.PC + 1);
    return operand + offset;
}

uint16_t Absolute_Helper(NesEmu::Registers& registers, NesEmu::Memory& memory, uint16_t offset = 0) {
    auto operand = memory.GetWord(registers.PC + 1);
    return operand + offset;
}

uint8_t LD_Immediate_Helper(NesEmu::Registers& registers, NesEmu::Memory& memory) {
	auto operand = static_cast<int8_t>(memory.GetByte(registers.PC + 1));
	registers.SetNegative(operand);
	registers.SetZero(operand);
	return static_cast<uint8_t>(operand);
}

uint8_t LD_Absolute_Helper(NesEmu::Registers& registers, NesEmu::Memory& memory, uint8_t registerValue = 0) {
	auto address = Absolute_Helper(registers, memory, registerValue);
	auto value = static_cast<int8_t>(memory.GetByte(address));
	registers.SetNegative(value);
	registers.SetZero(value);
	return static_cast<uint8_t>(value);
}

uint8_t LD_ZeroPage_Helper(NesEmu::Registers& registers, NesEmu::Memory& memory, uint8_t registerValue = 0) {
	auto address = ZeroPage_Helper(registers, memory, registerValue);
	auto value = static_cast<int8_t>(memory.GetByte(address));
	registers.A = value;
	registers.SetNegative(value);
	registers.SetZero(value);
	return static_cast<uint8_t>(value);
}

void ST_ZeroPage_Helper(NesEmu::Registers& registers, NesEmu::Memory& memory, uint8_t registerValue, uint16_t offset = 0) {
    auto address = ZeroPage_Helper(registers, memory, offset);
	memory.StoreByte(address, registerValue);
}

void ST_Absolute_Helper(NesEmu::Registers& registers, NesEmu::Memory& memory, uint8_t registerValue, uint16_t offset = 0) {
    auto address = Absolute_Helper(registers, memory, offset);
	memory.StoreByte(address, registerValue);
}

uint16_t GetIndirectXAddress(NesEmu::Registers& registers, NesEmu::Memory& memory) {
	auto operand = memory.GetByte(registers.PC + 1);
	auto address = operand + registers.X;
	auto indirectAddress = memory.GetWord(address);
	return indirectAddress;
}

uint16_t GetIndirectYAddress(NesEmu::Registers& registers, NesEmu::Memory& memory) {
	auto operand = memory.GetByte(registers.PC + 1);
	auto indirectAddress = memory.GetWord(operand) + registers.Y;
	return indirectAddress;
}

bool TestOverflow(uint8_t val1, uint8_t val2, uint8_t result) {
	auto val1Sign = static_cast<int8_t>(val1);
	auto val2Sign = static_cast<int8_t>(val2);
	auto resultSign = static_cast<int8_t>(result);

	if (val1Sign >= 0 && val2Sign >= 0 && resultSign < 0) {
		return true;
	}

	if (val1Sign < 0 && val2Sign < 0 && resultSign >= 0) {
		return true;
	}

	return false;
}

void ADC_Helper(NesEmu::Registers& registers, uint8_t operand) {
	auto result = registers.A + operand + CARRY_VALUE(registers);
	auto regA = registers.A;

	registers.A = result;

	if (registers.Decimal()) {
		registers.A = NesEmu::BcdToDec(registers.A);
	}

	registers.SetCarry(static_cast<int16_t>(result));
	registers.SetOverflow(TestOverflow(operand, regA, registers.A));
	registers.SetZero(static_cast<int8_t>(result));
	registers.SetNegative(static_cast<int8_t>(result));
}

void ADC_ZeroPage_Helper(NesEmu::Registers& registers, NesEmu::Memory& memory, uint8_t offset = 0) {
	auto address = ZeroPage_Helper(registers, memory, offset);
	auto value = memory.GetByte(address);
	ADC_Helper(registers, value);
}

void ADC_Absolute_Helper(NesEmu::Registers& registers, NesEmu::Memory& memory, uint8_t offset = 0) {
    auto address = Absolute_Helper(registers, memory, offset);
	auto value = memory.GetByte(address);
	ADC_Helper(registers, value);
}

void AND_Helper(NesEmu::Registers& registers, uint8_t operand) {
	registers.A = registers.A & operand;

	registers.SetZero(static_cast<int8_t>(registers.A));
	registers.SetNegative(static_cast<int8_t>(registers.A));
}

void AND_ZeroPage_Helper(NesEmu::Registers& registers, NesEmu::Memory& memory, uint8_t offset = 0) {
    auto address = ZeroPage_Helper(registers, memory, offset);
	auto value = memory.GetByte(address);
	AND_Helper(registers, value);
}

void AND_Absolute_Helper(NesEmu::Registers& registers, NesEmu::Memory& memory, uint8_t offset = 0) {
    auto address = Absolute_Helper(registers, memory, offset);
	auto value = memory.GetByte(address);
	AND_Helper(registers, value);
}


void EOR_Helper(NesEmu::Registers& registers, uint8_t operand) {
    registers.A = registers.A | operand;

    registers.SetZero(static_cast<int8_t>(registers.A));
    registers.SetNegative(static_cast<int8_t>(registers.A));
}

void EOR_ZeroPage_Helper(NesEmu::Registers& registers, NesEmu::Memory& memory, uint8_t offset = 0) {
    auto address = ZeroPage_Helper(registers, memory, offset);
    auto value = memory.GetByte(address);
    EOR_Helper(registers, value);
}

void EOR_Absolute_Helper(NesEmu::Registers& registers, NesEmu::Memory& memory, uint8_t offset = 0) {
    auto address = Absolute_Helper(registers, memory, offset);
    auto value = memory.GetByte(address);
    EOR_Helper(registers, value);
}

void DEC_ZeroPage_Helper(NesEmu::Registers& registers, NesEmu::Memory& memory, uint8_t offset = 0) {
    auto address = ZeroPage_Helper(registers, memory, offset);
    auto data = memory.GetByte(address);
    data--;
    registers.SetZero(static_cast<int8_t>(data));
    registers.SetNegative(static_cast<int8_t>(data));
    memory.StoreByte(address, data);
}

void DEC_Absolute_Helper(NesEmu::Registers& registers, NesEmu::Memory& memory, uint8_t offset = 0) {
    auto address = Absolute_Helper(registers, memory, offset);
    auto data = memory.GetByte(address);
    data--;
    registers.SetZero(static_cast<int8_t>(data));
    registers.SetNegative(static_cast<int8_t>(data));
    memory.StoreByte(address, data);
}

uint8_t ASL_Helper(uint8_t value, bool& carry) {
    carry = (value & BIT_7_MASK) != 0;
    return value << 1;
}

uint8_t LSR_Helper(uint8_t value, bool& carry) {
	carry = (value & BIT_0_MASK) != 0;
	return value >> 1;
}

void ASL_ZeroPage_Helper(NesEmu::Registers& registers, NesEmu::Memory& memory, uint8_t offset = 0) {
    bool carry;
    auto address = ZeroPage_Helper(registers, memory, offset);
    auto value = memory.GetByte(address);
    value = ASL_Helper(value, carry);
    memory.StoreByte(address, value);
    registers.SetZero(static_cast<int8_t>(value));
    registers.SetNegative(static_cast<int8_t>(value));
    registers.SetCarry(carry);
}

void ASL_Absolute_Helper(NesEmu::Registers& registers, NesEmu::Memory& memory, uint8_t offset = 0) {
    bool carry;
    auto address = Absolute_Helper(registers, memory, offset);
    auto value = memory.GetByte(address);
    value = ASL_Helper(value, carry);
    memory.StoreByte(address, value);
    registers.SetZero(static_cast<int8_t>(value));
    registers.SetNegative(static_cast<int8_t>(value));
    registers.SetCarry(carry);
}

void LSR_ZeroPage_Helper(NesEmu::Registers& registers, NesEmu::Memory& memory, uint8_t offset = 0) {
	bool carry;
	auto address = ZeroPage_Helper(registers, memory, offset);
	auto value = memory.GetByte(address);
	value = LSR_Helper(value, carry);
	memory.StoreByte(address, value);
	registers.SetZero(static_cast<int8_t>(value));
	registers.SetNegative(static_cast<int8_t>(value));
	registers.SetCarry(carry);
}

void LSR_Absolute_Helper(NesEmu::Registers& registers, NesEmu::Memory& memory, uint8_t offset = 0) {
	bool carry;
	auto address = Absolute_Helper(registers, memory, offset);
	auto value = memory.GetByte(address);
	value = LSR_Helper(value, carry);
	memory.StoreByte(address, value);
	registers.SetZero(static_cast<int8_t>(value));
	registers.SetNegative(static_cast<int8_t>(value));
	registers.SetCarry(carry);
}

void CMP_Helper(NesEmu::Registers& registers, uint8_t registerValue, uint8_t operand) {
	registers.SetCarry(registerValue >= operand);
	registers.SetZero(registerValue == operand);
	registers.SetNegative(!registers.Carry());
}

void CMP_ZeroPage_Helper(NesEmu::Registers& registers, NesEmu::Memory& memory, uint8_t registerValue, uint8_t offset = 0) {
	auto address = ZeroPage_Helper(registers, memory, offset);
	auto value = memory.GetByte(address);
	CMP_Helper(registers, registerValue, value);
}

void CMP_Absolute_Helper(NesEmu::Registers& registers, NesEmu::Memory& memory, uint8_t registerValue, uint8_t offset = 0) {
	auto address = Absolute_Helper(registers, memory, offset);
	auto value = memory.GetByte(address);
	CMP_Helper(registers, registerValue, value);
}

void CMP_Indirect_X_Helper(NesEmu::Registers& registers, NesEmu::Memory& memory, uint8_t registerValue) {
	auto address = GetIndirectXAddress(registers, memory);
	auto value = memory.GetByte(address);
	CMP_Helper(registers, registerValue, value);
}

void CMP_Indirect_Y_Helper(NesEmu::Registers& registers, NesEmu::Memory& memory, uint8_t registerValue) {
	auto address = GetIndirectYAddress(registers, memory);
	auto value = memory.GetByte(address);
	CMP_Helper(registers, registerValue, value);
}

// END HELPERS

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
	auto value = static_cast<int8_t>(memory.GetByte(indirectAddress));
	registers.A = value;
	registers.SetNegative(value);
	registers.SetZero(value);
}

void NesEmu::LDA_Indirect_Y(Registers& registers, Memory& memory) {
	auto indirectAddress = GetIndirectYAddress(registers, memory);
	auto value = static_cast<int8_t>(memory.GetByte(indirectAddress));
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

void NesEmu::ADC_Immediate(Registers& registers, Memory& memory) {
	auto operand = memory.GetByte(registers.PC + 1);
	ADC_Helper(registers, operand);
}

void NesEmu::ADC_ZeroPage(Registers& registers, Memory& memory) {
	ADC_ZeroPage_Helper(registers, memory);
}

void NesEmu::ADC_ZeroPage_X(Registers& registers, Memory& memory) {
	ADC_ZeroPage_Helper(registers, memory, registers.X);
}

void NesEmu::ADC_Absolute(Registers& registers, Memory& memory) {
	ADC_Absolute_Helper(registers, memory);
}

void NesEmu::ADC_Absolute_X(Registers& registers, Memory& memory) {
	ADC_Absolute_Helper(registers, memory, registers.X);
}

void NesEmu::ADC_Absolute_Y(Registers& registers, Memory& memory) {
	ADC_Absolute_Helper(registers, memory, registers.Y);
}

void NesEmu::ADC_Indirect_X(Registers& registers, Memory& memory) {
	auto address = GetIndirectXAddress(registers, memory);
	auto value = memory.GetByte(address);
	ADC_Helper(registers, value);
}

void NesEmu::ADC_Indirect_Y(Registers& registers, Memory& memory) {
	auto address = GetIndirectYAddress(registers, memory);
	auto value = memory.GetByte(address);
	ADC_Helper(registers, value);
}

void NesEmu::AND_Immediate(Registers& registers, Memory& memory) {
	auto operand = memory.GetByte(registers.PC + 1);
	AND_Helper(registers, operand);
}

void NesEmu::AND_ZeroPage(Registers& registers, Memory& memory) {
	AND_ZeroPage_Helper(registers, memory);
}

void NesEmu::AND_ZeroPage_X(Registers& registers, Memory& memory) {
	AND_ZeroPage_Helper(registers, memory, registers.X);
}

void NesEmu::AND_Absolute(Registers& registers, Memory& memory) {
	AND_Absolute_Helper(registers, memory);
}

void NesEmu::AND_Absolute_X(Registers& registers, Memory& memory) {
	AND_Absolute_Helper(registers, memory, registers.X);
}

void NesEmu::AND_Absolute_Y(Registers& registers, Memory& memory) {
	AND_Absolute_Helper(registers, memory, registers.Y);
}

void NesEmu::AND_Indirect_X(Registers& registers, Memory& memory) {
	auto address = GetIndirectXAddress(registers, memory);
	auto value = memory.GetByte(address);
	AND_Helper(registers, value);
}

void NesEmu::AND_Indirect_Y(Registers& registers, Memory& memory) {
	auto address = GetIndirectYAddress(registers, memory);
	auto value = memory.GetByte(address);
	AND_Helper(registers, value);
}

void NesEmu::EOR_Immediate(Registers& registers, Memory& memory) {
    auto operand = memory.GetByte(registers.PC + 1);
    EOR_Helper(registers, operand);
}

void NesEmu::EOR_ZeroPage(Registers& registers, Memory& memory) {
    EOR_ZeroPage_Helper(registers, memory);
}

void NesEmu::EOR_ZeroPage_X(Registers& registers, Memory& memory) {
    EOR_ZeroPage_Helper(registers, memory, registers.X);
}

void NesEmu::EOR_Absolute(Registers& registers, Memory& memory) {
    EOR_Absolute_Helper(registers, memory);
}

void NesEmu::EOR_Absolute_X(Registers& registers, Memory& memory) {
    EOR_Absolute_Helper(registers, memory, registers.X);
}

void NesEmu::EOR_Absolute_Y(Registers& registers, Memory& memory) {
    EOR_Absolute_Helper(registers, memory, registers.Y);
}

void NesEmu::EOR_Indirect_X(Registers& registers, Memory& memory) {
    auto address = GetIndirectXAddress(registers, memory);
    auto value = memory.GetByte(address);
    EOR_Helper(registers, value);
}

void NesEmu::EOR_Indirect_Y(Registers& registers, Memory& memory) {
    auto address = GetIndirectYAddress(registers, memory);
    auto value = memory.GetByte(address);
    EOR_Helper(registers, value);
}

void NesEmu::DEC_ZeroPage(Registers& registers, Memory& memory) {
    DEC_ZeroPage_Helper(registers, memory);
}

void NesEmu::DEC_ZeroPage_X(Registers& registers, Memory& memory) {
    DEC_ZeroPage_Helper(registers, memory, registers.X);
}

void NesEmu::DEC_Absolute(Registers& registers, Memory& memory) {
    DEC_Absolute_Helper(registers, memory);
}

void NesEmu::DEC_Absolute_X(Registers& registers, Memory& memory) {
    DEC_Absolute_Helper(registers, memory, registers.X);
}

void NesEmu::ASL_Accumulator(Registers& registers, Memory& memory) {
    bool carry;
    registers.A = ASL_Helper(registers.A, carry);
    registers.SetZero(static_cast<int8_t>(registers.A));
    registers.SetNegative(static_cast<int8_t>(registers.A));
    registers.SetCarry(carry);
}

void NesEmu::ASL_ZeroPage(Registers& registers, Memory& memory) {
    ASL_ZeroPage_Helper(registers, memory);
}

void NesEmu::ASL_ZeroPage_X(Registers& registers, Memory& memory) {
    ASL_ZeroPage_Helper(registers, memory, registers.X);
}

void NesEmu::ASL_Absolute(Registers& registers, Memory& memory) {
    ASL_Absolute_Helper(registers, memory);
}

void NesEmu::ASL_Absolute_X(Registers& registers, Memory& memory) {
    ASL_Absolute_Helper(registers, memory, registers.X);
}

void NesEmu::LSR_Accumulator(Registers& registers, Memory& memory) {
	bool carry;
	registers.A = LSR_Helper(registers.A, carry);
	registers.SetZero(static_cast<int8_t>(registers.A));
	registers.SetNegative(static_cast<int8_t>(registers.A));
	registers.SetCarry(carry);
}

void NesEmu::LSR_ZeroPage(Registers& registers, Memory& memory) {
	LSR_ZeroPage_Helper(registers, memory);
}

void NesEmu::LSR_ZeroPage_X(Registers& registers, Memory& memory) {
	LSR_ZeroPage_Helper(registers, memory, registers.X);
}

void NesEmu::LSR_Absolute(Registers& registers, Memory& memory) {
	LSR_Absolute_Helper(registers, memory);
}

void NesEmu::LSR_Absolute_X(Registers& registers, Memory& memory) {
	LSR_Absolute_Helper(registers, memory, registers.X);
}

void NesEmu::CLC(Registers& registers, Memory& memory) {
	registers.SetCarry(false);
}

void NesEmu::SEC(Registers& registers, Memory& memory) {
	registers.SetCarry(true);
}

void NesEmu::CLI(Registers& registers, Memory& memory) {
	registers.SetInterrupt(false);
}

void NesEmu::SEI(Registers& registers, Memory& memory) {
	registers.SetInterrupt(true);
}

void NesEmu::CLD(Registers& registers, Memory& memory) {
	registers.SetDecimal(false);
}

void NesEmu::CLV(Registers& registers, Memory& memory) {
	registers.SetOverflow(false);
}

void NesEmu::SED(Registers& registers, Memory& memory) {
	registers.SetDecimal(true);
}

void NesEmu::CMP_Immediate(Registers& registers, Memory& memory) {
	auto operand = memory.GetByte(registers.PC + 1);
	CMP_Helper(registers, registers.A, operand);
}

void NesEmu::CMP_ZeroPage(Registers& registers, Memory& memory) {
	CMP_ZeroPage_Helper(registers, memory, registers.A);
}

void NesEmu::CMP_ZeroPage_X(Registers& registers, Memory& memory) {
	CMP_ZeroPage_Helper(registers, memory, registers.A, registers.X);
}

void NesEmu::CMP_Absolute(Registers& registers, Memory& memory) {
	CMP_Absolute_Helper(registers, memory, registers.A);
}

void NesEmu::CMP_Absolute_X(Registers& registers, Memory& memory) {
	CMP_Absolute_Helper(registers, memory, registers.A, registers.X);
}

void NesEmu::CMP_Absolute_Y(Registers& registers, Memory& memory) {
	CMP_Absolute_Helper(registers, memory, registers.A, registers.Y);
}

void NesEmu::CMP_Indirect_X(Registers& registers, Memory& memory) {
	CMP_Indirect_X_Helper(registers, memory, registers.A);
}

void NesEmu::CMP_Indirect_Y(Registers& registers, Memory& memory) {
	CMP_Indirect_Y_Helper(registers, memory, registers.A);
}

void NesEmu::CPX_Immediate(Registers& registers, Memory& memory) {
	auto operand = memory.GetByte(registers.PC + 1);
	CMP_Helper(registers, registers.X, operand);
}

void NesEmu::CPX_ZeroPage(Registers& registers, Memory& memory) {
	CMP_Absolute_Helper(registers, memory, registers.X);
}

void NesEmu::CPX_Absolute(Registers& registers, Memory& memory) {
	CMP_Absolute_Helper(registers, memory, registers.X);
}

void NesEmu::CPY_Immediate(Registers& registers, Memory& memory) {
	auto operand = memory.GetByte(registers.PC + 1);
	CMP_Helper(registers, registers.Y, operand);
}

void NesEmu::CPY_ZeroPage(Registers& registers, Memory& memory) {
	CMP_Absolute_Helper(registers, memory, registers.Y);
}

void NesEmu::CPY_Absolute(Registers& registers, Memory& memory) {
	CMP_Absolute_Helper(registers, memory, registers.Y);
}