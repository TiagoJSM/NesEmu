#include "CompilationResult.h"

namespace Assembler6502 {
	CompilationResult::CompilationResult(vector<uint8_t> compiledByteCode)
		: _compiledByteCode(compiledByteCode) {}

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
}