#pragma once

#include "BaseInstructionDescriptor.h"
#include "Symbols.h"
#include "InstructionToken.h"

using namespace std;

namespace Assembler6502 {
	template <typename TOperand>
	class TemplatedOperandInstructionDescriptor : public BaseInstructionDescriptor {
	public:
		TemplatedOperandInstructionDescriptor(const string& instruction, const AddressingMode addressMode, const InstructionToken operand) 
			:_instruction(instruction), _addressMode(addressMode), _operand(operand) {}
	private:
		string _instruction;
		AddressingMode _addressMode;
		InstructionToken _operand;
	protected:
		InstructionType GetInstructionType() {
			return BaseInstructionDescriptor::GetInstructionType(_instruction);
		}
		string GetInstruction() {
			return _instruction;
		}
		TOperand GetOperand(const Labels& labels) {
			const string& s = _operand.AsString();
			if (labels.Contains(s)) {
				return static_cast<TOperand>(labels.GetLabelValue(_operand.AsString()));
			}
			return GetOperand();
		}
		TOperand GetOperand() {
			return _operand.GetValue<TOperand>();
		}

		AddressingMode GetAddressMode() {
			return _addressMode;
		}
	};
}