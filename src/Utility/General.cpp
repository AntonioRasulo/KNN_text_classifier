#include "General.hpp"

namespace utility {

	void stripUnicode(std::string& str)
	{
		str.erase(remove_if(str.begin(), str.end(), invalidChar), str.end());
	}

	bool invalidChar(char c)
	{
		return !(c >= -1 && c <= 255);
	}

	bool isWordAccepted(const std::string& word)
	{
		return bool(std::find(englishGrammar.begin(), englishGrammar.end(), word) != englishGrammar.end() ? false : true);
	}

}
