#include <iostream>
#include <vector>

#pragma once




/*
1 - normal
2 - fire
3 - water
4 - grass
5 - electric
6 - psychic
7 - fighting
8 - dark
9 - steel
10 - bug
11 - flying
12 - poison
13 - ice
14 - ground
15 - rock
16 - dragon
17 - ghost
18 - fairy

*/


class type{

public:

	type(int id);

	void addW(int w);

	void addR(int r);

	void addI(int i);

	const int getID();

	const std::string getName();

	void setName(std::string name);


	std::vector<int> weakness;

	std::vector<int> resistance;

	std::vector<int> immune;

private:

	int id;

	std::string name;


};



