#include "MemoryResourceMapping.h"

#define RamMemoryBlockSize 0x0800

namespace NesEmu {
	MemoryResourceMapping::MemoryResourceMapping(Memory& memory, uint16_t minAddress, uint16_t maxAddress)
		: BaseAddressResourceMapping(0x0000, 0x1FFF) {
		_memory = &memory;
	}

	uint8_t MemoryResourceMapping::GetByte(uint16_t address) {
		return _memory->GetByte(GetAddressWithoutMirroring(address));
	}

	uint16_t MemoryResourceMapping::GetWord(uint16_t address) {
		return _memory->GetWord(GetAddressWithoutMirroring(address));
	}

	void MemoryResourceMapping::StoreByte(uint16_t address, uint8_t byte) {
		_memory->StoreByte(GetAddressWithoutMirroring(address), byte);
	}

	void MemoryResourceMapping::StoreWord(uint16_t address, uint16_t word) {
		_memory->StoreWord(GetAddressWithoutMirroring(address), word);
	}

	void MemoryResourceMapping::GetData(uint16_t startAddress, uint16_t byteCount, vector<uint8_t>::iterator output) {
		copy(_memory->data.begin(), _memory->data.begin() + byteCount + startAddress, output);
	}

	void MemoryResourceMapping::SetData(uint16_t startAddress, const vector<uint8_t>& input) {
		copy(input.begin(), input.end(), _memory->data.begin());
	}
}