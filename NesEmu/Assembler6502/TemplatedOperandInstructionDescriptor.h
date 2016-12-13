#pragma once

#include "BaseInstructionDescriptor.h"
#include "Symbols.h"
#include "InstructionToken.h"

using namespace std;

namespace Assembler6502 {
	template <typename TOperand>
	class TemplatedOperandInstructionDescriptor : public BaseInstructionDescriptor {
	public:
		TemplatedOperandInstructionDescriptor(const string& instruction, const InstructionToken operand) :_instruction(instruction), _operand(operand) {}
	private:
		string _instruction;
		InstructionToken _operand;
	protected:
		string GetInstruction() {
			return _instruction;
		}
		TOperand GetOperand(const Symbols<uint16_t>& labels) {
			const string& s = _operand.AsString();
			if (labels.Contains(s)) {
				return static_cast<TOperand>(labels.GetLabelValue(_operand.AsString()));
			}
			return _operand.GetValue<TOperand>();
		}
	};
}