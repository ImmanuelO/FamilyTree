#include "pch.h"
#include "Person.h"


namespace Iman_familytree {

	Person::Person() :
		m_gender{ gender::Unkown }
	{}

	Person::Person(Name t_name, gender t_gender):
		m_name{ t_name },
		m_gender{ t_gender }
	{}

	//boost::gregorian::date Person::getDeathdate() const {
	//	if (m_deceased)
	//		return m_deathday;
	//	else
	//		throw std::logic_error("person still living");
	//}
	//void Person::setDeathdate(boost::gregorian::date t_deathday) {
	//	if (m_deceased)
	//		m_deathday = t_deathday;
	//	else
	//		throw std::logic_error("person still living");
	//}


} //Iman_familytree