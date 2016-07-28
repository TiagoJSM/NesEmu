#pragma once

#include "Registers.h"
#include "Memory.h"

//http://www.6502.org/tutorials/6502opcodes.html
//http://wiki.nesdev.com/w/index.php/CPU_unofficial_opcodes
//https://skilldrick.github.io/easy6502/

namespace NesEmu {
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
}