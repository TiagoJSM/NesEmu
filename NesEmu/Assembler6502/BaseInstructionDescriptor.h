#pragma once

#include <map>

using namespace std;

namespace Assembler6502 {

	enum class InstructionType {
		Unknown,
		ADC,
		AND,
		ASL,
		BCC,
		BCS,
		BEQ,
		BIT,
		BMI,
		BNE,
		BPL,
		BRK,
		BVC,
		BVS,
		CLC,
		CLD,
		CLI,
		CLV,
		CMP,
		CPX,
		CPY,
		DEC,
		DEX,
		DEY,
		EOR,
		INC,
		INX,
		INY,
		JMP,
		JSR,
		LDA,
		LDX,
		LDY,
		LSR,
		NOP,
		ORA,
		PHA,
		PHP,
		PLA,
		PLP,
		ROL,
		ROR,
		RTI,
		RTS,
		SBC,
		SEC,
		SED,
		SEI,
		STA,
		STX,
		STY,
		TAX,
		TAY,
		TSX,
		TXA,
		TXS,
		TYA
	};

	enum class AddressingMode
	{
		None,
		Immediate,
		ZeroPage,
		Absolute,
		Indirect
	};

	enum class Operator
	{
		None,
		X,
		Y
	};

	struct OpCodeEntry {
		OpCodeEntry(InstructionType instructionType, AddressingMode addressingMode, Operator oper);

		InstructionType instructionType;
		AddressingMode addressingMode;
		Operator oper;
	};

	struct OpEntryComparator 
	{
		bool operator()(const OpCodeEntry& e1, const OpCodeEntry& e2) const
		{
			return 
				e1.instructionType == e2.instructionType &&
				e1.addressingMode == e2.addressingMode &&
				e1.oper == e2.oper;
		}
	};

	class BaseInstructionDescriptor {
	protected:
		InstructionType GetInstructionType(const string& intruction);
		string GetInstructionType(InstructionType intruction);
		uint8_t GetOpCode(const OpCodeEntry& entry);
	private:
		static map<string, InstructionType> _instructionMapping;
		static map<OpCodeEntry, uint8_t, OpEntryComparator> _opCodeMapping;
	};
}