#include <iostream>
#include <vector>
#include "../src/type.cpp"
#include "../src/pkmn.cpp"

#pragma once


class calc{

public:

	void setType(type* t);

	void calculate(pkmn* p, int type);

	bool checkVecs(std::vector<int> v, int alt);

	bool isEffective(type* atk, type* def);

	

	
};