#include <iostream>
#include <typeinfo>
#include "trainer.hpp"


#pragma once

typedef std::string str;

trainer::trainer(str name, int id, int x, int y) : object(id, x, y) {

	this->name = name;

	this->badges = 0;

	this->money = 0;

	this->canMove = true;

	

}


const str trainer::getName(){

	return this->name;

}


const pkmn* trainer::getPartyPkmn(int num){


	return this->party[num];
}


/*const int trainer::getID(){


	return this->id;
}*/


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

//for debugging
//to be removed
void trainer::checkDir(int choice){

	//ULRD

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



}


void trainer::setDir(int dir){


	this->dir = dir;

	std::string current;

	switch(this->dir){

		case 1:
			current = "Up";
			break;
		case 2:
			current = "Left";
			break;
		case 3:
			current = "Right";
			break;
		case 4:
			current = "Down";
			break;	
	}

	std::cout << "Current direction: " << current << std::endl;
}


const int trainer::getDir(){

	return this->dir;

}


void trainer::matchDir(int x, int y){

	//need to check for coordinate and direction
	//and make interact true

	//ULRD

	//map is bottom-left to right and up

	//facing up, y+1 and x=x
	if(this->dir == 1 && this->getX() == x && this->getY() == y-1){

		this->interact = true;

	}//facing left, y=y, x=x-1
	else if(this->dir == 2 && this->getX() == x+1 && this->getY() == y){

		this->interact = true;

	}//facing right, y=y, x=x+1
	else if(this->dir == 3 && this->getX() == x-1 && this->getY() == y){
		std::cout << "Interaction is true" << std::endl;
		std::cout << "X: " << this->getX() << " Y: " << this->getY() << std::endl;
		std::cout << "X: " << x-1 << " Y: " << y << std::endl;
		this->interact = true;
	}//facing down, y=y+1
	else if(this->dir == 4 && this->getX() == x && this->getY() == y+1){
		std::cout << "Check down" << std::endl;
		this->interact = true;
	}
	else{

		this->interact = false;
	}

	

	std::cout << "Interact: " << this->interact << std::endl;
	


	//compare x and y

}


bool trainer::canInteract(){

	return this->interact;
}


void trainer::move(int mv){
//prints for debugging
	if(canMove){

		switch(mv){

			case 1:
				//up
				setY(getY() + 1);
				std::cout << "X in function: " << this->getX() << std::endl;
				std::cout << "Y in function: " << this->getY() << std::endl;
				//this->setDir(mv);
				break;

			case 2:
				//left
				setX(getX() - 1);
				std::cout << "X in function: " << this->getX() << std::endl;
				std::cout << "Y in function: " << this->getY() << std::endl;
			//	this->setDir(mv);
				break;

			case 3:
				//right
				setX(getX() + 1);
				std::cout << "X in function: " << this->getX() << std::endl;
				std::cout << "Y in function: " << this->getY() << std::endl;
				//this->setDir(mv);
				break;
			

			case 4:
				//down
				setY(getY() - 1);
				std::cout << "X in function: " << this->getX() << std::endl;
				std::cout << "Y in function: " << this->getY() << std::endl;
				//this->setDir(mv);	
				break;
		}

		

	}
}


/*void trainer::interact(tile* t, int dir){

	if(this->interact){

		switch(dir){

			case 1:
				std::cout << "UP" << std::endl;
				break;
			case 2:
				std::cout << "LEFT" << std::endl;
				break;	
			case 3:
				std::cout << "RIGHT" << std::endl;
				break;	
			case 4:
				std::cout << "DOWN" << std::endl;
				break;
		}
	}
	else{

		std::cout << "Cannot interact" << std::endl;
	}
}*/


/*void trainer::removeItem(int id){


	if()
}*/
//search by id?
