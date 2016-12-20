#include "BranchInstructionDescriptor.h"

namespace Assembler6502 {
	BranchInstructionDescriptor::BranchInstructionDescriptor(
		const string& instruction, const AddressingMode addressMode, const InstructionToken operand)
		:TemplatedOperandInstructionDescriptor(instruction, addressMode, operand) {

	}

	uint8_t BranchInstructionDescriptor::GetInstructionSize() {
		return 2;
	}

	vector<uint8_t> BranchInstructionDescriptor::GetOperationCodes(const OperationCodeContext& context) {
		auto programCounterOnBranch = context.GetCurrentInstructionAddress() + GetInstructionSize();
		auto labelValue = GetOperand(context.GetLabels());
		auto value = labelValue - programCounterOnBranch;
		return vector<uint8_t> { GetOpCode(OpCodeEntry(GetInstructionType(), GetAddressMode(), Operator::None)), static_cast<uint8_t>(value) };
	}
}