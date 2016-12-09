#include "ByteOperandInstructionDescriptor.h"

namespace Assembler6502 {
	ByteOperandInstructionDescriptor::ByteOperandInstructionDescriptor(const string& instruction, const uint8_t operand)
		:BaseByteOperandInstructionDescriptor(instruction, operand) {

	}

	vector<uint8_t> ByteOperandInstructionDescriptor::GetOperationCodes() {
		return vector<uint8_t> { GetOpCode(OpCodeEntry(InstructionType::EOR, AddressingMode::ZeroPage, Operator::None)), GetOperand() };
	}
}