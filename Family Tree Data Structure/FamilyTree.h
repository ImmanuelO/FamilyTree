#pragma once
#include "pch.h"
#include <db_cxx.h>
#include <list>
#include<string>
#include "FamilyDB.h"
#include "FamilyMember.h"





namespace Iman_familytree {
	class FamilyTree
	{
		FamilyTree();
		~FamilyTree() {};

	private:
		FamilyDB m_db_handler;

		

		std::string starting_user_key;
		std::list<FamilyMember> starting_user_tree;

	private:
		void db_configuration();
	};
}
