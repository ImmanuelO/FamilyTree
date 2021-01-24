#pragma once

#include <string>
#include "Person.h"


namespace Iman_familytree {
	
	struct Relationship
	{
		enum class RelationshipType
		{
			Child,
			Parent,
			Spouse
		};

		RelationshipType m_type{};
		std::string m_person1_key{};
		std::string m_person2_key{};

		bool operator==(const Relationship& b) const;
	};

} //Iman_familytree
