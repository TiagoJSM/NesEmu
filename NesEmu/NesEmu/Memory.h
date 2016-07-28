#pragma once

#include <stdint.h>

#define KBYTE 1024

namespace NesEmu{
	struct Memory {
		uint8_t data[2 * KBYTE];

		uint8_t GetByte(uint16_t address);
		uint16_t GetWord(uint16_t address);
		void StoreByte(uint16_t address, uint8_t byte);
	};
}