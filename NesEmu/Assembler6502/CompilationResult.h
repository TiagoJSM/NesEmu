#pragma once

#include <vector>

using namespace std;

namespace Assembler6502 {
	class CompilationResult {
	public:
		CompilationResult(vector<uint8_t> compiledByteCode, uint16_t baseAddress);
		CompilationResult(vector<string> errorLines);
		
		bool Successful();
		vector<uint8_t> GetCompiledByteCode();
		vector<string> GetErrorLines();
		uint16_t GetBaseAddress();
	private:
		vector<uint8_t> _compiledByteCode; 
		vector<string> _errorLines;
		uint16_t _baseAddress;
	};
}