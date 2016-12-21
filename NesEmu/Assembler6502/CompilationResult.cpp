#include "CompilationResult.h"

namespace Assembler6502 {
	CompilationResult::CompilationResult(vector<uint8_t> compiledByteCode, uint16_t baseAddress)
		: _compiledByteCode(compiledByteCode), _baseAddress(baseAddress) {}

	CompilationResult::CompilationResult(vector<string> errorLines)
		: _errorLines(errorLines) {}

	bool CompilationResult::Successful() {
		return _errorLines.empty();
	}

	vector<uint8_t> CompilationResult::GetCompiledByteCode() {
		return _compiledByteCode;
	}

	vector<string> CompilationResult::GetErrorLines() {
		return _errorLines;
	}

	uint16_t CompilationResult::GetBaseAddress() {
		return _baseAddress;
	}
}