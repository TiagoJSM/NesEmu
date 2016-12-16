#pragma once

#include <vector>

using namespace std;

namespace Assembler6502 {
	class CompilationResult {
	public:
		CompilationResult(vector<uint8_t> compiledByteCode);
		CompilationResult(vector<string> errorLines);
		
		bool Successful();
	private:
		vector<uint8_t> _compiledByteCode; 
		vector<string> _errorLines;
	};
}