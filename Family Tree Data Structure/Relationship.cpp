#include "pch.h"
#include "Relationship.h"



namespace Iman_familytree {
	bool Relationship::operator==(const Relationship& b) const
	{
		return this->m_type == b.m_type && 
			this->m_person1_key == b.m_person1_key && 
			this->m_person2_key == b.m_person2_key;
	}
}