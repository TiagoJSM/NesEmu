#include "Labels.h"

/*namespace Assembler6502 {
	
	template <typename TMappedType>
	Labels<TMappedType>::Labels() {}

	template <typename TMappedType>
	void Labels<TMappedType>::AddLabel(const string& labelName, TMappedType value) const {
		_labelMapping.insert(pair<string, TMappedType>(labelName, value));
	}

	template <typename TMappedType>
	bool Labels<TMappedType>::Contains(const string& labelName) const {
		auto it = _labelMapping.find(labelName);
		return it != _labelMapping.end();
	}

	template <typename TMappedType>
	TMappedType Labels<TMappedType>::GetLabelValue(const string& labelName) const {
		return _labelMapping.at(labelName);
	}

}*/