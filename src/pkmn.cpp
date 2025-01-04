#include <iostream>
#include "pkmn.hpp"


#pragma once


pkmn::pkmn(type* t1, type* t2, int dexnum, str name, int atk, int def, int spd, int spatk, int spdef, int hp, float ht, float wt, str nature): type1(t1), type2(t2){

	this->factor = 1.0;

	this->dexnum = dexnum;

	this->name = name;

	this->atk = atk;

	this->def = def;

	this->spd = spd;

	this->spatk = spatk;

	this->spdef = spdef;

	this->hp = hp;

	this->ht = ht;

	this->wt = wt;
	

}



void pkmn::altFactor(float alt){

	this->factor*=alt;

}

float pkmn::getFactor(){


	return this->factor;
}

void pkmn::resetFactor(){

	this->factor = 1.0;
}

