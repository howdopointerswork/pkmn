#include <iostream>
#include "../src/object.cpp"

#pragma once


typedef std::string str;

class npc : public object{

public:

	//constructor

	npc(str name, int id, int x, int y);

	//read from txt files or db later
	void setDialogue(str txt);

	void speak();

	str getDialogue();




private:

	str name;

	str dialogue;

	bool talking;

	int id;

	

};