#include "ByteOperandInstructionDescriptor.h"

namespace Assembler6502 {
	ByteOperandInstructionDescriptor::ByteOperandInstructionDescriptor(const string& instruction, const InstructionToken operand)
		:BaseByteOperandInstructionDescriptor(instruction, operand) {

	}

	vector<uint8_t> ByteOperandInstructionDescriptor::GetOperationCodes(const Symbols<uint16_t>& labels) {
		return vector<uint8_t> { GetOpCode(OpCodeEntry(InstructionType::EOR, AddressingMode::ZeroPage, Operator::None)), GetOperand(labels) };
	}
}