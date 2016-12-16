#include "WordOperandInstructionDescriptor.h"

namespace Assembler6502 {
	WordOperandInstructionDescriptor::WordOperandInstructionDescriptor(
		const string& instruction, const AddressingMode addressMode, const InstructionToken operand)
		:BaseWordOperandInstructionDescriptor(instruction, addressMode, operand) {

	}

	vector<uint8_t> WordOperandInstructionDescriptor::GetOperationCodes(const Labels& labels) {
		return vector<uint8_t> { GetOpCode(OpCodeEntry(GetInstructionType(), GetAddressMode(), Operator::None)), GetOperandLowByte(labels), GetOperandHighByte(labels) };
	}
}