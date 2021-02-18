#include "pch.h"
#include "Relationship.h"



namespace Iman_familytree {
	bool Relationship::operator==(const Relationship& b) const
	{
		return this->m_type == b.m_type && 
			this->m_person1_id == b.m_person1_id && 
			this->m_person2_id == b.m_person2_id;
	}
}