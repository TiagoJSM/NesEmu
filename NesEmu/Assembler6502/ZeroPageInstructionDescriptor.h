#pragma once

#include "BaseInstructionDescriptor.h"

using namespace std;

namespace Assembler6502 {

	class ZeroPageInstructionDescriptor : public BaseInstructionDescriptor {
	public:
		ZeroPageInstructionDescriptor(const string& instruction);
	private:
		string _instruction;
	};
}