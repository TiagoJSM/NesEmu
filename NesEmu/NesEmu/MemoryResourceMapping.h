#pragma once

#include "Memory.h"
#include "BaseAddressResourceMapping.h"

namespace NesEmu {
	class MemoryResourceMapping : public BaseAddressResourceMapping {
	public:
		MemoryResourceMapping(Memory& memory, uint16_t minAddress, uint16_t maxAddress);

		uint8_t GetByte(uint16_t address) override;
		uint16_t GetWord(uint16_t address) override;
		void StoreByte(uint16_t address, uint8_t byte) override;
		void StoreWord(uint16_t address, uint16_t word) override;
	protected:
		Memory* _memory;

		virtual uint16_t GetAddressWithoutMirroring(uint16_t address) = 0;
	};
}