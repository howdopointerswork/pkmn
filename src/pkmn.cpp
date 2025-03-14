#include <iostream>
#include "../include/pkmn.hpp"


#pragma once


pkmn::pkmn(int dexnum, str name, type* t1, type* t2): type1(t1), type2(t2){

	this->factor = 1.0;

	this->dexnum = dexnum;

	this->name = name;

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


void pkmn::setNature(int nature){

	this->nature = nature;
}
		

str pkmn::getName(){

	return this->name;
}

//for evolving if needed
void pkmn::setName(str name){

	this->name = name;
}

unsigned int pkmn::getStat(int id){ //check 48-55

	if(id <= 5){
		return this->stats[id];

	}

	return 0;
}

void pkmn::addStats(int hp, int atk, int def, int spatk, int spdef, int spd){

	this->stats.push_back(hp);
	this->stats.push_back(atk);
	this->stats.push_back(def);
	this->stats.push_back(spatk);
	this->stats.push_back(spdef);
	this->stats.push_back(spd);


}

void pkmn::setStat(int id, int val){

	this->stats[id] = val;
}

int pkmn::getDexNo(){

	return this->dexnum;
}

bool pkmn::insertMove(move* mv){

	unsigned int pre = this->moveset.size()+1;

	if(this->moveset.size() < 4){
		this->moveset.push_back(*mv);
	}

	return (pre == this->moveset.size() ? true : false);
}




void pkmn::printMoveset(){

	for(auto i=0; i<this->moveset.size(); ++i){

		std::cout << this->moveset.at(i).getName() << std::endl;
	}

}

int pkmn::movesetSize(){

	return this->moveset.size();
}

int getHealth(){

	return this->health;
}

void setHealth(int h){

	this->health = h;
}