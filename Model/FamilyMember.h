#pragma once
#include "pch.h"
#include "IdGenerator.h"
#include "Person.h"
#include "Relationship.h"
#include "Serializations.h"

namespace Iman_familytree {

	class boost::serialization::access;   //fwd decl

	class FamilyMember
	{
	public: 
		using rel_type = Relationship::Type;
		using person_shptr = std::shared_ptr<Person>;

		FamilyMember() : m_person_details{}, m_children{}, 
			m_parent{}, m_spouse{}{};
		
		explicit FamilyMember(Person);  //throws invalid argument Person must have name 

		//getters
		const person_shptr& getPerson();
		const std::vector<Relationship>& getRelationship(const rel_type) const;
		
		//operations
		void addRelationship(const rel_type, const person_shptr&);
		void deleteRelationship(const rel_type, const person_shptr&);

	
	private:
		std::shared_ptr<Person> m_person_details;
		
		std::vector<Relationship> m_children{};
		std::vector<Relationship> m_parent{};
		std::vector<Relationship> m_spouse{};

	//helper function
	private:
		inline Relationship&& createRelationship(const rel_type, uint32_t t_person_id);
		inline bool RelationshipExists(std::vector<Relationship>& relation_list, const Relationship& t_relation);
		inline void deleteFromList(std::vector<Relationship>&, const Relationship&);

		//Serialize
		template<class Archive>
		inline void serialize(Archive& ar, const unsigned int file_version) {
			ar & m_person_details & m_children & m_parent & m_spouse;
		}

		friend class FamilyTree;    //family tree data structure
		friend class boost::serialization::access;  //serialization
	};

}

