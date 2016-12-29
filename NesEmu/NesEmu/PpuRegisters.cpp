#include "PpuRegisters.h"

#define PpuAddressBlockSize 0x4000;

namespace NesEmu {

	bool PpuRegisters::NmiEnable() {
		return (this->PPUCTRL & BIT_7_MASK);
	}
	bool PpuRegisters::PpuMasterSlave() {
		return (this->PPUCTRL & BIT_6_MASK);
	}
	bool PpuRegisters::SpriteSizeFlag() {
		return (this->PPUCTRL & BIT_5_MASK);
	}
	SpriteSize PpuRegisters::SpriteSize() {
		return SpriteSizeFlag() ? SpriteSize::_8x16 : SpriteSize::_8x8;
	}
	bool PpuRegisters::BackgroundPatternTableAddressFlag() {
		return (this->PPUCTRL & BIT_4_MASK);
	}
	uint16_t PpuRegisters::BackgroundPatternTableAddress() {
		return BackgroundPatternTableAddressFlag() ? 0x1000 : 0x0000;
	}
	bool PpuRegisters::SpritePatternTableAddressFlag() {
		return (this->PPUCTRL & BIT_3_MASK);
	}
	uint16_t PpuRegisters::SpritePatternTableAddress() {
		if (SpriteSize() == SpriteSize::_8x16) {
			return 0x0000;
		}
		return SpritePatternTableAddressFlag() ? 0x1000 : 0x0000;
	}
	bool PpuRegisters::VRamAddressIncrementFlag() {
		return (this->PPUCTRL & BIT_2_MASK);
	}
	uint16_t PpuRegisters::VRamAddressIncrement() {
		return VRamAddressIncrementFlag() ? 32 : 1;
	}
	uint8_t PpuRegisters::BaseNametableAddressSelect() {
		return (this->PPUCTRL & BIT_1_MASK | BIT_0_MASK);
	}
	uint16_t PpuRegisters::BaseNametableAddress() {
		switch (BaseNametableAddressSelect()) {
		case 0: return 0x2000;
		case 1: return 0x2400;
		case 2: return 0x2800;
		case 3: return 0x2C00;
		}
	}

	bool PpuRegisters::EmphasizeBlue() {
		return (this->PPUMASK & BIT_7_MASK);
	}
	bool PpuRegisters::EmphasizeGreen() {
		return (this->PPUMASK & BIT_6_MASK);
	}
	bool PpuRegisters::EmphasizeRed() {
		return (this->PPUMASK & BIT_5_MASK);
	}
	bool PpuRegisters::ShowSprites() {
		return (this->PPUMASK & BIT_4_MASK);
	}
	bool PpuRegisters::ShowBackground() {
		return (this->PPUMASK & BIT_3_MASK);
	}
	bool PpuRegisters::ShowSpritesInLeftmost8Pixels() {
		return (this->PPUMASK & BIT_2_MASK);
	}
	bool PpuRegisters::ShowBackgroundInLeftmost8Pixels() {
		return (this->PPUMASK & BIT_1_MASK);
	}
	bool PpuRegisters::Grayscale() {
		return (this->PPUMASK & BIT_0_MASK);
	}

	bool PpuRegisters::VerticalBlankStarted() {
		return (this->PPUSTATUS & BIT_7_MASK);
	}
	bool PpuRegisters::Sprite0Hit() {
		return (this->PPUSTATUS & BIT_6_MASK);
	}
	bool PpuRegisters::SpriteOverflow() {
		return (this->PPUSTATUS & BIT_5_MASK);
	}

	uint8_t PpuRegisters::GetPPUSTATUS() {
		auto result = PPUSTATUS;
		PPUSTATUS = result & 0b01111111; // clear vertical blank
		return result;
	}

	void PpuRegisters::SetOAMDATA(uint8_t data) {
		OAMDATA = data;
		OAMADDR++;
	}
	uint8_t PpuRegisters::GetOAMDATA() {
		return OAMDATA;
	}

	void PpuRegisters::SetPPUSCROLL(uint8_t data) {
		if (_setScrollY) {
			PPUSCROLL_Y = data;
		}
		else {
			PPUSCROLL_X = data;
		}
		_setScrollY = !_setScrollY;
	}

	void PpuRegisters::SetPPUADDR(uint8_t data) {
		if (_setAddrHigh) {
			PPUADDR_High = data;
			auto ppuAddress = GetPpuAddress();
			//check https://wiki.nesdev.com/w/index.php/PPU_registers about setting the data dirty
			_vRamDataDirty = ppuAddress >= 0x000 && ppuAddress <= 0x3EFF;
		}
		else {
			PPUADDR_Low = data;
		}
		_setAddrHigh = !_setAddrHigh;
	}

	uint16_t PpuRegisters::GetPpuAddress() {
		auto address = (PPUADDR_High << 8) | PPUADDR_Low;
		return address % PpuAddressBlockSize;
	}

	void PpuRegisters::SetPPUADDR(uint16_t data) {
		PPUADDR_Low = data & 0xFF;
		PPUADDR_High = (data >> sizeof(uint8_t)) & 0xFF;
	}

	void PpuRegisters::SetPPUDATA(uint8_t data, PpuMemoryResourceMapping& memory) {
		memory.StoreByte(GetPpuAddress(), data);
		IncrementPPUADDR();
	}

	uint8_t PpuRegisters::GetPPUDATA(PpuMemoryResourceMapping& memory) {
		auto result = memory.GetByte(GetPpuAddress());
		IncrementPPUADDR();
		return result;
	}

	void PpuRegisters::IncrementPPUADDR() {
		SetPPUADDR(static_cast<uint16_t>(GetPpuAddress() + VRamAddressIncrement()));
	}

	void PpuRegisters::SetOAMDATA(uint8_t data, PpuMemoryResourceMapping& ppuMemory, CpuMemoryResourceMapping& cpuMemory) {

	}
}