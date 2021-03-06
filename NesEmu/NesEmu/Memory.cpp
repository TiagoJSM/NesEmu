#include "Memory.h"

namespace NesEmu {

	Memory::Memory(uint16_t size) : data(size) { }

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

	void Memory::StoreWord(uint16_t address, uint16_t word) {
		this->data[address + 1] = (word >> sizeof(uint8_t));
		this->data[address] = word;
	}

	void Memory::Load(vector<uint8_t> data, uint16_t baseAddress) {
		auto address = baseAddress;
		for (auto d : data) {
			this->data[address] = d;
			address++;
		}
	}
}