#include "ByteOperandYInstructionDescriptor.h"

namespace Assembler6502 {
	ByteOperandYInstructionDescriptor::ByteOperandYInstructionDescriptor(
		const string& instruction, const AddressingMode addressMode, const InstructionToken operand)
		:BaseByteOperandInstructionDescriptor(instruction, addressMode, operand) {

	}

	vector<uint8_t> ByteOperandYInstructionDescriptor::GetOperationCodes(const OperationCodeContext& context) {
		return vector<uint8_t> { GetOpCode(OpCodeEntry(GetInstructionType(), GetAddressMode(), Operator::Y)), GetOperand(context.GetLabels()) };
	}
}