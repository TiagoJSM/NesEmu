#include "ByteOperandXInstructionDescriptor.h"

namespace Assembler6502 {
	ByteOperandXInstructionDescriptor::ByteOperandXInstructionDescriptor(
		const string& instruction, const AddressingMode addressMode, const InstructionToken operand)
		:BaseByteOperandInstructionDescriptor(instruction, addressMode, operand) {

	}

	vector<uint8_t> ByteOperandXInstructionDescriptor::GetOperationCodes(const OperationCodeContext& context) {
		return vector<uint8_t> { GetOpCode(OpCodeEntry(GetInstructionType(), GetAddressMode(), Operator::X)), GetOperand() };
	}
}