#include <iostream>
#include "../include/move.hpp"

#pragma once

typedef std::string str;

move::move(int id, type* tp, int dmg, int pp, int cat, str name, int acc){

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

const str move::getName(){

	return this->name;
}