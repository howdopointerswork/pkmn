#include <iostream>


#pragma once


typedef std::string str;

class npc : public object{

public:

	//constructor

	npc(str name);

	//read from txt files or db later
	void setDialogue();



private:

	str name;

	str dialogue;

	bool talking;

	

};