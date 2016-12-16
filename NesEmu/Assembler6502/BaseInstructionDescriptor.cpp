#include "BaseInstructionDescriptor.h"

namespace Assembler6502 {
	OpCodeEntry::OpCodeEntry(InstructionType instructionType, AddressingMode addressingMode, Operator oper) 
		:instructionType(instructionType), addressingMode(addressingMode), oper(oper) {}

	map<string, InstructionType> BaseInstructionDescriptor::_instructionMapping = {
		{ "ADC", InstructionType::ADC },
		{ "AND", InstructionType::AND },
		{ "ASL", InstructionType::ASL },
		{ "BCC", InstructionType::BCC },
		{ "BCS", InstructionType::BCS },
		{ "BEQ", InstructionType::BEQ },
		{ "BIT", InstructionType::BIT },
		{ "BMI", InstructionType::BMI },
		{ "BNE", InstructionType::BNE },
		{ "BPL", InstructionType::BPL },
		{ "BRK", InstructionType::BRK },
		{ "BVC", InstructionType::BVC },
		{ "BVS", InstructionType::BVS },
		{ "CLC", InstructionType::CLC },
		{ "CLD", InstructionType::CLD },
		{ "CLI", InstructionType::CLI },
		{ "CLV", InstructionType::CLV },
		{ "CMP", InstructionType::CMP },
		{ "CPX", InstructionType::CPX },
		{ "CPY", InstructionType::CPY },
		{ "DEC", InstructionType::DEC },
		{ "DEX", InstructionType::DEX },
		{ "DEY", InstructionType::DEY },
		{ "EOR", InstructionType::EOR },
		{ "INC", InstructionType::INC },
		{ "INX", InstructionType::INX },
		{ "INY", InstructionType::INY },
		{ "JMP", InstructionType::JMP },
		{ "JSR", InstructionType::JSR },
		{ "LDA", InstructionType::LDA },
		{ "LDX", InstructionType::LDX },
		{ "LDY", InstructionType::LDY },
		{ "LSR", InstructionType::LSR },
		{ "NOP", InstructionType::NOP },
		{ "ORA", InstructionType::ORA },
		{ "PHA", InstructionType::PHA },
		{ "PHP", InstructionType::PHP },
		{ "PLA", InstructionType::PLA },
		{ "PLP", InstructionType::PLP },
		{ "ROL", InstructionType::ROL },
		{ "ROR", InstructionType::ROR },
		{ "RTI", InstructionType::RTI },
		{ "RTS", InstructionType::RTS },
		{ "SBC", InstructionType::SBC },
		{ "SEC", InstructionType::SEC },
		{ "SED", InstructionType::SED },
		{ "SEI", InstructionType::SEI },
		{ "STA", InstructionType::STA },
		{ "STX", InstructionType::STX },
		{ "STY", InstructionType::STY },
		{ "TAX", InstructionType::TAX },
		{ "TAY", InstructionType::TAY },
		{ "TSX", InstructionType::TSX },
		{ "TXA", InstructionType::TXA },
		{ "TXS", InstructionType::TSX },
		{ "TYA", InstructionType::TYA }
	};

