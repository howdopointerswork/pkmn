#include <iostream>
#include "move.hpp"

#pragma once

typedef std::string str;

move::move(str name, int id, type* tp, int cat, int pp, int dmg, int acc){

	this->name = name;

	this->id = id;

	this->tp = tp;

	this->cat = cat;

	this->pp = pp;

	this->dmg = dmg;

	this->acc = acc;
}


type* move::getType(){


	return this->tp;
}