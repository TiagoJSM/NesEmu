#pragma once

#include <string>
#include <stdint.h>

using namespace std;

namespace Assembler6502 {
	class InstructionToken {
	public:
		InstructionToken(const string& token);

		uint8_t AsUnsignedByte();
		uint16_t AsUnsignedWord();
		string AsString();

		template <typename TValue>
		TValue GetValue() {
			return static_cast<TValue>(ParseAsNumber<uint16_t>());
		}
	private:
		string _token;

		template <typename TNumber>
		TNumber ParseAsNumber() {
			return static_cast<TNumber>(strtol(_token.c_str(), NULL, 16));
		}
	};
}