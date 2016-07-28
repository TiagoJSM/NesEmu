#include "Memory.h"

namespace NesEmu {
	uint8_t Memory::GetByte(uint16_t address) {
		return this->data[address];
	}

	uint16_t Memory::GetWord(uint16_t address) {
		return 
			(static_cast<uint16_t>(this->data[address + 1]) << sizeof(uint8_t)) + 
			static_cast<uint16_t>(this->data[address]);
	}

	void Memory::StoreByte(uint16_t address, uint8_t byte) {
		this->data[address] = byte;
	}
}