#pragma once

#define KBYTE 1024

namespace NesEmu{
	struct Memory {
		unsigned char data[2 * KBYTE];

		unsigned char GetByte(unsigned short address);
		unsigned short GetWord(unsigned short address);
		void StoreByte(unsigned short address, unsigned char byte);
	};
}