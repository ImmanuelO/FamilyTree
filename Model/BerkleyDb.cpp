#include "pch.h"
#include "BerkleyDb.h"
namespace Iman_familytree {
	BerkleyDb::BerkleyDb():m_famEnv(u_int32_t(0)),
		                 m_famDb(&m_famEnv,u_int32_t(0))
	{
	}
	BerkleyDb::~BerkleyDb()
	{
		m_famDb.close(0);
		m_famEnv.close(DB_FORCESYNC);

	}
}