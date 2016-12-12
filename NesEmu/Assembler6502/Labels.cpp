#include "Labels.h"

namespace Assembler6502 {
	
	Labels::Labels() {}

	void Labels::AddLabel(const string& labelName, uint16_t value) {
		_labelMapping.insert(pair<string, uint16_t>(labelName, value));
	}

	bool Labels::Contains(const string& labelName) const {
		auto it = _labelMapping.find(labelName);
		return it != _labelMapping.end();
	}

	uint16_t Labels::GetLabelValue(const string& labelName) const {
		return _labelMapping.at(labelName);
	}

}