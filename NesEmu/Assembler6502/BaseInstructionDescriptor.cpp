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
		{ OpCodeEntry(InstructionType::EOR, AddressingMode::ZeroPage, Operator::None), 0x45 },
		{ OpCodeEntry(InstructionType::EOR, AddressingMode::Immediate, Operator::None), 0x49 }
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