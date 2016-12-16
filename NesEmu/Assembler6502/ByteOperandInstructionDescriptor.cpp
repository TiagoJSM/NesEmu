#include "ByteOperandInstructionDescriptor.h"

namespace Assembler6502 {
	ByteOperandInstructionDescriptor::ByteOperandInstructionDescriptor(
		const string& instruction, const AddressingMode addressMode, const InstructionToken operand)
		:BaseByteOperandInstructionDescriptor(instruction, addressMode, operand) {

	}

	vector<uint8_t> ByteOperandInstructionDescriptor::GetOperationCodes(const Labels& labels) {
		return vector<uint8_t> { GetOpCode(OpCodeEntry(GetInstructionType(), GetAddressMode(), Operator::None)), GetOperand(labels) };
	}
}