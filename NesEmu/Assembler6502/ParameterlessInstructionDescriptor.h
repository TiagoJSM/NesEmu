#pragma once

#include "BaseInstructionDescriptor.h"

using namespace std;

namespace Assembler6502 {

	class ParameterlessInstructionDescriptor : public BaseInstructionDescriptor {
	public:
		ParameterlessInstructionDescriptor(const string& instruction);
	private:
		string _instruction;
	};
}