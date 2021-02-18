#include "pch.h"
#include "FamilyMember.h"
#include "IdGenerator.h"


namespace Iman_familytree {

	FamilyMember::FamilyMember(Person t_person)
	{

		if (!t_person.m_name.fullNameText().empty()) {
			m_person_details = std::make_shared<Person>(t_person);
		}
		else 
			throw std::invalid_argument("Please provides members name");
		
	}

#ifndef NDEBUG
	const std::shared_ptr<Person>& FamilyMember::getPerson()
	{
		return m_person_details;
	}
#endif // DEBUG



	const std::vector<Relationship>& FamilyMember::getRelationship(const rel_type t_relate) const
	{
		switch (t_relate)
		{
		case rel_type::Child:
			return m_children;
		case rel_type::Parent:
			return m_parent;
		case rel_type::Spouse:
			return m_spouse;
		default:
			return m_children;
		}
	}

	void FamilyMember::addRelationship(const rel_type t_relate, const person_shptr& t_person)
	{
		if (t_person != nullptr && !t_person->m_name.fullNameText().empty()) 
		{
			Relationship relation = createRelationship(t_relate, t_person->m_id);

			switch (t_relate)
			{ 
			case rel_type::Child:
				if(!RelationshipExists(m_children,relation))
					m_children.push_back(relation);
				break;
			case rel_type::Parent:
				if (!RelationshipExists(m_parent, relation))
					m_parent.push_back(relation);
				break;
			case rel_type::Spouse:
				if (!RelationshipExists(m_spouse, relation))
					m_spouse.push_back(relation);
				break;
			default:
				break;
			}
		}
	}

 	void FamilyMember::deleteRelationship(const rel_type t_relate, const person_shptr& t_person)
	{
		if (t_person != nullptr && !t_person->m_name.fullNameText().empty()) {
			
			Relationship relation = createRelationship(t_relate, t_person->m_id);

			switch (t_relate)
			{
			case rel_type::Child:
				deleteFromList(m_children, relation);
				break;
			case rel_type::Parent:
				deleteFromList(m_parent, relation);
				break;
			case rel_type::Spouse:
				deleteFromList(m_spouse, relation);
				break;
			default:
				break;
			}
		}
	}

	inline Relationship&& FamilyMember::createRelationship(const rel_type t_rel_type, uint32_t t_person_id)
	{
		Relationship relation;
		relation.m_type = t_rel_type;
		relation.m_person1_id = this->m_person_details->m_id;
		relation.m_person2_id = t_person_id;
		return std::move(relation);
	}

	inline bool FamilyMember::RelationshipExists(std::vector<Relationship>& relation_list, const Relationship& t_relation)
	{
		auto find= std::find(relation_list.begin(), relation_list.end(), t_relation);
		if (find != relation_list.end())
			return true;
		else
			return false;
	}

	inline void FamilyMember::deleteFromList(std::vector<Relationship>& relation_list, const Relationship& t_relation)
	{
		auto it = std::remove(relation_list.begin(), relation_list.end(), t_relation);
		relation_list.erase(it, relation_list.end());
	}




} 