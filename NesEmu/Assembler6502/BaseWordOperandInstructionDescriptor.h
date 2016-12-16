#pragma once

#include "TemplatedOperandInstructionDescriptor.h"
#include "InstructionToken.h"

using namespace std;

namespace Assembler6502 {
	class BaseWordOperandInstructionDescriptor : public TemplatedOperandInstructionDescriptor<uint16_t> {
	public:
		BaseWordOperandInstructionDescriptor(const string& instruction, const AddressingMode addressMode, const InstructionToken operand);
		uint8_t GetInstructionSize() override;
	protected:
		uint8_t GetOperandLowByte(const Labels& labels);
		uint8_t GetOperandHighByte(const Labels& labels);
	};
}