#ifndef GENERAL_H
#define GENERAL_H

#include <string>
#include <map>
#include <vector>

namespace utility {

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

}

#endif
