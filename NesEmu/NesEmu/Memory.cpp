#include "Memory.h"

namespace NesEmu {
	unsigned char Memory::GetByte(unsigned short address) {
		return this->data[address];
	}

	unsigned short Memory::GetWord(unsigned short address) {
		return 
			(static_cast<unsigned short>(this->data[address + 1]) << sizeof(unsigned char)) + 
			static_cast<unsigned short>(this->data[address]);
	}

	void Memory::StoreByte(unsigned short address, unsigned char byte) {
		this->data[address] = byte;
	}
}