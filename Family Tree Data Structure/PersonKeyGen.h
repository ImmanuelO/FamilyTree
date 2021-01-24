#pragma once
#include <string>



namespace Iman_familytree {
	class PersonKeyGen
	{
		class Person; //fwd decl
	public:
		inline std::string operator()(const Person&) const;
	};
}
