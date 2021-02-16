
#include "pch.h"
#include "IdGenerator.h"


namespace Iman_familytree {
	IdGenerator::IdGenerator() :
		m_Id_generator(properlyseededrandomengine()) 
	{
	}
	uint32_t IdGenerator::operator()()
	{
		return m_Id_generator();
	}
}