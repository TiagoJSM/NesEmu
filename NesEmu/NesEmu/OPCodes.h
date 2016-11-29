#pragma once

#include "Registers.h"
#include "MemoryMap.h"
#include "UtilitaryFunctions.h"
#include "Macros.h"

//http://www.6502.org/tutorials/6502opcodes.html
//http://wiki.nesdev.com/w/index.php/CPU_unofficial_opcodes
//https://skilldrick.github.io/easy6502/

namespace NesEmu {
	void ADC_Immediate(Registers& registers, MemoryMap& memoryMapMap);
	void ADC_ZeroPage(Registers& registers, MemoryMap& memoryMap);
	void ADC_ZeroPage_X(Registers& registers, MemoryMap& memoryMap);
	void ADC_Absolute(Registers& registers, MemoryMap& memoryMap);
	void ADC_Absolute_X(Registers& registers, MemoryMap& memoryMap);
	void ADC_Absolute_Y(Registers& registers, MemoryMap& memoryMap);
	void ADC_Indirect_X(Registers& registers, MemoryMap& memoryMap);
	void ADC_Indirect_Y(Registers& registers, MemoryMap& memoryMap);

	void AND_Immediate(Registers& registers, MemoryMap& memoryMap);
	void AND_ZeroPage(Registers& registers, MemoryMap& memoryMap);
	void AND_ZeroPage_X(Registers& registers, MemoryMap& memoryMap);
	void AND_Absolute(Registers& registers, MemoryMap& memoryMap);
	void AND_Absolute_X(Registers& registers, MemoryMap& memoryMap);
	void AND_Absolute_Y(Registers& registers, MemoryMap& memoryMap);
	void AND_Indirect_X(Registers& registers, MemoryMap& memoryMap);
	void AND_Indirect_Y(Registers& registers, MemoryMap& memoryMap);

	void ASL_Accumulator(Registers& registers, MemoryMap& memoryMap);
	void ASL_ZeroPage(Registers& registers, MemoryMap& memoryMap);
	void ASL_ZeroPage_X(Registers& registers, MemoryMap& memoryMap);
	void ASL_Absolute(Registers& registers, MemoryMap& memoryMap);
	void ASL_Absolute_X(Registers& registers, MemoryMap& memoryMap);

	void BCC(Registers& registers, MemoryMap& memoryMap);
	void BCS(Registers& registers, MemoryMap& memoryMap);
	void BEQ(Registers& registers, MemoryMap& memoryMap);
	void BMI(Registers& registers, MemoryMap& memoryMap);
	void BNE(Registers& registers, MemoryMap& memoryMap);
	void BPL(Registers& registers, MemoryMap& memoryMap);
	void BVC(Registers& registers, MemoryMap& memoryMap);
	void BVS(Registers& registers, MemoryMap& memoryMap);

	void BIT_ZeroPage(Registers& registers, MemoryMap& memoryMap);
	void BIT_Absolute(Registers& registers, MemoryMap& memoryMap);

	void CLC(Registers& registers, MemoryMap& memoryMap);
	void CLD(Registers& registers, MemoryMap& memoryMap);
	void CLI(Registers& registers, MemoryMap& memoryMap);
	void CLV(Registers& registers, MemoryMap& memoryMap);

	void CMP_Immediate(Registers& registers, MemoryMap& memoryMap);
	void CMP_ZeroPage(Registers& registers, MemoryMap& memoryMap);
	void CMP_ZeroPage_X(Registers& registers, MemoryMap& memoryMap);
	void CMP_Absolute(Registers& registers, MemoryMap& memoryMap);
	void CMP_Absolute_X(Registers& registers, MemoryMap& memoryMap);
	void CMP_Absolute_Y(Registers& registers, MemoryMap& memoryMap);
	void CMP_Indirect_X(Registers& registers, MemoryMap& memoryMap);
	void CMP_Indirect_Y(Registers& registers, MemoryMap& memoryMap);

	void CPX_Immediate(Registers& registers, MemoryMap& memoryMap);
	void CPX_ZeroPage(Registers& registers, MemoryMap& memoryMap);
	void CPX_Absolute(Registers& registers, MemoryMap& memoryMap);

