#include "InstructionToken.h"

namespace Assembler6502 {
	InstructionToken::InstructionToken(const string& token) : _token(token) {}

	uint8_t InstructionToken::AsUnsignedByte() {
		return ParseAsNumber<uint8_t>();
	}
	uint16_t InstructionToken::AsUnsignedWord() {
		return ParseAsNumber<uint16_t>();
	}

	string InstructionToken::AsString() {
		return _token;
	}
}