#include <iostream>
#include "../include/npc.hpp"

#pragma once

npc::npc(std::string name, int id, int x, int y) : object(id, x, y){

	this->name = name;
	this->talking = false;
	this->id = id;
	
	
}


void npc::setDialogue(std::string txt){

	this->dialogue = txt;
}


void npc::speak(){

	std::cout << this->dialogue << std::endl;
}


std::string npc::getDialogue(){

	return this->dialogue;
}



