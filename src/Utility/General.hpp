#pragma once

#include <string>
#include <map>
#include <vector>

namespace utility {

	bool invalidChar(char);
	void stripUnicode(std::string&);

	bool isWordAccepted(const std::string& word);

	enum class documentType {
		FOOTBALL,
		COOKING,
		ASTRONOMY,
		COMPUTERSCIENCE,
		ELECTRONICS,
		GEOLOGY,
		GEOGRAPHY,
		MATH,
		COMICBOOK,
		ANATOMY,
		BASKETBALL,
		LITERATUE,
		MUSIC,
		UNKNOWN
	};

	static const std::map<std::string, documentType> stringToEnum = {
		{"Anatomy",documentType::ANATOMY},
		{"Astronomy",documentType::ASTRONOMY},
		{"Basketball",documentType::BASKETBALL},
		{"Comicbook",documentType::COMICBOOK},
		{"Computer_Science",documentType::COMPUTERSCIENCE},
		{"Cooking",documentType::COOKING},
		{"Electronics",documentType::ELECTRONICS},
		{"Football",documentType::FOOTBALL},
		{"Geology",documentType::GEOLOGY},
		{"Literature",documentType::LITERATUE},
		{"Math",documentType::MATH},
		{"Music",documentType::MUSIC},
		{"Geography",documentType::GEOGRAPHY}
	};

	static const std::vector<std::string> englishGrammar = {
	"on",
	"at",
	"in",
	"by",
	"within",
	"from",
	"to",
	"after",
	"until",
	"til",
	"before",
	"since",
	"for",
	"during",
	"over",
	"above",
	"under",
	"around",
	"near",
	"behind",
	"of",
	"across",
	"between",
	"middle",
	"among",
	"toward",
	"into",
	"with",
	"the",
	"a",
	"an",
	"is",
	"has",
	"have",
	"been",
	"then",
	"this",
	"that",
	"who",
	"which",
	"what",
	"when",
	"than",
	"or",
	"and",
	"so",
	"as",
	"all",
	"me",
	"mine",
	"and",
	"be",
	"are",
	"was",
	"also",
	"furthermore",
	"otherwise",
	"up",
	"my",
	"mine",
	"his",
	"i",
	"you",
	"it",
	"they",
	"we"
	};

}
