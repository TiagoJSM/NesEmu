#include "UtilitaryFunctions.h"

namespace Nesemu {
	uint8_t BcdToDec(uint8_t val)
	{
		return ((val / 16 * 10) + (val % 16));
	}

	uint8_t DecToBcd(uint8_t val)
	{
		return ((val / 10 * 16) + (val % 10));
	}
}