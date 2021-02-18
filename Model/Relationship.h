#pragma once

#include "Person.h"


namespace Iman_familytree {
	
	struct Relationship
	{
		enum class Type
		{
			Child,
			Parent,
			Spouse
		};

		Type m_type{};
		uint32_t m_person1_id{0};
		uint32_t m_person2_id{0};

		bool operator==(const Relationship& b) const;
	};

} //Iman_familytree
