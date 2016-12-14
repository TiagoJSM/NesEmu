#pragma once

#include <map>
#include <vector>

using namespace std;

namespace Assembler6502 {
	template <typename TMappedType>
	class Symbols : public map<string, TMappedType> {
	public:
		Symbols() {}

		void AddLabel(const string& labelName, TMappedType value) {
			this->insert(pair<string, TMappedType>(labelName, value));
		}
		bool Contains(const string& labelName) const {
			auto it = this->find(labelName);
			return it != this->end();
		}
		TMappedType GetLabelValue(const string& labelName) const {
			return this->at(labelName);
		}
		vector<string> Replace(const vector<string>& lines) {
			vector<string> result;
			for (auto iterator = lines.begin(); iterator != lines.end(); iterator++) {
				result.push_back(Replace((*iterator)));
			}
			return result;
		}
		string Replace(const string& line) {
			auto result = line;
			for (auto iterator = this->begin(); iterator != this->end(); iterator++) {
				auto symbol = (*iterator).first;
				auto value = (*iterator).second;
				auto replaceRegex = regex("\\b(" + Convert(symbol) + ")\\b");
				result = regex_replace(result, replaceRegex, value, std::regex_constants::format_sed);
			}
			return result;
		}
	protected:
		virtual string Convert(TMappedType value) = 0;
	};

	class Macros : public Symbols<string> {
	protected:
		string Convert(string value) override {
			return value;
		}
	};

	class Labels : public Symbols<uint16_t> {
	protected:
		string Convert(uint16_t value) override {
			return value + "";
		}
	};
}