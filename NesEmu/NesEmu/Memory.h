#pragma once

#define KBYTE 1024

namespace NesEmu{
	struct Memory {
		unsigned char data[2 * KBYTE];
	};
}