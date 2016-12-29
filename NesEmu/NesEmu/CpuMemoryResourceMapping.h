#pragma once

#include "Memory.h"
#include "MemoryResourceMapping.h"

namespace NesEmu {
	class CpuMemoryResourceMapping : public MemoryResourceMapping {
	public:
		CpuMemoryResourceMapping(Memory& memory);
	private:
		uint16_t GetAddressWithoutMirroring(uint16_t address) override;
	};
}