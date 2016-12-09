#pragma once

#include "BaseInstructionDescriptor.h"

using namespace std;

namespace Assembler6502 {
	template <typename TOperand>
	class TemplatedOperandInstructionDescriptor : public BaseInstructionDescriptor {
	public:
		TemplatedOperandInstructionDescriptor(const string& instruction, const TOperand operand) :_instruction(instruction), _operand(operand) {}
	private:
		string _instruction;
		TOperand _operand;
	protected:
		string GetInstruction() {
			return _instruction;
		}
		TOperand GetOperand() {
			return _operand
		}
	};
}