	map<OpCodeEntry, uint8_t, OpEntryComparator> BaseInstructionDescriptor::_opCodeMapping = {
		//ADC
		{ OpCodeEntry(InstructionType::ADC, AddressingMode::Immediate,		Operator::None),	0x69 },
		{ OpCodeEntry(InstructionType::ADC, AddressingMode::ZeroPage,		Operator::None),	0x65 },
		{ OpCodeEntry(InstructionType::ADC, AddressingMode::ZeroPage,		Operator::X),		0x75 },
		{ OpCodeEntry(InstructionType::ADC, AddressingMode::Absolute,		Operator::None),	0x6D },
		{ OpCodeEntry(InstructionType::ADC, AddressingMode::Absolute,		Operator::X),		0x7D },
		{ OpCodeEntry(InstructionType::ADC, AddressingMode::Absolute,		Operator::Y),		0x79 },
		{ OpCodeEntry(InstructionType::ADC, AddressingMode::Indirect,		Operator::X),		0x61 },
		{ OpCodeEntry(InstructionType::ADC, AddressingMode::Indirect,		Operator::Y),		0x71 },
		
		//AND
		{ OpCodeEntry(InstructionType::AND, AddressingMode::Immediate,		Operator::None),	0x29 },
		{ OpCodeEntry(InstructionType::AND, AddressingMode::ZeroPage,		Operator::None),	0x25 },
		{ OpCodeEntry(InstructionType::AND, AddressingMode::ZeroPage,		Operator::X),		0x35 },
		{ OpCodeEntry(InstructionType::AND, AddressingMode::Absolute,		Operator::None),	0x2D },
		{ OpCodeEntry(InstructionType::AND, AddressingMode::Absolute,		Operator::X),		0x3D },
		{ OpCodeEntry(InstructionType::AND, AddressingMode::Absolute,		Operator::Y),		0x39 },
		{ OpCodeEntry(InstructionType::AND, AddressingMode::Indirect,		Operator::X),		0x21 },
		{ OpCodeEntry(InstructionType::AND, AddressingMode::Indirect,		Operator::Y),		0x31 },

		//ASL 
		{ OpCodeEntry(InstructionType::ASL, AddressingMode::Accumulator,	Operator::None),	0x0A },
		{ OpCodeEntry(InstructionType::ASL, AddressingMode::ZeroPage,		Operator::None),	0x06 },
		{ OpCodeEntry(InstructionType::ASL, AddressingMode::ZeroPage,		Operator::X),		0x16 },
		{ OpCodeEntry(InstructionType::ASL, AddressingMode::Absolute,		Operator::None),	0x0E },
		{ OpCodeEntry(InstructionType::ASL, AddressingMode::Absolute,		Operator::X),		0x1E },

		//BIT 
		{ OpCodeEntry(InstructionType::BIT, AddressingMode::ZeroPage,		Operator::None),	0x24 },
		{ OpCodeEntry(InstructionType::BIT, AddressingMode::Absolute,		Operator::None),	0x2C },

		//Branch 
		{ OpCodeEntry(InstructionType::BPL, AddressingMode::None,			Operator::None),	0x10 },
		{ OpCodeEntry(InstructionType::BMI, AddressingMode::None,			Operator::None),	0x30 },
		{ OpCodeEntry(InstructionType::BVC, AddressingMode::None,			Operator::None),	0x50 },
		{ OpCodeEntry(InstructionType::BVS, AddressingMode::None,			Operator::None),	0x70 },
		{ OpCodeEntry(InstructionType::BCC, AddressingMode::None,			Operator::None),	0x90 },
		{ OpCodeEntry(InstructionType::BCS, AddressingMode::None,			Operator::None),	0xB0 },
		{ OpCodeEntry(InstructionType::BNE, AddressingMode::None,			Operator::None),	0xD0 },
		{ OpCodeEntry(InstructionType::BEQ, AddressingMode::None,			Operator::None),	0xF0 },

		//Break 
		{ OpCodeEntry(InstructionType::BRK, AddressingMode::None,			Operator::None),	0x00 },

		//CMP
		{ OpCodeEntry(InstructionType::CMP, AddressingMode::Immediate,		Operator::None),	0xC9 },
		{ OpCodeEntry(InstructionType::CMP, AddressingMode::ZeroPage,		Operator::None),	0xC5 },
		{ OpCodeEntry(InstructionType::CMP, AddressingMode::ZeroPage,		Operator::X),		0xD5 },
		{ OpCodeEntry(InstructionType::CMP, AddressingMode::Absolute,		Operator::None),	0xCD },
		{ OpCodeEntry(InstructionType::CMP, AddressingMode::Absolute,		Operator::X),		0xDD },
		{ OpCodeEntry(InstructionType::CMP, AddressingMode::Absolute,		Operator::Y),		0xD9 },
		{ OpCodeEntry(InstructionType::CMP, AddressingMode::Indirect,		Operator::X),		0xC1 },
		{ OpCodeEntry(InstructionType::CMP, AddressingMode::Indirect,		Operator::Y),		0xD1 },

		//CPX 
		{ OpCodeEntry(InstructionType::CPX, AddressingMode::Immediate,		Operator::None),	0xE0 },
		{ OpCodeEntry(InstructionType::CPX, AddressingMode::ZeroPage,		Operator::None),	0xE4 },
		{ OpCodeEntry(InstructionType::CPX, AddressingMode::Absolute,		Operator::None),	0xEC },

		//CPY
		{ OpCodeEntry(InstructionType::CPY, AddressingMode::Immediate,		Operator::None),	0xC0 },
		{ OpCodeEntry(InstructionType::CPY, AddressingMode::ZeroPage,		Operator::None),	0xC4 },
		{ OpCodeEntry(InstructionType::CPY, AddressingMode::Absolute,		Operator::None),	0xCC },

		//DEC
		{ OpCodeEntry(InstructionType::DEC, AddressingMode::ZeroPage,		Operator::None),	0xC6 },
		{ OpCodeEntry(InstructionType::DEC, AddressingMode::ZeroPage,		Operator::X),		0xD6 },
		{ OpCodeEntry(InstructionType::DEC, AddressingMode::Absolute,		Operator::None),	0xCE },
		{ OpCodeEntry(InstructionType::DEC, AddressingMode::Absolute,		Operator::X),		0xDE },

		//EOR
		{ OpCodeEntry(InstructionType::EOR, AddressingMode::Immediate,		Operator::None),	0x49 },
		{ OpCodeEntry(InstructionType::EOR, AddressingMode::ZeroPage,		Operator::None),	0x45 },
		{ OpCodeEntry(InstructionType::EOR, AddressingMode::ZeroPage,		Operator::X),		0x55 },
		{ OpCodeEntry(InstructionType::EOR, AddressingMode::Absolute,		Operator::None),	0x4D },
		{ OpCodeEntry(InstructionType::EOR, AddressingMode::Absolute,		Operator::X),		0x5D },
		{ OpCodeEntry(InstructionType::EOR, AddressingMode::Absolute,		Operator::Y),		0x59 },
		{ OpCodeEntry(InstructionType::EOR, AddressingMode::Indirect,		Operator::X),		0x41 },
		{ OpCodeEntry(InstructionType::EOR, AddressingMode::Indirect,		Operator::Y),		0x51 },
		
		//Flag 
		{ OpCodeEntry(InstructionType::CLC, AddressingMode::None,			Operator::None),	0x18 },
		{ OpCodeEntry(InstructionType::SEC, AddressingMode::None,			Operator::None),	0x38 },
		{ OpCodeEntry(InstructionType::CLI, AddressingMode::None,			Operator::None),	0x58 },
		{ OpCodeEntry(InstructionType::SEI, AddressingMode::None,			Operator::None),	0x78 },
		{ OpCodeEntry(InstructionType::CLV, AddressingMode::None,			Operator::None),	0xB8 },
		{ OpCodeEntry(InstructionType::CLD, AddressingMode::None,			Operator::None),	0xD8 },
		{ OpCodeEntry(InstructionType::SED, AddressingMode::None,			Operator::None),	0xF8 },

		//INC
		{ OpCodeEntry(InstructionType::INC, AddressingMode::ZeroPage,		Operator::None),	0xE6 },
		{ OpCodeEntry(InstructionType::INC, AddressingMode::ZeroPage,		Operator::X),		0xF6 },
		{ OpCodeEntry(InstructionType::INC, AddressingMode::Absolute,		Operator::None),	0xEE },
		{ OpCodeEntry(InstructionType::INC, AddressingMode::Absolute,		Operator::X),		0xFE },

		//JMP 
		{ OpCodeEntry(InstructionType::JMP, AddressingMode::Absolute,		Operator::None),	0x4C },
		{ OpCodeEntry(InstructionType::JMP, AddressingMode::Indirect,		Operator::None),	0x6C },

		//JSR
		{ OpCodeEntry(InstructionType::JSR, AddressingMode::Absolute,		Operator::None),	0x20 },

		//LDA
		{ OpCodeEntry(InstructionType::LDA, AddressingMode::Immediate,		Operator::None),	0xA9 },
		{ OpCodeEntry(InstructionType::LDA, AddressingMode::ZeroPage,		Operator::None),	0xA5 },
		{ OpCodeEntry(InstructionType::LDA, AddressingMode::ZeroPage,		Operator::X),		0xB5 },
		{ OpCodeEntry(InstructionType::LDA, AddressingMode::Absolute,		Operator::None),	0xAD },
		{ OpCodeEntry(InstructionType::LDA, AddressingMode::Absolute,		Operator::X),		0xBD },
		{ OpCodeEntry(InstructionType::LDA, AddressingMode::Absolute,		Operator::Y),		0xB9 },
		{ OpCodeEntry(InstructionType::LDA, AddressingMode::Indirect,		Operator::X),		0xA1 },
		{ OpCodeEntry(InstructionType::LDA, AddressingMode::Indirect,		Operator::Y),		0xB1 },

		//LDX
		{ OpCodeEntry(InstructionType::LDX, AddressingMode::Immediate,		Operator::None),	0xA2 },
		{ OpCodeEntry(InstructionType::LDX, AddressingMode::ZeroPage,		Operator::None),	0xA6 },
		{ OpCodeEntry(InstructionType::LDX, AddressingMode::ZeroPage,		Operator::Y),		0xB6 },
		{ OpCodeEntry(InstructionType::LDX, AddressingMode::Absolute,		Operator::None),	0xAE },
		{ OpCodeEntry(InstructionType::LDX, AddressingMode::Absolute,		Operator::Y),		0xBE },

		//LDY
		{ OpCodeEntry(InstructionType::LDY, AddressingMode::Immediate,		Operator::None),	0xA0 },
		{ OpCodeEntry(InstructionType::LDY, AddressingMode::ZeroPage,		Operator::None),	0xA4 },
		{ OpCodeEntry(InstructionType::LDY, AddressingMode::ZeroPage,		Operator::X),		0xB4 },
		{ OpCodeEntry(InstructionType::LDY, AddressingMode::Absolute,		Operator::None),	0xAC },
		{ OpCodeEntry(InstructionType::LDY, AddressingMode::Absolute,		Operator::X),		0xBC },

		//LSR
		{ OpCodeEntry(InstructionType::LSR, AddressingMode::Accumulator,	Operator::None),	0x4A },
		{ OpCodeEntry(InstructionType::LSR, AddressingMode::ZeroPage,		Operator::None),	0x46 },
		{ OpCodeEntry(InstructionType::LSR, AddressingMode::ZeroPage,		Operator::X),		0x56 },
		{ OpCodeEntry(InstructionType::LSR, AddressingMode::Absolute,		Operator::None),	0x4E },
		{ OpCodeEntry(InstructionType::LSR, AddressingMode::Absolute,		Operator::X),		0x5E },

		//NOP
		{ OpCodeEntry(InstructionType::NOP, AddressingMode::None,			Operator::None),	0xEA },

		//ORA
		{ OpCodeEntry(InstructionType::ORA, AddressingMode::Immediate,		Operator::None),	0x09 },
		{ OpCodeEntry(InstructionType::ORA, AddressingMode::ZeroPage,		Operator::None),	0x05 },
		{ OpCodeEntry(InstructionType::ORA, AddressingMode::ZeroPage,		Operator::X),		0x15 },
		{ OpCodeEntry(InstructionType::ORA, AddressingMode::Absolute,		Operator::None),	0x0D },
		{ OpCodeEntry(InstructionType::ORA, AddressingMode::Absolute,		Operator::X),		0x1D },
		{ OpCodeEntry(InstructionType::ORA, AddressingMode::Absolute,		Operator::Y),		0x19 },
		{ OpCodeEntry(InstructionType::ORA, AddressingMode::Indirect,		Operator::X),		0x01 },
		{ OpCodeEntry(InstructionType::ORA, AddressingMode::Indirect,		Operator::Y),		0x11 },

		//Register 
		{ OpCodeEntry(InstructionType::TAX, AddressingMode::None,			Operator::None),	0xAA },
		{ OpCodeEntry(InstructionType::TXA, AddressingMode::None,			Operator::None),	0x8A },
		{ OpCodeEntry(InstructionType::DEX, AddressingMode::None,			Operator::None),	0xCA },
		{ OpCodeEntry(InstructionType::INX, AddressingMode::None,			Operator::None),	0xE8 },
		{ OpCodeEntry(InstructionType::TAY, AddressingMode::None,			Operator::None),	0xA8 },
		{ OpCodeEntry(InstructionType::TYA, AddressingMode::None,			Operator::None),	0x98 },
		{ OpCodeEntry(InstructionType::DEY, AddressingMode::None,			Operator::None),	0x88 },
		{ OpCodeEntry(InstructionType::INY, AddressingMode::None,			Operator::None),	0xC8 },

		//ROL
		{ OpCodeEntry(InstructionType::ROL, AddressingMode::Accumulator,	Operator::None),	0x2A },
		{ OpCodeEntry(InstructionType::ROL, AddressingMode::ZeroPage,		Operator::None),	0x26 },
		{ OpCodeEntry(InstructionType::ROL, AddressingMode::ZeroPage,		Operator::X),		0x36 },
		{ OpCodeEntry(InstructionType::ROL, AddressingMode::Absolute,		Operator::None),	0x2E },
		{ OpCodeEntry(InstructionType::ROL, AddressingMode::Absolute,		Operator::X),		0x3E },

		//ROR
		{ OpCodeEntry(InstructionType::ROR, AddressingMode::Accumulator,	Operator::None),	0x6A },
		{ OpCodeEntry(InstructionType::ROR, AddressingMode::ZeroPage,		Operator::None),	0x66 },
		{ OpCodeEntry(InstructionType::ROR, AddressingMode::ZeroPage,		Operator::X),		0x76 },
		{ OpCodeEntry(InstructionType::ROR, AddressingMode::Absolute,		Operator::None),	0x6E },
		{ OpCodeEntry(InstructionType::ROR, AddressingMode::Absolute,		Operator::X),		0x7E },

		//RTI
		{ OpCodeEntry(InstructionType::RTI, AddressingMode::None,			Operator::None),	0x40 },

		//RTS
		{ OpCodeEntry(InstructionType::RTS, AddressingMode::None,			Operator::None),	0x60 },

		//SBC
		{ OpCodeEntry(InstructionType::SBC, AddressingMode::Immediate,		Operator::None),	0xE9 },
		{ OpCodeEntry(InstructionType::SBC, AddressingMode::ZeroPage,		Operator::None),	0xE5 },
		{ OpCodeEntry(InstructionType::SBC, AddressingMode::ZeroPage,		Operator::X),		0xF5 },
		{ OpCodeEntry(InstructionType::SBC, AddressingMode::Absolute,		Operator::None),	0xED },
		{ OpCodeEntry(InstructionType::SBC, AddressingMode::Absolute,		Operator::X),		0xFD },
		{ OpCodeEntry(InstructionType::SBC, AddressingMode::Absolute,		Operator::Y),		0xF9 },
		{ OpCodeEntry(InstructionType::SBC, AddressingMode::Indirect,		Operator::X),		0xE1 },
		{ OpCodeEntry(InstructionType::SBC, AddressingMode::Indirect,		Operator::Y),		0xF1 },

		//STA
		{ OpCodeEntry(InstructionType::STA, AddressingMode::ZeroPage,		Operator::None),	0x85 },
		{ OpCodeEntry(InstructionType::STA, AddressingMode::ZeroPage,		Operator::X),		0x95 },
		{ OpCodeEntry(InstructionType::STA, AddressingMode::Absolute,		Operator::None),	0x8D },
		{ OpCodeEntry(InstructionType::STA, AddressingMode::Absolute,		Operator::X),		0x9D },
		{ OpCodeEntry(InstructionType::STA, AddressingMode::Absolute,		Operator::Y),		0x99 },
		{ OpCodeEntry(InstructionType::STA, AddressingMode::Indirect,		Operator::X),		0x81 },
		{ OpCodeEntry(InstructionType::STA, AddressingMode::Indirect,		Operator::Y),		0x81 },

		//Stack 
		{ OpCodeEntry(InstructionType::TXS, AddressingMode::None,			Operator::None),	0x9A },
		{ OpCodeEntry(InstructionType::TSX, AddressingMode::None,			Operator::None),	0xBA },
		{ OpCodeEntry(InstructionType::PHA, AddressingMode::None,			Operator::None),	0x48 },
		{ OpCodeEntry(InstructionType::PLA, AddressingMode::None,			Operator::None),	0x68 },
		{ OpCodeEntry(InstructionType::PHP, AddressingMode::None,			Operator::None),	0x08 },
		{ OpCodeEntry(InstructionType::PLP, AddressingMode::None,			Operator::None),	0x28 },

		//STX
		{ OpCodeEntry(InstructionType::STX, AddressingMode::ZeroPage,		Operator::None),	0x86 },
		{ OpCodeEntry(InstructionType::STX, AddressingMode::ZeroPage,		Operator::Y),		0x96 },
		{ OpCodeEntry(InstructionType::STX, AddressingMode::Absolute,		Operator::None),	0x8E },

		//STY
		{ OpCodeEntry(InstructionType::STY, AddressingMode::ZeroPage,		Operator::None),	0x84 },
		{ OpCodeEntry(InstructionType::STY, AddressingMode::ZeroPage,		Operator::X),		0x94 },
		{ OpCodeEntry(InstructionType::STY, AddressingMode::Absolute,		Operator::None),	0x8C },
	};

	InstructionType BaseInstructionDescriptor::GetInstructionType(const string& intruction) {
		if (_instructionMapping.find(intruction) != _instructionMapping.end()) {
			return _instructionMapping[intruction];
		}
		return InstructionType::Unknown;
	}

	string BaseInstructionDescriptor::GetInstructionType(InstructionType intruction) {
		for (auto it = _instructionMapping.begin(); it != _instructionMapping.end(); ++it) {
			if (it->second == intruction) {
				return it->first;
			}
		}
		return string();
	}

	uint8_t BaseInstructionDescriptor::GetOpCode(const OpCodeEntry& entry) {
		return _opCodeMapping[entry];
	}
}