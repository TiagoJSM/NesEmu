#include "OPCodes.h"

#define CARRY_VALUE(registers) static_cast<uint8_t>((registers.Carry() ? 1 : 0))
#define NOT_CARRY_VALUE(registers) static_cast<uint8_t>((registers.Carry() ? 0 : 1))

uint16_t ZeroPage_Helper(NesEmu::Registers& registers, NesEmu::MemoryMap& memoryMap, uint16_t offset = 0) {
    auto operand = memoryMap.GetByte(registers.PC + 1);
    return operand + offset;
}

uint16_t Absolute_Helper(NesEmu::Registers& registers, NesEmu::MemoryMap& memoryMap, uint16_t offset = 0) {
    auto operand = memoryMap.GetWord(registers.PC + 1);
    return operand + offset;
}

uint8_t LD_Immediate_Helper(NesEmu::Registers& registers, NesEmu::MemoryMap& memoryMap) {
	auto operand = static_cast<int8_t>(memoryMap.GetByte(registers.PC + 1));
	registers.SetNegative(operand);
	registers.SetZero(operand);
	return static_cast<uint8_t>(operand);
}

uint8_t LD_Absolute_Helper(NesEmu::Registers& registers, NesEmu::MemoryMap& memoryMap, uint8_t registerValue = 0) {
	auto address = Absolute_Helper(registers, memoryMap, registerValue);
	auto value = static_cast<int8_t>(memoryMap.GetByte(address));
	registers.SetNegative(value);
	registers.SetZero(value);
	return static_cast<uint8_t>(value);
}

uint8_t LD_ZeroPage_Helper(NesEmu::Registers& registers, NesEmu::MemoryMap& memoryMap, uint8_t registerValue = 0) {
	auto address = ZeroPage_Helper(registers, memoryMap, registerValue);
	auto value = static_cast<int8_t>(memoryMap.GetByte(address));
	registers.A = value;
	registers.SetNegative(value);
	registers.SetZero(value);
	return static_cast<uint8_t>(value);
}

void ST_ZeroPage_Helper(NesEmu::Registers& registers, NesEmu::MemoryMap& memoryMap, uint8_t registerValue, uint16_t offset = 0) {
    auto address = ZeroPage_Helper(registers, memoryMap, offset);
	memoryMap.StoreByte(address, registerValue);
}

void ST_Absolute_Helper(NesEmu::Registers& registers, NesEmu::MemoryMap& memoryMap, uint8_t registerValue, uint16_t offset = 0) {
    auto address = Absolute_Helper(registers, memoryMap, offset);
	memoryMap.StoreByte(address, registerValue);
}

uint16_t GetIndirectXAddress(NesEmu::Registers& registers, NesEmu::MemoryMap& memoryMap) {
	auto operand = memoryMap.GetByte(registers.PC + 1);
	auto address = operand + registers.X;
	auto indirectAddress = memoryMap.GetWord(address);
	return indirectAddress;
}

