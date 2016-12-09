#include "TemplatedOperandInstructionDescriptor.h"

namespace Assembler6502 {
	template <typename TOperand>
	TemplatedOperandInstructionDescriptor<TOperand>::TemplatedOperandInstructionDescriptor(const string& instruction, const TOperand operand)
		:_instruction(instruction), _operand(operand){

	}

	template <typename TOperand>
	string TemplatedOperandInstructionDescriptor<TOperand>::GetInstruction() {
		return instruction;
	}

	template <typename TOperand>
	TOperand TemplatedOperandInstructionDescriptor<TOperand>::GetOperand() {
		return _operand;
	}
}