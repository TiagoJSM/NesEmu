#include "WordOperandXInstructionDescriptor.h"

namespace Assembler6502 {
	WordOperandXInstructionDescriptor::WordOperandXInstructionDescriptor(
		const string& instruction, const AddressingMode addressMode, const InstructionToken operand)
		:BaseWordOperandInstructionDescriptor(instruction, addressMode, operand) {

	}

	vector<uint8_t> WordOperandXInstructionDescriptor::GetOperationCodes(const Labels& labels) {
		return vector<uint8_t> { GetOpCode(OpCodeEntry(GetInstructionType(), GetAddressMode(), Operator::X)), GetOperandLowByte(labels), GetOperandHighByte(labels) };
	}
}