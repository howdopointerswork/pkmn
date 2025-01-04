#include <iostream>
#include <vector>
#include "type.cpp"
#include "pkmn.cpp"

#pragma once


class calc{

public:

	void setType(type* t);

	void calculate(pkmn* p, int type);

	bool checkVecs(std::vector<int> v, int alt);


};