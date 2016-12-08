#pragma once

#include "BaseInstructionDescriptor.h"

using namespace std;

namespace Assembler6502 {

	class BaseAbsoluteInstructionDescriptor : public BaseInstructionDescriptor {
	public:
		BaseAbsoluteInstructionDescriptor(const string& instruction, const uint16_t operand);
	private:
		string _instruction;
		uint16_t _operand;
	protected:
		string GetInstruction();
		uint16_t GetOperand();
	};
}