#include <iostream>
#include <typeinfo>
#include "trainer.hpp"


#pragma once

typedef std::string str;

trainer::trainer(str name, int id){

	this->name = name;

	this->id = id;

	this->badges = 0;

	this->money = 0;

	

}


const str trainer::getName(){

	return this->name;

}


const pkmn* trainer::getPartyPkmn(int num){


	return this->party[num];
}


const int trainer::getID(){


	return this->id;
}


const int trainer::getBadges(){

	return this->badges;
}


const int trainer::getMoney(){


	return this->money;
}




void trainer::incBadges(){

	//8 or 16?

	if(this->badges < 16){
	
		++this->badges;
	}

}


void trainer::setMoney(int amount){


	this->money = amount;
}


void trainer::addMoney(int amount){

	this->money += amount;
}


void trainer::addItem(item* toAdd){

	//can't do array so using if/else

	//check through pocket and see if id
	//is already there, if so
	//inc qty

	//check here

	if(typeid(*toAdd) == typeid(general) && !this->checkItemExists(toAdd, 0)){

		this->bag[0].push_back(toAdd);
		//put with if statement to check

	}
	else if(typeid(*toAdd) == typeid(medicine) && !this->checkItemExists(toAdd, 1)){

		this->bag[1].push_back(toAdd);
	}

	else if(typeid(*toAdd) == typeid(pokeball) && !this->checkItemExists(toAdd, 2)){

		this->bag[2].push_back(toAdd);
	}

	else if(typeid(*toAdd) == typeid(tmhm) && !this->checkItemExists(toAdd, 3)){

		this->bag[3].push_back(toAdd);
	}

	else if(typeid(*toAdd) == typeid(berry) && !this->checkItemExists(toAdd, 4)){

		this->bag[4].push_back(toAdd);
	}

	else if(typeid(*toAdd) == typeid(battle) && !this->checkItemExists(toAdd, 5)){

		this->bag[5].push_back(toAdd);
	}

	else if(typeid(*toAdd) == typeid(key) && !this->checkItemExists(toAdd, 6)){

		this->bag[6].push_back(toAdd);
	}

}


const bool trainer::checkItemExists(item* toCheck, int n){

	for(int i=0; i<this->bag[n].size(); i++){

		if(toCheck->getID() == this->bag[n].at(i)->getID()){

			this->bag[n].at(i)->incQty();
			return true;
		}
	}
	return false;
}


const int trainer::getPocketSize(int n){

	return this->bag[n].size();
}


void trainer::stop(){

	this->canMove = false;
}


void trainer::go(){

	this->canMove = true;
}

int trainer::checkDir(int choice){

	switch(choice){

		case 1:

			this->setDir(choice);
			break;

		case 2:
			
			this->setDir(choice);
			break;

		case 3:

			this->setDir(choice);
			break;

		case 4:
		
			this->setDir(choice);
			break;

	}


	return this->getDir();

}


void trainer::setDir(int dir){


	this->dir = dir;
}


int getDir(){

	return this->dir;

}



/*void trainer::removeItem(int id){


	if()
}*/
//search by id?
