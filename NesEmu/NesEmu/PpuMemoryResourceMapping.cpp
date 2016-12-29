#include "PpuMemoryResourceMapping.h"

#define RamMemoryBlockSize 0x0800

namespace NesEmu {
	PpuMemoryResourceMapping::PpuMemoryResourceMapping(Memory& memory)
		: MemoryResourceMapping(memory, 0x0000, 0x3FFF) {
	}

	uint16_t PpuMemoryResourceMapping::GetAddressWithoutMirroring(uint16_t address) {
		if (address >= 0x3000 && address <= 0x3EFF) {
			return address - 0x1000;
		}
		if (address >= 0x3F20 && address <= 0x3FFF) {
			return 0x3F00 + (address % 0x20);
		}
		return address;
	}
}