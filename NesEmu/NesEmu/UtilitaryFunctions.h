#pragma once

#include "stdint.h"

//http://stackoverflow.com/questions/1408361/unsigned-integer-to-bcd-conversion
//http://www.6502.org/tutorials/decimal_mode.html

namespace NesEmu {
	uint8_t BcdToDec(uint8_t val);
	uint8_t DecToBcd(uint8_t val);
}