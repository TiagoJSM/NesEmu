#include "AssemblyModule.h"

namespace Assembler6502 {
	AssemblyModule::AssemblyModule(vector<string>& intructionLines) :_intructionLines(intructionLines){
	}

	void AssemblyModule::RemoveComments() {
		auto uncommented = vector<string>();
		for (auto iterator = _intructionLines.begin(); iterator != _intructionLines.end(); iterator++) {
			
		}
	}
}