	void CPY_Immediate(Registers& registers, MemoryMap& memoryMap);
	void CPY_ZeroPage(Registers& registers, MemoryMap& memoryMap);
	void CPY_Absolute(Registers& registers, MemoryMap& memoryMap);

	void DEC_ZeroPage(Registers& registers, MemoryMap& memoryMap);
	void DEC_ZeroPage_X(Registers& registers, MemoryMap& memoryMap);
	void DEC_Absolute(Registers& registers, MemoryMap& memoryMap);
	void DEC_Absolute_X(Registers& registers, MemoryMap& memoryMap);

	void DEX(Registers& registers, MemoryMap& memoryMap);
	void DEY(Registers& registers, MemoryMap& memoryMap);

	void INC_ZeroPage(Registers& registers, MemoryMap& memoryMap);
	void INC_ZeroPage_X(Registers& registers, MemoryMap& memoryMap);
	void INC_Absolute(Registers& registers, MemoryMap& memoryMap);
	void INC_Absolute_X(Registers& registers, MemoryMap& memoryMap);

	void INX(Registers& registers, MemoryMap& memoryMap);
	void INY(Registers& registers, MemoryMap& memoryMap);

	void EOR_Immediate(Registers& registers, MemoryMap& memoryMap);
	void EOR_ZeroPage(Registers& registers, MemoryMap& memoryMap);
	void EOR_ZeroPage_X(Registers& registers, MemoryMap& memoryMap);
	void EOR_Absolute(Registers& registers, MemoryMap& memoryMap);
	void EOR_Absolute_X(Registers& registers, MemoryMap& memoryMap);
	void EOR_Absolute_Y(Registers& registers, MemoryMap& memoryMap);
	void EOR_Indirect_X(Registers& registers, MemoryMap& memoryMap);
	void EOR_Indirect_Y(Registers& registers, MemoryMap& memoryMap);

	void JMP_Absolute(Registers& registers, MemoryMap& memoryMap);
	void JMP_Indirect(Registers& registers, MemoryMap& memoryMap);

	void LDA_Immediate(Registers& registers, MemoryMap& memoryMap);
	void LDA_ZeroPage(Registers& registers, MemoryMap& memoryMap);
	void LDA_ZeroPage_X(Registers& registers, MemoryMap& memoryMap);
	void LDA_Absolute(Registers& registers, MemoryMap& memoryMap);
	void LDA_Absolute_X(Registers& registers, MemoryMap& memoryMap);
	void LDA_Absolute_Y(Registers& registers, MemoryMap& memoryMap);
	void LDA_Indirect_X(Registers& registers, MemoryMap& memoryMap);
	void LDA_Indirect_Y(Registers& registers, MemoryMap& memoryMap);
	
	void LDX_Immediate(Registers& registers, MemoryMap& memoryMap);
	void LDX_ZeroPage(Registers& registers, MemoryMap& memoryMap);
	void LDX_ZeroPage_Y(Registers& registers, MemoryMap& memoryMap);
	void LDX_Absolute(Registers& registers, MemoryMap& memoryMap);
	void LDX_Absolute_Y(Registers& registers, MemoryMap& memoryMap);

	void LDY_Immediate(Registers& registers, MemoryMap& memoryMap);
	void LDY_ZeroPage(Registers& registers, MemoryMap& memoryMap);
	void LDY_ZeroPage_X(Registers& registers, MemoryMap& memoryMap);
	void LDY_Absolute(Registers& registers, MemoryMap& memoryMap);
	void LDY_Absolute_X(Registers& registers, MemoryMap& memoryMap);

	void LSR_Accumulator(Registers& registers, MemoryMap& memoryMap);
	void LSR_ZeroPage(Registers& registers, MemoryMap& memoryMap);
	void LSR_ZeroPage_X(Registers& registers, MemoryMap& memoryMap);
	void LSR_Absolute(Registers& registers, MemoryMap& memoryMap);
	void LSR_Absolute_X(Registers& registers, MemoryMap& memoryMap);

	void NOP(Registers& registers, MemoryMap& memoryMap);

