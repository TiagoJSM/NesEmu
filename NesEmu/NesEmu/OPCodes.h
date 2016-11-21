#pragma once

#include "Registers.h"
#include "Memory.h"
#include "UtilitaryFunctions.h"
#include "Macros.h"

//http://www.6502.org/tutorials/6502opcodes.html
//http://wiki.nesdev.com/w/index.php/CPU_unofficial_opcodes
//https://skilldrick.github.io/easy6502/

namespace NesEmu {
	void ADC_Immediate(Registers& registers, Memory& memory);
	void ADC_ZeroPage(Registers& registers, Memory& memory);
	void ADC_ZeroPage_X(Registers& registers, Memory& memory);
	void ADC_Absolute(Registers& registers, Memory& memory);
	void ADC_Absolute_X(Registers& registers, Memory& memory);
	void ADC_Absolute_Y(Registers& registers, Memory& memory);
	void ADC_Indirect_X(Registers& registers, Memory& memory);
	void ADC_Indirect_Y(Registers& registers, Memory& memory);

	void AND_Immediate(Registers& registers, Memory& memory);
	void AND_ZeroPage(Registers& registers, Memory& memory);
	void AND_ZeroPage_X(Registers& registers, Memory& memory);
	void AND_Absolute(Registers& registers, Memory& memory);
	void AND_Absolute_X(Registers& registers, Memory& memory);
	void AND_Absolute_Y(Registers& registers, Memory& memory);
	void AND_Indirect_X(Registers& registers, Memory& memory);
	void AND_Indirect_Y(Registers& registers, Memory& memory);

	void ASL_Accumulator(Registers& registers, Memory& memory);
	void ASL_ZeroPage(Registers& registers, Memory& memory);
	void ASL_ZeroPage_X(Registers& registers, Memory& memory);
	void ASL_Absolute(Registers& registers, Memory& memory);
	void ASL_Absolute_X(Registers& registers, Memory& memory);

	void CLC(Registers& registers, Memory& memory);
	void CLD(Registers& registers, Memory& memory);
	void CLI(Registers& registers, Memory& memory);
	void CLV(Registers& registers, Memory& memory);

	void CMP_Immediate(Registers& registers, Memory& memory);
	void CMP_ZeroPage(Registers& registers, Memory& memory);
	void CMP_ZeroPage_X(Registers& registers, Memory& memory);
	void CMP_Absolute(Registers& registers, Memory& memory);
	void CMP_Absolute_X(Registers& registers, Memory& memory);
	void CMP_Absolute_Y(Registers& registers, Memory& memory);
	void CMP_Indirect_X(Registers& registers, Memory& memory);
	void CMP_Indirect_Y(Registers& registers, Memory& memory);

	void CPX_Immediate(Registers& registers, Memory& memory);
	void CPX_ZeroPage(Registers& registers, Memory& memory);
	void CPX_Absolute(Registers& registers, Memory& memory);

	void CPY_Immediate(Registers& registers, Memory& memory);
	void CPY_ZeroPage(Registers& registers, Memory& memory);
	void CPY_Absolute(Registers& registers, Memory& memory);

	void DEC_ZeroPage(Registers& registers, Memory& memory);
	void DEC_ZeroPage_X(Registers& registers, Memory& memory);
	void DEC_Absolute(Registers& registers, Memory& memory);
	void DEC_Absolute_X(Registers& registers, Memory& memory);

	void DEX(Registers& registers, Memory& memory);
	void DEY(Registers& registers, Memory& memory);

	void INC_ZeroPage(Registers& registers, Memory& memory);
	void INC_ZeroPage_X(Registers& registers, Memory& memory);
	void INC_Absolute(Registers& registers, Memory& memory);
	void INC_Absolute_X(Registers& registers, Memory& memory);

	void INX(Registers& registers, Memory& memory);
	void INY(Registers& registers, Memory& memory);

	void EOR_Immediate(Registers& registers, Memory& memory);
	void EOR_ZeroPage(Registers& registers, Memory& memory);
	void EOR_ZeroPage_X(Registers& registers, Memory& memory);
	void EOR_Absolute(Registers& registers, Memory& memory);
	void EOR_Absolute_X(Registers& registers, Memory& memory);
	void EOR_Absolute_Y(Registers& registers, Memory& memory);
	void EOR_Indirect_X(Registers& registers, Memory& memory);
	void EOR_Indirect_Y(Registers& registers, Memory& memory);

