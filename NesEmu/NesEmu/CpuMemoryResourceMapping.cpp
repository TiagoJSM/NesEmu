#include "CpuMemoryResourceMapping.h"

#define RamMemoryBlockSize 0x0800

namespace NesEmu{
	CpuMemoryResourceMapping::CpuMemoryResourceMapping(Memory& memory)
		: MemoryResourceMapping(memory, 0x0000, 0x1FFF) {
	}

	uint16_t CpuMemoryResourceMapping::GetAddressWithoutMirroring(uint16_t address) {
		return address % RamMemoryBlockSize;
	}
}