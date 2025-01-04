#include <iostream>
#include "move.hpp"

#pragma once

typedef std::string str;

move::move(str name, int id, type* tp, bool is_physical, int pp, int dmg){

	this->name = name;

	this->id = id;

	this->tp = tp;

	this->is_physical = is_physical;

	this->pp = pp;

	this->dmg = dmg;
}


type* move::getType(){


	return this->tp;
}