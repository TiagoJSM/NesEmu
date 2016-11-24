#include "MemoryResourceMapping.h"

#define RamMemoryBlockSize 0x0800

namespace NesEmu{
	MemoryResourceMapping::MemoryResourceMapping(Memory& memory)
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

	uint16_t MemoryResourceMapping::GetAddressWithoutMirroring(uint16_t address) {
		return address % RamMemoryBlockSize;
	}
}