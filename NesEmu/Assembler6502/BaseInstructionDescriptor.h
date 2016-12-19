#pragma once

#include <map>

#include "Symbols.h"

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
		Accumulator,
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
				tie(e1.instructionType, e1.addressingMode, e1.oper) < tie(e2.instructionType, e2.addressingMode, e2.oper);
		}
	};

	class OperationCodeContext {
	public:
		OperationCodeContext(Labels labels, uint16_t currentInstructionAddress);

		const Labels& GetLabels() const;
		void SetCurrentInstructionAddress(uint16_t baseAddress);
		uint16_t GetCurrentInstructionAddress() const;

	private:
		Labels _labels;
		uint16_t _currentInstructionAddress;
	};

	class BaseInstructionDescriptor {
	public:
		virtual uint8_t GetInstructionSize() = 0;
		virtual vector<uint8_t> GetOperationCodes(const OperationCodeContext& context) = 0;
	protected:
		InstructionType GetInstructionType(const string& intruction);
		string GetInstruction(InstructionType intruction);
		uint8_t GetOpCode(const OpCodeEntry& entry);
	private:
		static map<string, InstructionType> _instructionMapping;
		static map<OpCodeEntry, uint8_t, OpEntryComparator> _opCodeMapping;
	};
}