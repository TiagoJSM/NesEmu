#pragma once

#include <map>

using namespace std;

namespace Assembler6502 {
	template <typename TMappedType>
	class Symbols {
	public:
		Symbols() {}

		void AddLabel(const string& labelName, TMappedType value) {
			_labelMapping.insert(pair<string, TMappedType>(labelName, value));
		}
		bool Contains(const string& labelName) const {
			auto it = _labelMapping.find(labelName);
			return it != _labelMapping.end();
		}
		TMappedType GetLabelValue(const string& labelName) const {
			return _labelMapping.at(labelName);
		}

	private:
		map<string, TMappedType> _labelMapping;
	};
}