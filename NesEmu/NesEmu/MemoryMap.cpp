#include "MemoryMap.h"

namespace NesEmu {

	MemoryMap::MemoryMap(Memory& memory) {
		_resourceMappings = { new MemoryResourceMapping(memory) };
	}

	MemoryMap::~MemoryMap() {
		for (auto it = _resourceMappings.begin(); it != _resourceMappings.end(); it++)
		{
			delete (*it);
		}
		_resourceMappings.clear();
	}

	uint8_t MemoryMap::GetByte(uint16_t address) {
		return GetResourceMappingFor(address)->GetByte(address);
	}
	uint16_t MemoryMap::GetWord(uint16_t address) {
		return GetResourceMappingFor(address)->GetWord(address);
	}
	void MemoryMap::StoreByte(uint16_t address, uint8_t byte) {
		GetResourceMappingFor(address)->StoreByte(address, byte);
	}

	BaseAddressResourceMapping* MemoryMap::GetResourceMappingFor(uint16_t address) {
		for (auto iterator = _resourceMappings.begin(); iterator != _resourceMappings.end(); iterator++) {
			if ((*iterator)->HandlesAddress(address)) {
				return *iterator;
			}
		}
		return nullptr;
	}
}