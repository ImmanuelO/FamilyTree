#pragma once
#include "pch.h"

//DB
#include <db_cxx.h>
namespace Iman_familytree {
	class FamilyTree; //fwd decl

	class BerkleyDb
	{
	public:
		BerkleyDb();

		inline DbEnv* getEnv() { return &m_famEnv; }
		inline Db* getDB(){ return &m_famDb; }
	
		virtual ~BerkleyDb();
	
	public:
		char* FAM_ENV_DIR{ nullptr };
		char* FAM_DB_DIR{ nullptr };
		DbEnv m_famEnv;
		Db m_famDb;
	};
}
