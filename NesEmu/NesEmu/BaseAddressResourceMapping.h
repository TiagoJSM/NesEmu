#pragma once

#include <stdint.h>

namespace NesEmu {
	class BaseAddressResourceMapping {
	public:
		BaseAddressResourceMapping(uint16_t minAddress, uint16_t maxAddress);
		
		bool HandlesAddress(uint16_t address);

		virtual uint8_t GetByte(uint16_t address) = 0;
		virtual uint16_t GetWord(uint16_t address) = 0;
		virtual void StoreByte(uint16_t address, uint8_t byte) = 0;
	private:
		uint16_t _minAddress; 
		uint16_t _maxAddress;
	};
}