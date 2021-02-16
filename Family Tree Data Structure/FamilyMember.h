#pragma once
#include "pch.h"
#include "IdGenerator.h"
#include "Person.h"
#include "Relationship.h"
#include "tree_serializations.h"

namespace Iman_familytree {

	class FamilyMember
	{
	public: 
		friend class FamilyTree;
		using rel_type = Relationship::RelationshipType;


		FamilyMember() :m_person_details{}, m_children{}, 
			m_parent{}, m_spouse{}{};
		explicit FamilyMember(Person);  //throws invalid argument Person must have name 

		//getters
		const std::shared_ptr<Person>& getPerson();
		const std::vector<Relationship>& getRelationship(const rel_type) const;
		
		//operations
		void addRelationship(const rel_type, const std::shared_ptr<Person>&);
		void deleteRelationship(const rel_type, const std::shared_ptr<Person>&);

		template<typename Generator>
		void usernameGenerator(const Person&);

		//Serialize
		template<class Archive>
		inline void serialize(Archive& ar, const unsigned int file_version){
			ar & m_id &  m_person_details & m_children & m_parent & m_spouse;
		}

	private:
		std::string m_id{};
		std::shared_ptr<Person> m_person_details;
		
		std::vector<Relationship> m_children{};
		std::vector<Relationship> m_parent{};
		std::vector<Relationship> m_spouse{};

	private:
		//helpers function
		bool RelationshipExists(std::vector<Relationship>& relation_list, const Relationship& t_relation);
		void deleteFromList(std::vector<Relationship>&, const Relationship&);

	};

	template<typename Generator>
	inline void FamilyMember::usernameGenerator(const Person& t_user)
	{
		m_id = Generator(t_user);
	}

}

