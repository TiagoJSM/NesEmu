#pragma once

#include "CpuRegisters.h"
#include "MemoryMap.h"
#include "UtilitaryFunctions.h"
#include "Macros.h"

//http://www.6502.org/tutorials/6502opcodes.html
//http://wiki.nesdev.com/w/index.php/CPU_unofficial_opcodes
//https://skilldrick.github.io/easy6502/

namespace NesEmu {
	typedef void(*OpCode)(CpuRegisters&, MemoryMap&);

	void ADC_Immediate(CpuRegisters& registers, MemoryMap& memoryMapMap);
	void ADC_ZeroPage(CpuRegisters& registers, MemoryMap& memoryMap);
	void ADC_ZeroPage_X(CpuRegisters& registers, MemoryMap& memoryMap);
	void ADC_Absolute(CpuRegisters& registers, MemoryMap& memoryMap);
	void ADC_Absolute_X(CpuRegisters& registers, MemoryMap& memoryMap);
	void ADC_Absolute_Y(CpuRegisters& registers, MemoryMap& memoryMap);
	void ADC_Indirect_X(CpuRegisters& registers, MemoryMap& memoryMap);
	void ADC_Indirect_Y(CpuRegisters& registers, MemoryMap& memoryMap);

	void AND_Immediate(CpuRegisters& registers, MemoryMap& memoryMap);
	void AND_ZeroPage(CpuRegisters& registers, MemoryMap& memoryMap);
	void AND_ZeroPage_X(CpuRegisters& registers, MemoryMap& memoryMap);
	void AND_Absolute(CpuRegisters& registers, MemoryMap& memoryMap);
	void AND_Absolute_X(CpuRegisters& registers, MemoryMap& memoryMap);
	void AND_Absolute_Y(CpuRegisters& registers, MemoryMap& memoryMap);
	void AND_Indirect_X(CpuRegisters& registers, MemoryMap& memoryMap);
	void AND_Indirect_Y(CpuRegisters& registers, MemoryMap& memoryMap);

	void ASL_Accumulator(CpuRegisters& registers, MemoryMap& memoryMap);
	void ASL_ZeroPage(CpuRegisters& registers, MemoryMap& memoryMap);
	void ASL_ZeroPage_X(CpuRegisters& registers, MemoryMap& memoryMap);
	void ASL_Absolute(CpuRegisters& registers, MemoryMap& memoryMap);
	void ASL_Absolute_X(CpuRegisters& registers, MemoryMap& memoryMap);

	void BCC(CpuRegisters& registers, MemoryMap& memoryMap);
	void BCS(CpuRegisters& registers, MemoryMap& memoryMap);
	void BEQ(CpuRegisters& registers, MemoryMap& memoryMap);
	void BMI(CpuRegisters& registers, MemoryMap& memoryMap);
	void BNE(CpuRegisters& registers, MemoryMap& memoryMap);
	void BPL(CpuRegisters& registers, MemoryMap& memoryMap);
	void BVC(CpuRegisters& registers, MemoryMap& memoryMap);
	void BVS(CpuRegisters& registers, MemoryMap& memoryMap);

	void BRK(CpuRegisters& registers, MemoryMap& memoryMap);

	void BIT_ZeroPage(CpuRegisters& registers, MemoryMap& memoryMap);
	void BIT_Absolute(CpuRegisters& registers, MemoryMap& memoryMap);

	void CLC(CpuRegisters& registers, MemoryMap& memoryMap);
	void CLD(CpuRegisters& registers, MemoryMap& memoryMap);
	void CLI(CpuRegisters& registers, MemoryMap& memoryMap);
	void CLV(CpuRegisters& registers, MemoryMap& memoryMap);

	void CMP_Immediate(CpuRegisters& registers, MemoryMap& memoryMap);
	void CMP_ZeroPage(CpuRegisters& registers, MemoryMap& memoryMap);
	void CMP_ZeroPage_X(CpuRegisters& registers, MemoryMap& memoryMap);
	void CMP_Absolute(CpuRegisters& registers, MemoryMap& memoryMap);
	void CMP_Absolute_X(CpuRegisters& registers, MemoryMap& memoryMap);
	void CMP_Absolute_Y(CpuRegisters& registers, MemoryMap& memoryMap);
	void CMP_Indirect_X(CpuRegisters& registers, MemoryMap& memoryMap);
	void CMP_Indirect_Y(CpuRegisters& registers, MemoryMap& memoryMap);

	void CPX_Immediate(CpuRegisters& registers, MemoryMap& memoryMap);
	void CPX_ZeroPage(CpuRegisters& registers, MemoryMap& memoryMap);
	void CPX_Absolute(CpuRegisters& registers, MemoryMap& memoryMap);

