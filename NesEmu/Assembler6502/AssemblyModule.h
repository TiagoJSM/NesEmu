#pragma once

#include <vector>

using namespace std;

namespace Assembler6502 {
	class AssemblyModule {
	public:
		AssemblyModule(vector<string>& intructionLines);

		void RemoveComments();
	
	private:
		vector<string> _intructionLines;
	};
}