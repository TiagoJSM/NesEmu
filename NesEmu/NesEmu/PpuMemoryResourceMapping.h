#pragma once

#include "Memory.h"
#include "MemoryResourceMapping.h"

namespace NesEmu {
	class PpuMemoryResourceMapping : public MemoryResourceMapping {
	public:
		PpuMemoryResourceMapping(Memory& memory);
	protected:
		uint16_t GetAddressWithoutMirroring(uint16_t address) override;
	};
}