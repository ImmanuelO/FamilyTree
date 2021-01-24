#pragma once
#include <db_cxx.h>
#include <list>
#include<string>
#include "FamilyDB.h"
#include "FamilyMember.h"





namespace Iman_familytree {
	class FamilyTree
	{
		FamilyTree();
		~FamilyTree();

	private:
		char* FAM_ENV_DIR{ nullptr };
		char* FAM_DB_DIR{ nullptr };
		FamilyDB m_db_handler;
		DbEnv* famEnv{ nullptr };
		Db* famDb{ nullptr };
		

		std::string starting_user_key;
		std::list<FamilyMember> starting_user_tree;

	private:
		void db_configuration();
	};
}