	void CPY_Immediate(CpuRegisters& registers, MemoryMap& memoryMap);
	void CPY_ZeroPage(CpuRegisters& registers, MemoryMap& memoryMap);
	void CPY_Absolute(CpuRegisters& registers, MemoryMap& memoryMap);

	void DEC_ZeroPage(CpuRegisters& registers, MemoryMap& memoryMap);
	void DEC_ZeroPage_X(CpuRegisters& registers, MemoryMap& memoryMap);
	void DEC_Absolute(CpuRegisters& registers, MemoryMap& memoryMap);
	void DEC_Absolute_X(CpuRegisters& registers, MemoryMap& memoryMap);

	void DEX(CpuRegisters& registers, MemoryMap& memoryMap);
	void DEY(CpuRegisters& registers, MemoryMap& memoryMap);

	void INC_ZeroPage(CpuRegisters& registers, MemoryMap& memoryMap);
	void INC_ZeroPage_X(CpuRegisters& registers, MemoryMap& memoryMap);
	void INC_Absolute(CpuRegisters& registers, MemoryMap& memoryMap);
	void INC_Absolute_X(CpuRegisters& registers, MemoryMap& memoryMap);

	void INX(CpuRegisters& registers, MemoryMap& memoryMap);
	void INY(CpuRegisters& registers, MemoryMap& memoryMap);

	void EOR_Immediate(CpuRegisters& registers, MemoryMap& memoryMap);
	void EOR_ZeroPage(CpuRegisters& registers, MemoryMap& memoryMap);
	void EOR_ZeroPage_X(CpuRegisters& registers, MemoryMap& memoryMap);
	void EOR_Absolute(CpuRegisters& registers, MemoryMap& memoryMap);
	void EOR_Absolute_X(CpuRegisters& registers, MemoryMap& memoryMap);
	void EOR_Absolute_Y(CpuRegisters& registers, MemoryMap& memoryMap);
	void EOR_Indirect_X(CpuRegisters& registers, MemoryMap& memoryMap);
	void EOR_Indirect_Y(CpuRegisters& registers, MemoryMap& memoryMap);

	void JMP_Absolute(CpuRegisters& registers, MemoryMap& memoryMap);
	void JMP_Indirect(CpuRegisters& registers, MemoryMap& memoryMap);

	void JSR(CpuRegisters& registers, MemoryMap& memoryMap);

	void LDA_Immediate(CpuRegisters& registers, MemoryMap& memoryMap);
	void LDA_ZeroPage(CpuRegisters& registers, MemoryMap& memoryMap);
	void LDA_ZeroPage_X(CpuRegisters& registers, MemoryMap& memoryMap);
	void LDA_Absolute(CpuRegisters& registers, MemoryMap& memoryMap);
	void LDA_Absolute_X(CpuRegisters& registers, MemoryMap& memoryMap);
	void LDA_Absolute_Y(CpuRegisters& registers, MemoryMap& memoryMap);
	void LDA_Indirect_X(CpuRegisters& registers, MemoryMap& memoryMap);
	void LDA_Indirect_Y(CpuRegisters& registers, MemoryMap& memoryMap);
	
	void LDX_Immediate(CpuRegisters& registers, MemoryMap& memoryMap);
	void LDX_ZeroPage(CpuRegisters& registers, MemoryMap& memoryMap);
	void LDX_ZeroPage_Y(CpuRegisters& registers, MemoryMap& memoryMap);
	void LDX_Absolute(CpuRegisters& registers, MemoryMap& memoryMap);
	void LDX_Absolute_Y(CpuRegisters& registers, MemoryMap& memoryMap);

	void LDY_Immediate(CpuRegisters& registers, MemoryMap& memoryMap);
	void LDY_ZeroPage(CpuRegisters& registers, MemoryMap& memoryMap);
	void LDY_ZeroPage_X(CpuRegisters& registers, MemoryMap& memoryMap);
	void LDY_Absolute(CpuRegisters& registers, MemoryMap& memoryMap);
	void LDY_Absolute_X(CpuRegisters& registers, MemoryMap& memoryMap);

	void LSR_Accumulator(CpuRegisters& registers, MemoryMap& memoryMap);
	void LSR_ZeroPage(CpuRegisters& registers, MemoryMap& memoryMap);
	void LSR_ZeroPage_X(CpuRegisters& registers, MemoryMap& memoryMap);
	void LSR_Absolute(CpuRegisters& registers, MemoryMap& memoryMap);
	void LSR_Absolute_X(CpuRegisters& registers, MemoryMap& memoryMap);

	void NOP(CpuRegisters& registers, MemoryMap& memoryMap);

