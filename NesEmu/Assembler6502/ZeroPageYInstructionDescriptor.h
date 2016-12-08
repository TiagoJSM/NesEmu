#pragma once

#include "BaseInstructionDescriptor.h"

using namespace std;

namespace Assembler6502 {

	class ZeroPageYInstructionDescriptor : public BaseInstructionDescriptor {
	public:
		ZeroPageYInstructionDescriptor(const string& instruction, const uint8_t operand);
	private:
		string _instruction;
		uint8_t _operand;
	};
}