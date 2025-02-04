#include <iostream>
#include "object.cpp"

#pragma once


typedef std::string str;

class npc : public object{

public:

	//constructor

	npc(str name, int id, int x, int y);

	//read from txt files or db later
	void setDialogue();



private:

	str name;

	str dialogue;

	bool talking;

	int id;

	

};