#pragma once

#include "BaseInstructionDescriptor.h"

using namespace std;

namespace Assembler6502 {

	class ParameterlessInstructionDescriptor : public BaseInstructionDescriptor {
	public:
		ParameterlessInstructionDescriptor(const string& instruction);
		uint8_t GetInstructionSize() override;
	private:
		string _instruction;
	};
}