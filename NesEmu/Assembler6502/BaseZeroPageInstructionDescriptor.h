#pragma once

#include "BaseInstructionDescriptor.h"

using namespace std;

namespace Assembler6502 {

	class BaseZeroPageInstructionDescriptor : public BaseInstructionDescriptor {
	public:
		BaseZeroPageInstructionDescriptor(const string& instruction, const uint8_t operand);
	private:
		string _instruction;
		uint8_t _operand;
	protected:
		string GetInstruction();
		uint8_t GetOperand();
	};
}