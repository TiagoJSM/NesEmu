#pragma once

#include <stdint.h>
#include <vector>

#include "Macros.h"

using namespace std;

namespace NesEmu{
	struct Memory {
		vector<uint8_t> data;

		Memory(uint16_t size);

		uint8_t GetByte(uint16_t address);
		uint16_t GetWord(uint16_t address);
		void StoreByte(uint16_t address, uint8_t byte);
		void StoreWord(uint16_t address, uint16_t word);
		
		void Load(vector<uint8_t> data, uint16_t baseAddress);
	};
}