	void ORA_Immediate(Registers& registers, MemoryMap& memoryMap);
	void ORA_ZeroPage(Registers& registers, MemoryMap& memoryMap);
	void ORA_ZeroPage_X(Registers& registers, MemoryMap& memoryMap);
	void ORA_Absolute(Registers& registers, MemoryMap& memoryMap);
	void ORA_Absolute_X(Registers& registers, MemoryMap& memoryMap);
	void ORA_Absolute_Y(Registers& registers, MemoryMap& memoryMap);
	void ORA_Indirect_X(Registers& registers, MemoryMap& memoryMap);
	void ORA_Indirect_Y(Registers& registers, MemoryMap& memoryMap);

	void PHA(Registers& registers, MemoryMap& memoryMap);
	void PLA(Registers& registers, MemoryMap& memoryMap);
	void PHP(Registers& registers, MemoryMap& memoryMap);
	void PLP(Registers& registers, MemoryMap& memoryMap);

	void ROL_Accumulator(Registers& registers, MemoryMap& memoryMap);
	void ROL_ZeroPage(Registers& registers, MemoryMap& memoryMap);
	void ROL_ZeroPage_X(Registers& registers, MemoryMap& memoryMap);
	void ROL_Absolute(Registers& registers, MemoryMap& memoryMap);
	void ROL_Absolute_X(Registers& registers, MemoryMap& memoryMap);

	void ROR_Accumulator(Registers& registers, MemoryMap& memoryMap);
	void ROR_ZeroPage(Registers& registers, MemoryMap& memoryMap);
	void ROR_ZeroPage_X(Registers& registers, MemoryMap& memoryMap);
	void ROR_Absolute(Registers& registers, MemoryMap& memoryMap);
	void ROR_Absolute_X(Registers& registers, MemoryMap& memoryMap);

	void SBC_Immediate(Registers& registers, MemoryMap& memoryMap);
	void SBC_ZeroPage(Registers& registers, MemoryMap& memoryMap);
	void SBC_ZeroPage_X(Registers& registers, MemoryMap& memoryMap);
	void SBC_Absolute(Registers& registers, MemoryMap& memoryMap);
	void SBC_Absolute_X(Registers& registers, MemoryMap& memoryMap);
	void SBC_Absolute_Y(Registers& registers, MemoryMap& memoryMap);
	void SBC_Indirect_X(Registers& registers, MemoryMap& memoryMap);
	void SBC_Indirect_Y(Registers& registers, MemoryMap& memoryMap);

	void SEC(Registers& registers, MemoryMap& memoryMap);
	void SED(Registers& registers, MemoryMap& memoryMap);
	void SEI(Registers& registers, MemoryMap& memoryMap);

	void STA_ZeroPage(Registers& registers, MemoryMap& memoryMap);
	void STA_ZeroPage_X(Registers& registers, MemoryMap& memoryMap);
	void STA_Absolute(Registers& registers, MemoryMap& memoryMap);
	void STA_Absolute_X(Registers& registers, MemoryMap& memoryMap);
	void STA_Absolute_Y(Registers& registers, MemoryMap& memoryMap);
	void STA_Indirect_X(Registers& registers, MemoryMap& memoryMap);
	void STA_Indirect_Y(Registers& registers, MemoryMap& memoryMap);

	void STX_ZeroPage(Registers& registers, MemoryMap& memoryMap);
	void STX_ZeroPage_Y(Registers& registers, MemoryMap& memoryMap);
	void STX_Absolute(Registers& registers, MemoryMap& memoryMap);

	void STY_ZeroPage(Registers& registers, MemoryMap& memoryMap);
	void STY_ZeroPage_X(Registers& registers, MemoryMap& memoryMap);
	void STY_Absolute(Registers& registers, MemoryMap& memoryMap);

	void TAX(Registers& registers, MemoryMap& memoryMap);
	void TAY(Registers& registers, MemoryMap& memoryMap);
	void TSX(Registers& registers, MemoryMap& memoryMap);
	void TXA(Registers& registers, MemoryMap& memoryMap);
	void TXS(Registers& registers, MemoryMap& memoryMap);
	void TYA(Registers& registers, MemoryMap& memoryMap);
}