	void ORA_Immediate(CpuRegisters& registers, MemoryMap& memoryMap);
	void ORA_ZeroPage(CpuRegisters& registers, MemoryMap& memoryMap);
	void ORA_ZeroPage_X(CpuRegisters& registers, MemoryMap& memoryMap);
	void ORA_Absolute(CpuRegisters& registers, MemoryMap& memoryMap);
	void ORA_Absolute_X(CpuRegisters& registers, MemoryMap& memoryMap);
	void ORA_Absolute_Y(CpuRegisters& registers, MemoryMap& memoryMap);
	void ORA_Indirect_X(CpuRegisters& registers, MemoryMap& memoryMap);
	void ORA_Indirect_Y(CpuRegisters& registers, MemoryMap& memoryMap);

	void PHA(CpuRegisters& registers, MemoryMap& memoryMap);
	void PLA(CpuRegisters& registers, MemoryMap& memoryMap);
	void PHP(CpuRegisters& registers, MemoryMap& memoryMap);
	void PLP(CpuRegisters& registers, MemoryMap& memoryMap);

	void ROL_Accumulator(CpuRegisters& registers, MemoryMap& memoryMap);
	void ROL_ZeroPage(CpuRegisters& registers, MemoryMap& memoryMap);
	void ROL_ZeroPage_X(CpuRegisters& registers, MemoryMap& memoryMap);
	void ROL_Absolute(CpuRegisters& registers, MemoryMap& memoryMap);
	void ROL_Absolute_X(CpuRegisters& registers, MemoryMap& memoryMap);

	void ROR_Accumulator(CpuRegisters& registers, MemoryMap& memoryMap);
	void ROR_ZeroPage(CpuRegisters& registers, MemoryMap& memoryMap);
	void ROR_ZeroPage_X(CpuRegisters& registers, MemoryMap& memoryMap);
	void ROR_Absolute(CpuRegisters& registers, MemoryMap& memoryMap);
	void ROR_Absolute_X(CpuRegisters& registers, MemoryMap& memoryMap);

	void RTI(CpuRegisters& registers, MemoryMap& memoryMap);
	void RTS(CpuRegisters& registers, MemoryMap& memoryMap);

	void SBC_Immediate(CpuRegisters& registers, MemoryMap& memoryMap);
	void SBC_ZeroPage(CpuRegisters& registers, MemoryMap& memoryMap);
	void SBC_ZeroPage_X(CpuRegisters& registers, MemoryMap& memoryMap);
	void SBC_Absolute(CpuRegisters& registers, MemoryMap& memoryMap);
	void SBC_Absolute_X(CpuRegisters& registers, MemoryMap& memoryMap);
	void SBC_Absolute_Y(CpuRegisters& registers, MemoryMap& memoryMap);
	void SBC_Indirect_X(CpuRegisters& registers, MemoryMap& memoryMap);
	void SBC_Indirect_Y(CpuRegisters& registers, MemoryMap& memoryMap);

	void SEC(CpuRegisters& registers, MemoryMap& memoryMap);
	void SED(CpuRegisters& registers, MemoryMap& memoryMap);
	void SEI(CpuRegisters& registers, MemoryMap& memoryMap);

	void STA_ZeroPage(CpuRegisters& registers, MemoryMap& memoryMap);
	void STA_ZeroPage_X(CpuRegisters& registers, MemoryMap& memoryMap);
	void STA_Absolute(CpuRegisters& registers, MemoryMap& memoryMap);
	void STA_Absolute_X(CpuRegisters& registers, MemoryMap& memoryMap);
	void STA_Absolute_Y(CpuRegisters& registers, MemoryMap& memoryMap);
	void STA_Indirect_X(CpuRegisters& registers, MemoryMap& memoryMap);
	void STA_Indirect_Y(CpuRegisters& registers, MemoryMap& memoryMap);

	void STX_ZeroPage(CpuRegisters& registers, MemoryMap& memoryMap);
	void STX_ZeroPage_Y(CpuRegisters& registers, MemoryMap& memoryMap);
	void STX_Absolute(CpuRegisters& registers, MemoryMap& memoryMap);

	void STY_ZeroPage(CpuRegisters& registers, MemoryMap& memoryMap);
	void STY_ZeroPage_X(CpuRegisters& registers, MemoryMap& memoryMap);
	void STY_Absolute(CpuRegisters& registers, MemoryMap& memoryMap);

	void TAX(CpuRegisters& registers, MemoryMap& memoryMap);
	void TAY(CpuRegisters& registers, MemoryMap& memoryMap);
	void TSX(CpuRegisters& registers, MemoryMap& memoryMap);
	void TXA(CpuRegisters& registers, MemoryMap& memoryMap);
	void TXS(CpuRegisters& registers, MemoryMap& memoryMap);
	void TYA(CpuRegisters& registers, MemoryMap& memoryMap);
}