	void LDA_Immediate(Registers& registers, Memory& memory);
	void LDA_ZeroPage(Registers& registers, Memory& memory);
	void LDA_ZeroPage_X(Registers& registers, Memory& memory);
	void LDA_Absolute(Registers& registers, Memory& memory);
	void LDA_Absolute_X(Registers& registers, Memory& memory);
	void LDA_Absolute_Y(Registers& registers, Memory& memory);
	void LDA_Indirect_X(Registers& registers, Memory& memory);
	void LDA_Indirect_Y(Registers& registers, Memory& memory);
	
	void LDX_Immediate(Registers& registers, Memory& memory);
	void LDX_ZeroPage(Registers& registers, Memory& memory);
	void LDX_ZeroPage_Y(Registers& registers, Memory& memory);
	void LDX_Absolute(Registers& registers, Memory& memory);
	void LDX_Absolute_Y(Registers& registers, Memory& memory);

	void LDY_Immediate(Registers& registers, Memory& memory);
	void LDY_ZeroPage(Registers& registers, Memory& memory);
	void LDY_ZeroPage_X(Registers& registers, Memory& memory);
	void LDY_Absolute(Registers& registers, Memory& memory);
	void LDY_Absolute_X(Registers& registers, Memory& memory);

	void LSR_Accumulator(Registers& registers, Memory& memory);
	void LSR_ZeroPage(Registers& registers, Memory& memory);
	void LSR_ZeroPage_X(Registers& registers, Memory& memory);
	void LSR_Absolute(Registers& registers, Memory& memory);
	void LSR_Absolute_X(Registers& registers, Memory& memory);

	void NOP(Registers& registers, Memory& memory);

	void ORA_Immediate(Registers& registers, Memory& memory);
	void ORA_ZeroPage(Registers& registers, Memory& memory);
	void ORA_ZeroPage_X(Registers& registers, Memory& memory);
	void ORA_Absolute(Registers& registers, Memory& memory);
	void ORA_Absolute_X(Registers& registers, Memory& memory);
	void ORA_Absolute_Y(Registers& registers, Memory& memory);
	void ORA_Indirect_X(Registers& registers, Memory& memory);
	void ORA_Indirect_Y(Registers& registers, Memory& memory);

	void ROL_Accumulator(Registers& registers, Memory& memory);
	void ROL_ZeroPage(Registers& registers, Memory& memory);
	void ROL_ZeroPage_X(Registers& registers, Memory& memory);
	void ROL_Absolute(Registers& registers, Memory& memory);
	void ROL_Absolute_X(Registers& registers, Memory& memory);

	void ROR_Accumulator(Registers& registers, Memory& memory);
	void ROR_ZeroPage(Registers& registers, Memory& memory);
	void ROR_ZeroPage_X(Registers& registers, Memory& memory);
	void ROR_Absolute(Registers& registers, Memory& memory);
	void ROR_Absolute_X(Registers& registers, Memory& memory);

	void SEC(Registers& registers, Memory& memory);
	void SED(Registers& registers, Memory& memory);
	void SEI(Registers& registers, Memory& memory);

	void STA_ZeroPage(Registers& registers, Memory& memory);
	void STA_ZeroPage_X(Registers& registers, Memory& memory);
	void STA_Absolute(Registers& registers, Memory& memory);
	void STA_Absolute_X(Registers& registers, Memory& memory);
	void STA_Absolute_Y(Registers& registers, Memory& memory);
	void STA_Indirect_X(Registers& registers, Memory& memory);
	void STA_Indirect_Y(Registers& registers, Memory& memory);

	void STX_ZeroPage(Registers& registers, Memory& memory);
	void STX_ZeroPage_Y(Registers& registers, Memory& memory);
	void STX_Absolute(Registers& registers, Memory& memory);

	void STY_ZeroPage(Registers& registers, Memory& memory);
	void STY_ZeroPage_X(Registers& registers, Memory& memory);
	void STY_Absolute(Registers& registers, Memory& memory);
}