#pragma once

#include <stdint.h>
#include <vector>

#include "BaseAddressResourceMapping.h"
#include "MemoryResourceMapping.h"
#include "Memory.h"

using namespace std;

namespace NesEmu {
	class MemoryMap {
	public:
		MemoryMap(Memory& memory);
		~MemoryMap();

		uint8_t GetByte(uint16_t address);
		uint16_t GetWord(uint16_t address);
		void StoreByte(uint16_t address, uint8_t byte);
	private:
		vector<BaseAddressResourceMapping*> _resourceMappings;

		BaseAddressResourceMapping* GetResourceMappingFor(uint16_t address);
	};
}