#pragma once

#include "Registers.h"
#include "Memory.h"

//http://www.6502.org/tutorials/6502opcodes.html
//http://wiki.nesdev.com/w/index.php/CPU_unofficial_opcodes
//https://skilldrick.github.io/easy6502/

namespace NesEmu {
	void LDA_Immediate(Registers& registers, Memory& memory);
}