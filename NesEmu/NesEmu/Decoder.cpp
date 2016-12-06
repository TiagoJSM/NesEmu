#include "Decoder.h"

namespace NesEmu {

	const auto opCodesLength = 0x100;

	OpCode _opCodes[opCodesLength] =
	{				/*0*/			/*1*/			/*2*/			/*3*/		/*4*/			/*5*/			/*6*/			/*7*/		/*8*/	/*9*/				/*A*/				/*B*/		/*C*/			/*D*/			/*E*/			/*F*/
	/*$00 - $0F*/	BRK,			ORA_Indirect_X,	nullptr,		nullptr,	nullptr,		ORA_ZeroPage,	ASL_ZeroPage,	nullptr,	PHP,	ORA_Immediate,		ASL_Accumulator,	nullptr,	nullptr,		ORA_Absolute,	ASL_Absolute,	nullptr,
	/*$10 - $1F*/	BMI,			ORA_Indirect_Y,	nullptr,		nullptr,	nullptr,		ORA_ZeroPage_X,	ASL_ZeroPage_X, nullptr,	CLC,	ORA_Absolute_Y,		nullptr,			nullptr,	nullptr,		ORA_Absolute_X,	ASL_Absolute_X,	nullptr,
	/*$20 - $2F*/	JSR,			AND_Indirect_X,	nullptr,		nullptr,	BIT_ZeroPage,	AND_ZeroPage,	ROL_ZeroPage,	nullptr,	PLP,	AND_Immediate,		ROL_Accumulator,	nullptr,	BIT_Absolute,	AND_Absolute,	ROL_Absolute,	nullptr,
	/*$30 - $3F*/	BMI,			AND_Indirect_Y,	nullptr,		nullptr,	nullptr,		AND_ZeroPage_X,	ROL_ZeroPage_X,	nullptr,	CLI,	AND_Absolute_Y,		nullptr,			nullptr,	nullptr,		AND_Absolute_X,	ROL_Absolute_X,	nullptr,
	/*$40 - $4F*/	RTI,			EOR_Indirect_X,	nullptr,		nullptr,	nullptr,		EOR_ZeroPage,	LSR_ZeroPage,	nullptr,	PHA,	EOR_Immediate,		LSR_Accumulator,	nullptr,	JMP_Absolute,	EOR_Absolute,	LSR_Absolute,	nullptr,
	/*$50 - $5F*/	BVC,			EOR_Indirect_Y,	nullptr,		nullptr,	nullptr,		EOR_Absolute,	LSR_ZeroPage_X,	nullptr,	CLI,	EOR_Absolute_Y,		nullptr,			nullptr,	nullptr,		EOR_Absolute_X,	LSR_Absolute_X,	nullptr,
	/*$60 - $6F*/	RTS,			ADC_Indirect_X,	nullptr,		nullptr,	nullptr,		ADC_ZeroPage,	ROR_ZeroPage,	nullptr,	PLA,	ADC_Immediate,		ROR_Accumulator,	nullptr,	JMP_Indirect,	ADC_Absolute,	ROR_Absolute,	nullptr,
	/*$70 - $7F*/	BVS,			ADC_Indirect_Y,	nullptr,		nullptr,	nullptr,		ADC_ZeroPage_X,	ROR_ZeroPage_X,	nullptr,	SEI,	ADC_Absolute_Y,		nullptr,			nullptr,	nullptr,		ADC_Absolute_X,	ROR_Absolute_X,	nullptr,
	/*$80 - $8F*/	nullptr,		STA_Indirect_X,	nullptr,		nullptr,	STY_ZeroPage,	STA_ZeroPage,	STX_ZeroPage,	nullptr,	DEY,	nullptr,			TXA,				nullptr,	STY_Absolute,	STA_Absolute,	STX_Absolute,	nullptr,
	/*$90 - $9F*/	BCC,			STA_Indirect_Y,	nullptr,		nullptr,	STY_ZeroPage_X,	STA_ZeroPage_X,	STX_ZeroPage_Y,	nullptr,	TYA,	STA_Absolute_Y,		TXS,				nullptr,	nullptr,		STA_Absolute_X,	nullptr,		nullptr,
	/*$A0 - $AF*/	LDY_Immediate,	LDA_Indirect_X,	LDX_Immediate,	nullptr,	LDY_ZeroPage,	LDA_ZeroPage,	LDX_ZeroPage,	nullptr,	TAY,	LDA_Immediate,		TAX,				nullptr,	LDY_Absolute,	LDA_Absolute,	LDX_Absolute,	nullptr,
	/*$B0 - $BF*/	BCS,			LDA_Indirect_Y,	nullptr,		nullptr,	LDY_ZeroPage_X,	LDA_ZeroPage_X,	LDX_ZeroPage_Y,	nullptr,	CLV,	LDA_Absolute_Y,		TSX,				nullptr,	LDY_Absolute_X,	LDA_Absolute_X,	LDX_Absolute_Y,	nullptr,
	/*$C0 - $CF*/	CPY_Immediate,	CMP_Indirect_X,	nullptr,		nullptr,	CPY_ZeroPage,	CMP_ZeroPage,	DEC_ZeroPage,	nullptr,	INY,	CMP_Immediate,		DEX,				nullptr,	CPY_Absolute,	CMP_Absolute,	DEC_Absolute,	nullptr,
	/*$D0 - $DF*/	BNE,			CMP_Indirect_Y,	nullptr,		nullptr,	nullptr,		CMP_ZeroPage_X,	DEC_ZeroPage_X,	nullptr,	CLD,	CMP_Absolute_Y,		nullptr,			nullptr,	nullptr,		CMP_Absolute_X,	DEC_Absolute_X,	nullptr,
	/*$E0 - $EF*/	CPX_Immediate,	SBC_Indirect_X,	nullptr,		nullptr,	CPX_ZeroPage,	SBC_ZeroPage,	INC_ZeroPage,	nullptr,	INX,	SBC_Immediate,		NOP,				nullptr,	CPX_Absolute,	SBC_Absolute,	INC_Absolute,	nullptr,
	/*$F0 - $FF*/	BEQ,			SBC_Indirect_Y,	nullptr,		nullptr,	nullptr,		SBC_ZeroPage_X,	INC_ZeroPage_X,	nullptr,	SED,	SBC_Absolute_Y,		nullptr,			nullptr,	nullptr,		SBC_Absolute_X,	INC_Absolute_X,	nullptr
	};

	OpCode Decode(uint8_t byte) {
		return _opCodes[byte];
	}
}