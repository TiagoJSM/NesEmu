#pragma once

#include <stdint.h>

#include "Macros.h"
#include "PpuMemoryResourceMapping.h"

namespace NesEmu {
	//https://wiki.nesdev.com/w/index.php/PPU_registers
	enum class SpriteSize {
		_8x8, 
		_8x16
	};

	class PpuRegisters {
	public:
		uint8_t PPUCTRL, PPUMASK, OAMADDR, OAMDMA;

		//PPUCTRL decode
		bool NmiEnable();
		bool PpuMasterSlave();
		bool SpriteSizeFlag();
		SpriteSize SpriteSize();
		bool BackgroundPatternTableAddressFlag();
		uint16_t BackgroundPatternTableAddress();
		bool SpritePatternTableAddressFlag();
		uint16_t SpritePatternTableAddress();
		bool VRamAddressIncrementFlag();
		uint16_t VRamAddressIncrement();
		uint8_t BaseNametableAddressSelect();
		uint16_t BaseNametableAddress();
		
		//PPUMASK decode
		bool EmphasizeBlue();
		bool EmphasizeGreen();
		bool EmphasizeRed();
		bool ShowSprites();
		bool ShowBackground();
		bool ShowSpritesInLeftmost8Pixels();
		bool ShowBackgroundInLeftmost8Pixels();
		bool Grayscale();

		//PPUSTATUS decode
		bool VerticalBlankStarted();
		bool Sprite0Hit();
		bool SpriteOverflow();

		uint8_t GetPPUSTATUS();

		void SetOAMDATA(uint8_t data);
		uint8_t GetOAMDATA();

		void SetPPUSCROLL(uint8_t data);

		void SetPPUADDR(uint8_t data);
		uint16_t GetPpuAddress();

		void SetPPUDATA(uint8_t data, PpuMemoryResourceMapping& memory);
		uint8_t GetPPUDATA(PpuMemoryResourceMapping& memory);
	private:
		uint8_t OAMDATA;
		uint8_t PPUSTATUS;

		uint8_t PPUSCROLL_X;
		uint8_t PPUSCROLL_Y;
		bool _setScrollY;

		uint8_t PPUADDR_High;
		uint8_t PPUADDR_Low;
		bool _setAddrHigh;
		
		bool _vRamDataDirty;

		void SetPPUADDR(uint16_t data);
		void IncrementPPUADDR();
	};
}