uint16_t GetIndirectYAddress(NesEmu::Registers& registers, NesEmu::MemoryMap& memoryMap) {
	auto operand = memoryMap.GetByte(registers.PC + 1);
	auto indirectAddress = memoryMap.GetWord(operand) + registers.Y;
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

void ADC_ZeroPage_Helper(NesEmu::Registers& registers, NesEmu::MemoryMap& memoryMap, uint8_t offset = 0) {
	auto address = ZeroPage_Helper(registers, memoryMap, offset);
	auto value = memoryMap.GetByte(address);
	ADC_Helper(registers, value);
}

void ADC_Absolute_Helper(NesEmu::Registers& registers, NesEmu::MemoryMap& memoryMap, uint8_t offset = 0) {
    auto address = Absolute_Helper(registers, memoryMap, offset);
	auto value = memoryMap.GetByte(address);
	ADC_Helper(registers, value);
}

void AND_Helper(NesEmu::Registers& registers, uint8_t operand) {
	registers.A = registers.A & operand;

	registers.SetZero(static_cast<int8_t>(registers.A));
	registers.SetNegative(static_cast<int8_t>(registers.A));
}

void AND_ZeroPage_Helper(NesEmu::Registers& registers, NesEmu::MemoryMap& memoryMap, uint8_t offset = 0) {
    auto address = ZeroPage_Helper(registers, memoryMap, offset);
	auto value = memoryMap.GetByte(address);
	AND_Helper(registers, value);
}

void AND_Absolute_Helper(NesEmu::Registers& registers, NesEmu::MemoryMap& memoryMap, uint8_t offset = 0) {
    auto address = Absolute_Helper(registers, memoryMap, offset);
	auto value = memoryMap.GetByte(address);
	AND_Helper(registers, value);
}

void EOR_Helper(NesEmu::Registers& registers, uint8_t operand) {
    registers.A = registers.A ^ operand;

    registers.SetZero(static_cast<int8_t>(registers.A));
    registers.SetNegative(static_cast<int8_t>(registers.A));
}

void EOR_ZeroPage_Helper(NesEmu::Registers& registers, NesEmu::MemoryMap& memoryMap, uint8_t offset = 0) {
    auto address = ZeroPage_Helper(registers, memoryMap, offset);
    auto value = memoryMap.GetByte(address);
    EOR_Helper(registers, value);
}

void EOR_Absolute_Helper(NesEmu::Registers& registers, NesEmu::MemoryMap& memoryMap, uint8_t offset = 0) {
    auto address = Absolute_Helper(registers, memoryMap, offset);
    auto value = memoryMap.GetByte(address);
    EOR_Helper(registers, value);
}

void DEC_ZeroPage_Helper(NesEmu::Registers& registers, NesEmu::MemoryMap& memoryMap, uint8_t offset = 0) {
    auto address = ZeroPage_Helper(registers, memoryMap, offset);
    auto data = memoryMap.GetByte(address);
    data--;
    registers.SetZero(static_cast<int8_t>(data));
    registers.SetNegative(static_cast<int8_t>(data));
    memoryMap.StoreByte(address, data);
}

void DEC_Absolute_Helper(NesEmu::Registers& registers, NesEmu::MemoryMap& memoryMap, uint8_t offset = 0) {
    auto address = Absolute_Helper(registers, memoryMap, offset);
    auto data = memoryMap.GetByte(address);
    data--;
    registers.SetZero(static_cast<int8_t>(data));
    registers.SetNegative(static_cast<int8_t>(data));
    memoryMap.StoreByte(address, data);
}

void INC_ZeroPage_Helper(NesEmu::Registers& registers, NesEmu::MemoryMap& memoryMap, uint8_t offset = 0) {
	auto address = ZeroPage_Helper(registers, memoryMap, offset);
	auto data = memoryMap.GetByte(address);
	data++;
	registers.SetZero(static_cast<int8_t>(data));
	registers.SetNegative(static_cast<int8_t>(data));
	memoryMap.StoreByte(address, data);
}

void INC_Absolute_Helper(NesEmu::Registers& registers, NesEmu::MemoryMap& memoryMap, uint8_t offset = 0) {
	auto address = Absolute_Helper(registers, memoryMap, offset);
	auto data = memoryMap.GetByte(address);
	data++;
	registers.SetZero(static_cast<int8_t>(data));
	registers.SetNegative(static_cast<int8_t>(data));
	memoryMap.StoreByte(address, data);
}

uint8_t ASL_Helper(uint8_t value, bool& carry) {
    carry = (value & BIT_7_MASK) != 0;
    return value << 1;
}

uint8_t LSR_Helper(uint8_t value, bool& carry) {
	carry = (value & BIT_0_MASK) != 0;
	return value >> 1;
}

void ASL_ZeroPage_Helper(NesEmu::Registers& registers, NesEmu::MemoryMap& memoryMap, uint8_t offset = 0) {
    bool carry;
    auto address = ZeroPage_Helper(registers, memoryMap, offset);
    auto value = memoryMap.GetByte(address);
    value = ASL_Helper(value, carry);
    memoryMap.StoreByte(address, value);
    registers.SetZero(static_cast<int8_t>(value));
    registers.SetNegative(static_cast<int8_t>(value));
    registers.SetCarry(carry);
}

void ASL_Absolute_Helper(NesEmu::Registers& registers, NesEmu::MemoryMap& memoryMap, uint8_t offset = 0) {
    bool carry;
    auto address = Absolute_Helper(registers, memoryMap, offset);
    auto value = memoryMap.GetByte(address);
    value = ASL_Helper(value, carry);
    memoryMap.StoreByte(address, value);
    registers.SetZero(static_cast<int8_t>(value));
    registers.SetNegative(static_cast<int8_t>(value));
    registers.SetCarry(carry);
}

void LSR_ZeroPage_Helper(NesEmu::Registers& registers, NesEmu::MemoryMap& memoryMap, uint8_t offset = 0) {
	bool carry;
	auto address = ZeroPage_Helper(registers, memoryMap, offset);
	auto value = memoryMap.GetByte(address);
	value = LSR_Helper(value, carry);
	memoryMap.StoreByte(address, value);
	registers.SetZero(static_cast<int8_t>(value));
	registers.SetNegative(static_cast<int8_t>(value));
	registers.SetCarry(carry);
}

void LSR_Absolute_Helper(NesEmu::Registers& registers, NesEmu::MemoryMap& memoryMap, uint8_t offset = 0) {
	bool carry;
	auto address = Absolute_Helper(registers, memoryMap, offset);
	auto value = memoryMap.GetByte(address);
	value = LSR_Helper(value, carry);
	memoryMap.StoreByte(address, value);
	registers.SetZero(static_cast<int8_t>(value));
	registers.SetNegative(static_cast<int8_t>(value));
	registers.SetCarry(carry);
}

void CMP_Helper(NesEmu::Registers& registers, uint8_t registerValue, uint8_t operand) {
	registers.SetCarry(registerValue >= operand);
	registers.SetZero(registerValue == operand);
	registers.SetNegative(!registers.Carry());
}

void CMP_ZeroPage_Helper(NesEmu::Registers& registers, NesEmu::MemoryMap& memoryMap, uint8_t registerValue, uint8_t offset = 0) {
	auto address = ZeroPage_Helper(registers, memoryMap, offset);
	auto value = memoryMap.GetByte(address);
	CMP_Helper(registers, registerValue, value);
}

void CMP_Absolute_Helper(NesEmu::Registers& registers, NesEmu::MemoryMap& memoryMap, uint8_t registerValue, uint8_t offset = 0) {
	auto address = Absolute_Helper(registers, memoryMap, offset);
	auto value = memoryMap.GetByte(address);
	CMP_Helper(registers, registerValue, value);
}

void CMP_Indirect_X_Helper(NesEmu::Registers& registers, NesEmu::MemoryMap& memoryMap, uint8_t registerValue) {
	auto address = GetIndirectXAddress(registers, memoryMap);
	auto value = memoryMap.GetByte(address);
	CMP_Helper(registers, registerValue, value);
}

void CMP_Indirect_Y_Helper(NesEmu::Registers& registers, NesEmu::MemoryMap& memoryMap, uint8_t registerValue) {
	auto address = GetIndirectYAddress(registers, memoryMap);
	auto value = memoryMap.GetByte(address);
	CMP_Helper(registers, registerValue, value);
}

void ORA_Helper(NesEmu::Registers& registers, uint8_t operand) {
	registers.A = registers.A | operand;

	registers.SetZero(static_cast<int8_t>(registers.A));
	registers.SetNegative(static_cast<int8_t>(registers.A));
}

void ORA_ZeroPage_Helper(NesEmu::Registers& registers, NesEmu::MemoryMap& memoryMap, uint8_t offset = 0) {
	auto address = ZeroPage_Helper(registers, memoryMap, offset);
	auto value = memoryMap.GetByte(address);
	ORA_Helper(registers, value);
}

void ORA_Absolute_Helper(NesEmu::Registers& registers, NesEmu::MemoryMap& memoryMap, uint8_t offset = 0) {
	auto address = Absolute_Helper(registers, memoryMap, offset);
	auto value = memoryMap.GetByte(address);
	ORA_Helper(registers, value);
}

void ROL_Helper(NesEmu::Registers& registers, uint8_t value) {
	auto carry = registers.Carry();
	auto bit7 = (value & BIT_7_MASK) != 0;
	auto result = (value << 1) & (carry << BIT_0_MASK);
	registers.SetCarry(bit7);
	registers.SetZero(result == 0);
	registers.SetNegative(static_cast<int8_t>(result));
	registers.A = result;
}

void ROL_ZeroPage_Helper(NesEmu::Registers& registers, NesEmu::MemoryMap& memoryMap, uint8_t offset = 0) {
	auto address = ZeroPage_Helper(registers, memoryMap, offset);
	auto value = memoryMap.GetByte(address);
	ROL_Helper(registers, value);
}

void ROL_Absolute_Helper(NesEmu::Registers& registers, NesEmu::MemoryMap& memoryMap, uint8_t offset = 0) {
	auto address = Absolute_Helper(registers, memoryMap, offset);
	auto value = memoryMap.GetByte(address);
	ROL_Helper(registers, value);
}

void ROR_Helper(NesEmu::Registers& registers, uint8_t value) {
	auto carry = registers.Carry();
	auto bit0 = (value & BIT_0_MASK) != 0;
	auto result = (value >> 1) & (carry << BIT_7_MASK);
	registers.SetCarry(bit0);
	registers.SetZero(result == 0);
	registers.SetNegative(static_cast<int8_t>(result));
	registers.A = result;
}

void ROR_ZeroPage_Helper(NesEmu::Registers& registers, NesEmu::MemoryMap& memoryMap, uint8_t offset = 0) {
	auto address = ZeroPage_Helper(registers, memoryMap, offset);
	auto value = memoryMap.GetByte(address);
	ROR_Helper(registers, value);
}

void ROR_Absolute_Helper(NesEmu::Registers& registers, NesEmu::MemoryMap& memoryMap, uint8_t offset = 0) {
	auto address = Absolute_Helper(registers, memoryMap, offset);
	auto value = memoryMap.GetByte(address);
	ROR_Helper(registers, value);
}

void SBC_Helper(NesEmu::Registers& registers, uint8_t operand) {
	auto result = registers.A - operand + NOT_CARRY_VALUE(registers);
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

void SBC_ZeroPage_Helper(NesEmu::Registers& registers, NesEmu::MemoryMap& memoryMap, uint8_t offset = 0) {
	auto address = ZeroPage_Helper(registers, memoryMap, offset);
	auto value = memoryMap.GetByte(address);
	SBC_Helper(registers, value);
}

void SBC_Absolute_Helper(NesEmu::Registers& registers, NesEmu::MemoryMap& memoryMap, uint8_t offset = 0) {
	auto address = Absolute_Helper(registers, memoryMap, offset);
	auto value = memoryMap.GetByte(address);
	SBC_Helper(registers, value);
}

void Transfer_Helper(NesEmu::Registers& registers, uint8_t registerValue) {
	auto value = static_cast<int8_t>(registerValue);
	registers.SetNegative(value);
	registers.SetZero(value);
}

void Branch_Helper(NesEmu::Registers& registers, NesEmu::MemoryMap& memoryMap, bool doBranch) {
	auto value = memoryMap.GetByte(registers.PC + 1);
	registers.PC -= value;
	registers.PC -= 2; //ToDo: investigate if this is correct
}

void BIT_Helper(NesEmu::Registers& registers, NesEmu::MemoryMap& memoryMap, uint8_t value) {
	registers.SetZero(static_cast<int8_t>(value & registers.A));
	registers.SetNegative(static_cast<int8_t>(value & BIT_7_MASK));
	registers.SetOverflow(static_cast<int8_t>(value & BIT_6_MASK));
}

void Push_Helper(NesEmu::Registers& registers, NesEmu::MemoryMap& memoryMap, uint8_t value) {
	memoryMap.StoreByte(registers.S, value);
	registers.S--;
}

void Push_Helper(NesEmu::Registers& registers, NesEmu::MemoryMap& memoryMap, uint16_t value) {
	memoryMap.StoreWord(registers.S, value);
	registers.S -= 2;
}

uint8_t Pull_Byte_Helper(NesEmu::Registers& registers, NesEmu::MemoryMap& memoryMap) {
	auto value = memoryMap.GetByte(registers.S);
	registers.S++;
	return value;
}

uint16_t Pull_Word_Helper(NesEmu::Registers& registers, NesEmu::MemoryMap& memoryMap) {
	auto value = memoryMap.GetWord(registers.S);
	registers.S += 2;
	return value;
}

// END HELPERS

void NesEmu::LDA_Immediate(Registers& registers, MemoryMap& memoryMap) {
	registers.A = LD_Immediate_Helper(registers, memoryMap);
}

void NesEmu::LDA_ZeroPage(Registers& registers, MemoryMap& memoryMap) {
	registers.A = LD_ZeroPage_Helper(registers, memoryMap);
}

void NesEmu::LDA_ZeroPage_X(Registers& registers, MemoryMap& memoryMap) {
	registers.A = LD_ZeroPage_Helper(registers, memoryMap, registers.X);
}

void NesEmu::LDA_Absolute(Registers& registers, MemoryMap& memoryMap) {
	registers.A = LD_Absolute_Helper(registers, memoryMap);
}

void NesEmu::LDA_Absolute_X(Registers& registers, MemoryMap& memoryMap) {
	registers.A = LD_Absolute_Helper(registers, memoryMap, registers.X);
}

void NesEmu::LDA_Absolute_Y(Registers& registers, MemoryMap& memoryMap) {
	registers.A = LD_Absolute_Helper(registers, memoryMap, registers.Y);
}

void NesEmu::LDA_Indirect_X(Registers& registers, MemoryMap& memoryMap) {
	auto indirectAddress = GetIndirectXAddress(registers, memoryMap);
	auto value = static_cast<int8_t>(memoryMap.GetByte(indirectAddress));
	registers.A = value;
	registers.SetNegative(value);
	registers.SetZero(value);
}

void NesEmu::LDA_Indirect_Y(Registers& registers, MemoryMap& memoryMap) {
	auto indirectAddress = GetIndirectYAddress(registers, memoryMap);
	auto value = static_cast<int8_t>(memoryMap.GetByte(indirectAddress));
	registers.A = value;
	registers.SetNegative(value);
	registers.SetZero(value);
}

void NesEmu::LDX_Immediate(Registers& registers, MemoryMap& memoryMap) {
	registers.X = LD_Immediate_Helper(registers, memoryMap);
}

void NesEmu::LDX_ZeroPage(Registers& registers, MemoryMap& memoryMap) {
	registers.X = LD_ZeroPage_Helper(registers, memoryMap);
}

void NesEmu::LDX_ZeroPage_Y(Registers& registers, MemoryMap& memoryMap) {
	registers.X = LD_ZeroPage_Helper(registers, memoryMap, registers.Y);
}

void NesEmu::LDX_Absolute(Registers& registers, MemoryMap& memoryMap) {
	registers.X = LD_Absolute_Helper(registers, memoryMap);
}

void NesEmu::LDX_Absolute_Y(Registers& registers, MemoryMap& memoryMap) {
	registers.X = LD_Absolute_Helper(registers, memoryMap, registers.Y);
}

void NesEmu::LDY_Immediate(Registers& registers, MemoryMap& memoryMap) {
	registers.Y = LD_Immediate_Helper(registers, memoryMap);
}

void NesEmu::LDY_ZeroPage(Registers& registers, MemoryMap& memoryMap) {
	registers.Y = LD_ZeroPage_Helper(registers, memoryMap);
}

void NesEmu::LDY_ZeroPage_X(Registers& registers, MemoryMap& memoryMap) {
	registers.Y = LD_ZeroPage_Helper(registers, memoryMap, registers.X);
}

void NesEmu::LDY_Absolute(Registers& registers, MemoryMap& memoryMap) {
	registers.Y = LD_Absolute_Helper(registers, memoryMap);
}

void NesEmu::LDY_Absolute_X(Registers& registers, MemoryMap& memoryMap) {
	registers.Y = LD_Absolute_Helper(registers, memoryMap, registers.X);
}

void NesEmu::STA_ZeroPage(Registers& registers, MemoryMap& memoryMap) {
	ST_ZeroPage_Helper(registers, memoryMap, registers.A);
}

void NesEmu::STA_ZeroPage_X(Registers& registers, MemoryMap& memoryMap) {
	ST_ZeroPage_Helper(registers, memoryMap, registers.A, registers.X);
}

void NesEmu::STA_Absolute(Registers& registers, MemoryMap& memoryMap) {
	ST_Absolute_Helper(registers, memoryMap, registers.A);
}

void NesEmu::STA_Absolute_X(Registers& registers, MemoryMap& memoryMap) {
	ST_Absolute_Helper(registers, memoryMap, registers.A, registers.X);
}

void NesEmu::STA_Absolute_Y(Registers& registers, MemoryMap& memoryMap) {
	ST_Absolute_Helper(registers, memoryMap, registers.A, registers.Y);
}

void NesEmu::STA_Indirect_X(Registers& registers, MemoryMap& memoryMap) {
	auto indirectAddress = GetIndirectXAddress(registers, memoryMap);
	memoryMap.StoreByte(indirectAddress, registers.A);
}

void NesEmu::STA_Indirect_Y(Registers& registers, MemoryMap& memoryMap) {
	auto indirectAddress = GetIndirectYAddress(registers, memoryMap);
	memoryMap.StoreByte(indirectAddress, registers.A);
}

void NesEmu::STX_ZeroPage(Registers& registers, MemoryMap& memoryMap) {
	ST_ZeroPage_Helper(registers, memoryMap, registers.X);
}

void NesEmu::STX_ZeroPage_Y(Registers& registers, MemoryMap& memoryMap) {
	ST_ZeroPage_Helper(registers, memoryMap, registers.X, registers.Y);
}

void NesEmu::STX_Absolute(Registers& registers, MemoryMap& memoryMap) {
	ST_Absolute_Helper(registers, memoryMap, registers.X);
}

void NesEmu::STY_ZeroPage(Registers& registers, MemoryMap& memoryMap) {
	ST_ZeroPage_Helper(registers, memoryMap, registers.Y);
}

void NesEmu::STY_ZeroPage_X(Registers& registers, MemoryMap& memoryMap) {
	ST_ZeroPage_Helper(registers, memoryMap, registers.Y, registers.X);
}

void NesEmu::STY_Absolute(Registers& registers, MemoryMap& memoryMap) {
	ST_Absolute_Helper(registers, memoryMap, registers.X);
}

void NesEmu::ADC_Immediate(Registers& registers, MemoryMap& memoryMap) {
	auto operand = memoryMap.GetByte(registers.PC + 1);
	ADC_Helper(registers, operand);
}

void NesEmu::ADC_ZeroPage(Registers& registers, MemoryMap& memoryMap) {
	ADC_ZeroPage_Helper(registers, memoryMap);
}

void NesEmu::ADC_ZeroPage_X(Registers& registers, MemoryMap& memoryMap) {
	ADC_ZeroPage_Helper(registers, memoryMap, registers.X);
}

void NesEmu::ADC_Absolute(Registers& registers, MemoryMap& memoryMap) {
	ADC_Absolute_Helper(registers, memoryMap);
}

void NesEmu::ADC_Absolute_X(Registers& registers, MemoryMap& memoryMap) {
	ADC_Absolute_Helper(registers, memoryMap, registers.X);
}

void NesEmu::ADC_Absolute_Y(Registers& registers, MemoryMap& memoryMap) {
	ADC_Absolute_Helper(registers, memoryMap, registers.Y);
}

void NesEmu::ADC_Indirect_X(Registers& registers, MemoryMap& memoryMap) {
	auto address = GetIndirectXAddress(registers, memoryMap);
	auto value = memoryMap.GetByte(address);
	ADC_Helper(registers, value);
}

void NesEmu::ADC_Indirect_Y(Registers& registers, MemoryMap& memoryMap) {
	auto address = GetIndirectYAddress(registers, memoryMap);
	auto value = memoryMap.GetByte(address);
	ADC_Helper(registers, value);
}

void NesEmu::AND_Immediate(Registers& registers, MemoryMap& memoryMap) {
	auto operand = memoryMap.GetByte(registers.PC + 1);
	AND_Helper(registers, operand);
}

void NesEmu::AND_ZeroPage(Registers& registers, MemoryMap& memoryMap) {
	AND_ZeroPage_Helper(registers, memoryMap);
}

void NesEmu::AND_ZeroPage_X(Registers& registers, MemoryMap& memoryMap) {
	AND_ZeroPage_Helper(registers, memoryMap, registers.X);
}

void NesEmu::AND_Absolute(Registers& registers, MemoryMap& memoryMap) {
	AND_Absolute_Helper(registers, memoryMap);
}

void NesEmu::AND_Absolute_X(Registers& registers, MemoryMap& memoryMap) {
	AND_Absolute_Helper(registers, memoryMap, registers.X);
}

void NesEmu::AND_Absolute_Y(Registers& registers, MemoryMap& memoryMap) {
	AND_Absolute_Helper(registers, memoryMap, registers.Y);
}

void NesEmu::AND_Indirect_X(Registers& registers, MemoryMap& memoryMap) {
	auto address = GetIndirectXAddress(registers, memoryMap);
	auto value = memoryMap.GetByte(address);
	AND_Helper(registers, value);
}

void NesEmu::AND_Indirect_Y(Registers& registers, MemoryMap& memoryMap) {
	auto address = GetIndirectYAddress(registers, memoryMap);
	auto value = memoryMap.GetByte(address);
	AND_Helper(registers, value);
}

void NesEmu::BCC(Registers& registers, MemoryMap& memoryMap) {
	Branch_Helper(registers, memoryMap, !registers.Carry());
}

void NesEmu::BCS(Registers& registers, MemoryMap& memoryMap) {
	Branch_Helper(registers, memoryMap, registers.Carry());
}

void NesEmu::BEQ(Registers& registers, MemoryMap& memoryMap) {
	Branch_Helper(registers, memoryMap, registers.Zero());
}

void NesEmu::BMI(Registers& registers, MemoryMap& memoryMap) {
	Branch_Helper(registers, memoryMap, registers.Negative());
}

void NesEmu::BNE(Registers& registers, MemoryMap& memoryMap) {
	Branch_Helper(registers, memoryMap, !registers.Zero());
}

void NesEmu::BPL(Registers& registers, MemoryMap& memoryMap) {
	Branch_Helper(registers, memoryMap, !registers.Negative() && !registers.Zero()); //ToDo: check this
}

void NesEmu::BVC(Registers& registers, MemoryMap& memoryMap) {
	Branch_Helper(registers, memoryMap, !registers.Overflow());
}

void NesEmu::BVS(Registers& registers, MemoryMap& memoryMap) {
	Branch_Helper(registers, memoryMap, registers.Overflow());
}

void NesEmu::BIT_ZeroPage(Registers& registers, MemoryMap& memoryMap) {
	auto address = ZeroPage_Helper(registers, memoryMap, 0);
	auto value = memoryMap.GetByte(address);
	BIT_Helper(registers, memoryMap, value);
}

void NesEmu::BIT_Absolute(Registers& registers, MemoryMap& memoryMap) {
	auto address = Absolute_Helper(registers, memoryMap, 0);
	auto value = memoryMap.GetByte(address);
	BIT_Helper(registers, memoryMap, value);
}

void NesEmu::EOR_Immediate(Registers& registers, MemoryMap& memoryMap) {
    auto operand = memoryMap.GetByte(registers.PC + 1);
    EOR_Helper(registers, operand);
}

void NesEmu::EOR_ZeroPage(Registers& registers, MemoryMap& memoryMap) {
    EOR_ZeroPage_Helper(registers, memoryMap);
}

void NesEmu::EOR_ZeroPage_X(Registers& registers, MemoryMap& memoryMap) {
    EOR_ZeroPage_Helper(registers, memoryMap, registers.X);
}

void NesEmu::EOR_Absolute(Registers& registers, MemoryMap& memoryMap) {
    EOR_Absolute_Helper(registers, memoryMap);
}

void NesEmu::EOR_Absolute_X(Registers& registers, MemoryMap& memoryMap) {
    EOR_Absolute_Helper(registers, memoryMap, registers.X);
}

void NesEmu::EOR_Absolute_Y(Registers& registers, MemoryMap& memoryMap) {
    EOR_Absolute_Helper(registers, memoryMap, registers.Y);
}

void NesEmu::EOR_Indirect_X(Registers& registers, MemoryMap& memoryMap) {
    auto address = GetIndirectXAddress(registers, memoryMap);
    auto value = memoryMap.GetByte(address);
    EOR_Helper(registers, value);
}

void NesEmu::EOR_Indirect_Y(Registers& registers, MemoryMap& memoryMap) {
    auto address = GetIndirectYAddress(registers, memoryMap);
    auto value = memoryMap.GetByte(address);
    EOR_Helper(registers, value);
}

void NesEmu::JMP_Absolute(Registers& registers, MemoryMap& memoryMap) {
	registers.PC = Absolute_Helper(registers, memoryMap, 0);
}

void NesEmu::JMP_Indirect(Registers& registers, MemoryMap& memoryMap) {
	auto indirectAddress = Absolute_Helper(registers, memoryMap, 0);
	registers.PC = memoryMap.GetWord(indirectAddress);
}

void NesEmu::JSR(Registers& registers, MemoryMap& memoryMap) {
	auto operand = memoryMap.GetWord(registers.PC + 1);
	uint16_t value = registers.PC + 2; //point to the address BEFORE the NEXT instruction
	Push_Helper(registers, memoryMap, value);
	registers.PC = operand;
}


void NesEmu::DEC_ZeroPage(Registers& registers, MemoryMap& memoryMap) {
    DEC_ZeroPage_Helper(registers, memoryMap);
}

void NesEmu::DEC_ZeroPage_X(Registers& registers, MemoryMap& memoryMap) {
    DEC_ZeroPage_Helper(registers, memoryMap, registers.X);
}

void NesEmu::DEC_Absolute(Registers& registers, MemoryMap& memoryMap) {
    DEC_Absolute_Helper(registers, memoryMap);
}

void NesEmu::DEC_Absolute_X(Registers& registers, MemoryMap& memoryMap) {
    DEC_Absolute_Helper(registers, memoryMap, registers.X);
}

void NesEmu::DEX(Registers& registers, MemoryMap& memoryMap) {
	registers.X--;
	registers.SetNegative(static_cast<int8_t>(registers.X));
	registers.SetZero(static_cast<int8_t>(registers.X));
}

void NesEmu::DEY(Registers& registers, MemoryMap& memoryMap) {
	registers.Y--;
	registers.SetNegative(static_cast<int8_t>(registers.Y));
	registers.SetZero(static_cast<int8_t>(registers.Y));
}

void NesEmu::INC_ZeroPage(Registers& registers, MemoryMap& memoryMap) {
	INC_ZeroPage_Helper(registers, memoryMap);
}

void NesEmu::INC_ZeroPage_X(Registers& registers, MemoryMap& memoryMap) {
	INC_ZeroPage_Helper(registers, memoryMap, registers.X);
}

void NesEmu::INC_Absolute(Registers& registers, MemoryMap& memoryMap) {
	INC_Absolute_Helper(registers, memoryMap);
}

void NesEmu::INC_Absolute_X(Registers& registers, MemoryMap& memoryMap) {
	INC_Absolute_Helper(registers, memoryMap, registers.X);
}

void  NesEmu::INX(Registers& registers, MemoryMap& memoryMap) {
	registers.X++;
	registers.SetNegative(static_cast<int8_t>(registers.X));
	registers.SetZero(static_cast<int8_t>(registers.X));
}

void  NesEmu::INY(Registers& registers, MemoryMap& memoryMap) {
	registers.Y++;
	registers.SetNegative(static_cast<int8_t>(registers.Y));
	registers.SetZero(static_cast<int8_t>(registers.Y));
}

void NesEmu::ASL_Accumulator(Registers& registers, MemoryMap& memoryMap) {
    bool carry;
    registers.A = ASL_Helper(registers.A, carry);
    registers.SetZero(static_cast<int8_t>(registers.A));
    registers.SetNegative(static_cast<int8_t>(registers.A));
    registers.SetCarry(carry);
}

void NesEmu::ASL_ZeroPage(Registers& registers, MemoryMap& memoryMap) {
    ASL_ZeroPage_Helper(registers, memoryMap);
}

void NesEmu::ASL_ZeroPage_X(Registers& registers, MemoryMap& memoryMap) {
    ASL_ZeroPage_Helper(registers, memoryMap, registers.X);
}

void NesEmu::ASL_Absolute(Registers& registers, MemoryMap& memoryMap) {
    ASL_Absolute_Helper(registers, memoryMap);
}

void NesEmu::ASL_Absolute_X(Registers& registers, MemoryMap& memoryMap) {
    ASL_Absolute_Helper(registers, memoryMap, registers.X);
}

void NesEmu::LSR_Accumulator(Registers& registers, MemoryMap& memoryMap) {
	bool carry;
	registers.A = LSR_Helper(registers.A, carry);
	registers.SetZero(static_cast<int8_t>(registers.A));
	registers.SetNegative(static_cast<int8_t>(registers.A));
	registers.SetCarry(carry);
}

void NesEmu::LSR_ZeroPage(Registers& registers, MemoryMap& memoryMap) {
	LSR_ZeroPage_Helper(registers, memoryMap);
}

void NesEmu::LSR_ZeroPage_X(Registers& registers, MemoryMap& memoryMap) {
	LSR_ZeroPage_Helper(registers, memoryMap, registers.X);
}

void NesEmu::LSR_Absolute(Registers& registers, MemoryMap& memoryMap) {
	LSR_Absolute_Helper(registers, memoryMap);
}

void NesEmu::LSR_Absolute_X(Registers& registers, MemoryMap& memoryMap) {
	LSR_Absolute_Helper(registers, memoryMap, registers.X);
}

void NesEmu::NOP(Registers& registers, MemoryMap& memoryMap) { }

void NesEmu::CLC(Registers& registers, MemoryMap& memoryMap) {
	registers.SetCarry(false);
}

void NesEmu::SEC(Registers& registers, MemoryMap& memoryMap) {
	registers.SetCarry(true);
}

void NesEmu::CLI(Registers& registers, MemoryMap& memoryMap) {
	registers.SetInterrupt(false);
}

void NesEmu::SEI(Registers& registers, MemoryMap& memoryMap) {
	registers.SetInterrupt(true);
}

void NesEmu::CLD(Registers& registers, MemoryMap& memoryMap) {
	registers.SetDecimal(false);
}

void NesEmu::CLV(Registers& registers, MemoryMap& memoryMap) {
	registers.SetOverflow(false);
}

void NesEmu::SED(Registers& registers, MemoryMap& memoryMap) {
	registers.SetDecimal(true);
}

void NesEmu::CMP_Immediate(Registers& registers, MemoryMap& memoryMap) {
	auto operand = memoryMap.GetByte(registers.PC + 1);
	CMP_Helper(registers, registers.A, operand);
}

void NesEmu::CMP_ZeroPage(Registers& registers, MemoryMap& memoryMap) {
	CMP_ZeroPage_Helper(registers, memoryMap, registers.A);
}

void NesEmu::CMP_ZeroPage_X(Registers& registers, MemoryMap& memoryMap) {
	CMP_ZeroPage_Helper(registers, memoryMap, registers.A, registers.X);
}

void NesEmu::CMP_Absolute(Registers& registers, MemoryMap& memoryMap) {
	CMP_Absolute_Helper(registers, memoryMap, registers.A);
}

void NesEmu::CMP_Absolute_X(Registers& registers, MemoryMap& memoryMap) {
	CMP_Absolute_Helper(registers, memoryMap, registers.A, registers.X);
}

void NesEmu::CMP_Absolute_Y(Registers& registers, MemoryMap& memoryMap) {
	CMP_Absolute_Helper(registers, memoryMap, registers.A, registers.Y);
}

void NesEmu::CMP_Indirect_X(Registers& registers, MemoryMap& memoryMap) {
	CMP_Indirect_X_Helper(registers, memoryMap, registers.A);
}

void NesEmu::CMP_Indirect_Y(Registers& registers, MemoryMap& memoryMap) {
	CMP_Indirect_Y_Helper(registers, memoryMap, registers.A);
}

void NesEmu::CPX_Immediate(Registers& registers, MemoryMap& memoryMap) {
	auto operand = memoryMap.GetByte(registers.PC + 1);
	CMP_Helper(registers, registers.X, operand);
}

void NesEmu::CPX_ZeroPage(Registers& registers, MemoryMap& memoryMap) {
	CMP_Absolute_Helper(registers, memoryMap, registers.X);
}

void NesEmu::CPX_Absolute(Registers& registers, MemoryMap& memoryMap) {
	CMP_Absolute_Helper(registers, memoryMap, registers.X);
}

void NesEmu::CPY_Immediate(Registers& registers, MemoryMap& memoryMap) {
	auto operand = memoryMap.GetByte(registers.PC + 1);
	CMP_Helper(registers, registers.Y, operand);
}

void NesEmu::CPY_ZeroPage(Registers& registers, MemoryMap& memoryMap) {
	CMP_Absolute_Helper(registers, memoryMap, registers.Y);
}

void NesEmu::CPY_Absolute(Registers& registers, MemoryMap& memoryMap) {
	CMP_Absolute_Helper(registers, memoryMap, registers.Y);
}

void NesEmu::ORA_Immediate(Registers& registers, MemoryMap& memoryMap) {
	auto operand = memoryMap.GetByte(registers.PC + 1);
	ORA_Helper(registers, operand);
}

void NesEmu::ORA_ZeroPage(Registers& registers, MemoryMap& memoryMap) {
	ORA_ZeroPage_Helper(registers, memoryMap);
}

void NesEmu::ORA_ZeroPage_X(Registers& registers, MemoryMap& memoryMap) {
	ORA_ZeroPage_Helper(registers, memoryMap, registers.X);
}

void NesEmu::ORA_Absolute(Registers& registers, MemoryMap& memoryMap) {
	ORA_Absolute_Helper(registers, memoryMap);
}

void NesEmu::ORA_Absolute_X(Registers& registers, MemoryMap& memoryMap) {
	ORA_Absolute_Helper(registers, memoryMap, registers.X);
}

void NesEmu::ORA_Absolute_Y(Registers& registers, MemoryMap& memoryMap) {
	ORA_Absolute_Helper(registers, memoryMap, registers.Y);
}

void NesEmu::ORA_Indirect_X(Registers& registers, MemoryMap& memoryMap) {
	auto address = GetIndirectXAddress(registers, memoryMap);
	auto value = memoryMap.GetByte(address);
	ORA_Helper(registers, value);
}

void NesEmu::ORA_Indirect_Y(Registers& registers, MemoryMap& memoryMap) {
	auto address = GetIndirectYAddress(registers, memoryMap);
	auto value = memoryMap.GetByte(address);
	ORA_Helper(registers, value);
}

void NesEmu::PHA(Registers& registers, MemoryMap& memoryMap) {
	Push_Helper(registers, memoryMap, registers.A);
}

void NesEmu::PLA(Registers& registers, MemoryMap& memoryMap) {
	registers.A = Pull_Byte_Helper(registers, memoryMap);
}

void NesEmu::PHP(Registers& registers, MemoryMap& memoryMap) {
	Push_Helper(registers, memoryMap, registers.P);
}

void NesEmu::PLP(Registers& registers, MemoryMap& memoryMap) {
	registers.P = Pull_Byte_Helper(registers, memoryMap);
}

void NesEmu::ROL_Accumulator(Registers& registers, MemoryMap& memoryMap) {
	ROL_Helper(registers, registers.A);
}

void NesEmu::ROL_ZeroPage(Registers& registers, MemoryMap& memoryMap) {
	ROL_ZeroPage_Helper(registers, memoryMap);
}

void NesEmu::ROL_ZeroPage_X(Registers& registers, MemoryMap& memoryMap) {
	ROL_ZeroPage_Helper(registers, memoryMap, registers.X);
}

void NesEmu::ROL_Absolute(Registers& registers, MemoryMap& memoryMap) {
	ROL_Absolute_Helper(registers, memoryMap);
}

void NesEmu::ROL_Absolute_X(Registers& registers, MemoryMap& memoryMap) {
	ROL_Absolute_Helper(registers, memoryMap, registers.X);
}

void NesEmu::ROR_Accumulator(Registers& registers, MemoryMap& memoryMap) {
	ROR_Helper(registers, registers.A);
}

void NesEmu::ROR_ZeroPage(Registers& registers, MemoryMap& memoryMap) {
	ROR_ZeroPage_Helper(registers, memoryMap);
}

void NesEmu::ROR_ZeroPage_X(Registers& registers, MemoryMap& memoryMap) {
	ROR_ZeroPage_Helper(registers, memoryMap, registers.X);
}

void NesEmu::ROR_Absolute(Registers& registers, MemoryMap& memoryMap) {
	ROR_Absolute_Helper(registers, memoryMap);
}

void NesEmu::ROR_Absolute_X(Registers& registers, MemoryMap& memoryMap) {
	ROR_Absolute_Helper(registers, memoryMap, registers.X);
}

void NesEmu::RTS(Registers& registers, MemoryMap& memoryMap) {
	uint16_t value = Pull_Word_Helper(registers, memoryMap) + 1;
	registers.PC = value;
}

void NesEmu::SBC_Immediate(Registers& registers, MemoryMap& memoryMap) {
	auto operand = memoryMap.GetByte(registers.PC + 1);
	SBC_Helper(registers, operand);
}

void NesEmu::SBC_ZeroPage(Registers& registers, MemoryMap& memoryMap) {
	SBC_ZeroPage_Helper(registers, memoryMap);
}

void NesEmu::SBC_ZeroPage_X(Registers& registers, MemoryMap& memoryMap) {
	SBC_ZeroPage_Helper(registers, memoryMap, registers.X);
}

void NesEmu::SBC_Absolute(Registers& registers, MemoryMap& memoryMap) {
	SBC_Absolute_Helper(registers, memoryMap);
}

void NesEmu::SBC_Absolute_X(Registers& registers, MemoryMap& memoryMap) {
	SBC_Absolute_Helper(registers, memoryMap, registers.X);
}

void NesEmu::SBC_Absolute_Y(Registers& registers, MemoryMap& memoryMap) {
	SBC_Absolute_Helper(registers, memoryMap, registers.Y);
}

void NesEmu::SBC_Indirect_X(Registers& registers, MemoryMap& memoryMap) {
	auto address = GetIndirectXAddress(registers, memoryMap);
	auto value = memoryMap.GetByte(address);
	SBC_Helper(registers, value);
}

void NesEmu::SBC_Indirect_Y(Registers& registers, MemoryMap& memoryMap) {
	auto address = GetIndirectYAddress(registers, memoryMap);
	auto value = memoryMap.GetByte(address);
	SBC_Helper(registers, value);
}

void NesEmu::TAX(Registers& registers, MemoryMap& memoryMap) {
	registers.X = registers.A;
	Transfer_Helper(registers, registers.X);
}

void NesEmu::TAY(Registers& registers, MemoryMap& memoryMap) {
	registers.Y = registers.A;
	Transfer_Helper(registers, registers.Y);
}

void NesEmu::TSX(Registers& registers, MemoryMap& memoryMap) {
	registers.X = registers.S;
	Transfer_Helper(registers, registers.X);
}

void NesEmu::TXA(Registers& registers, MemoryMap& memoryMap) {
	registers.A = registers.X;
	Transfer_Helper(registers, registers.A);
}

void NesEmu::TXS(Registers& registers, MemoryMap& memoryMap) {
	registers.S = registers.X;
	Transfer_Helper(registers, registers.S);
}

void NesEmu::TYA(Registers& registers, MemoryMap& memoryMap) {
	registers.A = registers.Y;
	Transfer_Helper(registers, registers.A);
}