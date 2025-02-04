#include <iostream>
#include "npc.hpp"

#pragma once

npc::npc(std::string name, int id, int x, int y) : object(id, x, y){

	this->name = name;
	this->talking = false;
	this->id = id;
	
	
}

