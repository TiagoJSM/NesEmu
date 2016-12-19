#include "ParameterlessInstructionDescriptor.h"

namespace Assembler6502 {
	ParameterlessInstructionDescriptor::ParameterlessInstructionDescriptor(const string& instruction, const AddressingMode addressMode) 
		:_instruction(instruction), _addressMode(addressMode){

	}

	uint8_t ParameterlessInstructionDescriptor::GetInstructionSize() {
		return 1;
	}

	vector<uint8_t> ParameterlessInstructionDescriptor::GetOperationCodes(const OperationCodeContext& context) {
		return vector<uint8_t> { GetOpCode(OpCodeEntry(GetInstructionType(_instruction), _addressMode, Operator::None)) };
	}
}