#pragma once
#include "pch.h"
#include <algorithm>
#include <functional>
#include <iterator>
#include <string>
#include <random>


namespace Iman_familytree {
	struct Person; //fwd decl

	//Class to generate a 32 bit unique identifier
	//implemented with the mersenne twister engine to 
	//generate the unique intergers giving a possible range of ID's 
	//from 0 <= IdGenerator <= 2^(32) - 1 (4,294,967,295)  
	//this will be used as a primary key in Family tree
	class IdGenerator
	{
	public:
		IdGenerator();
		uint32_t operator()();

		template<class T = std::mt19937, std::size_t N = T::state_size * sizeof(typename T::result_type)>
		auto properlyseededrandomengine() {
			std::random_device source;
			std::random_device::result_type random_data[(N - 1) / sizeof(source()) + 1];
			std::generate(std::begin(random_data), std::end(random_data), std::ref(source));
			std::seed_seq seeds(std::begin(random_data), std::end(random_data));
			return T(seeds);

		}

	private:
		std::mt19937 m_Id_generator;
	
	};

}
