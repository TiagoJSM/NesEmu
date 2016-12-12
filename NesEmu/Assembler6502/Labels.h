#pragma once

#include <map>

using namespace std;

namespace Assembler6502 {
	class Labels {
	public:
		Labels();

		void AddLabel(const string& labelName, uint16_t value);
		bool Contains(const string& labelName) const;
		uint16_t GetLabelValue(const string& labelName) const;

	private:
		map<string, uint16_t> _labelMapping;
	};
}