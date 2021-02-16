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
		std::string m_person1_uuid{};
		std::string m_person2_uuid{};

		bool operator==(const Relationship& b) const;
	};

} //Iman_familytree
