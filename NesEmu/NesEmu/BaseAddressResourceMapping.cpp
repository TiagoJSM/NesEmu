#include "BaseAddressResourceMapping.h"

namespace NesEmu {
	BaseAddressResourceMapping::BaseAddressResourceMapping(uint16_t minAddress, uint16_t maxAddress) {
		_minAddress = minAddress;
		_maxAddress = maxAddress;
	}

	bool BaseAddressResourceMapping::HandlesAddress(uint16_t address) {
		return address >= _minAddress && address <= _maxAddress;
	}
}