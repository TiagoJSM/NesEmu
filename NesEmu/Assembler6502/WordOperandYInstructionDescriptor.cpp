#include "WordOperandYInstructionDescriptor.h"

namespace Assembler6502 {
	WordOperandYInstructionDescriptor::WordOperandYInstructionDescriptor(
		const string& instruction, const AddressingMode addressMode, const InstructionToken operand)
		:BaseWordOperandInstructionDescriptor(instruction, addressMode, operand) {

	}

	vector<uint8_t> WordOperandYInstructionDescriptor::GetOperationCodes(const OperationCodeContext& context) {
		return vector<uint8_t> { 
			GetOpCode(
				OpCodeEntry(
					GetInstructionType(),
					GetAddressMode(),
					Operator::Y)),
				GetOperandLowByte(),
				GetOperandHighByte() };
	}
}