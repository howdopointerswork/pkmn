#include <iostream>
#include <cstdint>
#include <typeinfo>
#include <type_traits>
#include "../include/tile.hpp"



#pragma once

//id guide:
//1 regular tile
//2 immovable tile (object)
//3 wild grass
//4 border



tile::tile(int id, int x, int y) : object(id, x, y){ 


	this->passable = true;

	this->current = nullptr;



	//initialize here

}


/*int tile::getID(){


	return this->id;
}*/


bool tile::checkPassable(){


	return this->passable;
}

void tile::checkInteract(bool interact){



	if(interact){

		if(typeid(this->getCurrent()) == typeid(item)){

			this->removeCurrent();
		}
		else if(typeid(this->getCurrent()) == typeid(npc)){
			//check direction as well
			std::cout << "Handle NPC here" << std::endl;
		}

	}
}


void tile::changePassable(bool passable){


	this->passable = passable;
}


void tile::isPassable(){

	if(this->current == nullptr){

		passable = true;
	}

	else{

		passable = false;
	}

	


}



//make objects the type they're passed as



void tile::addCurrent(object* onTile){

	//if block for debugging

	if(typeid(*onTile) == typeid(trainer)){

		std::cout << "Is trainer type" << std::endl;
	}
	else if(typeid(*onTile) == typeid(general)){ //this isn't right

		std::cout << "Is item type" << std::endl;
	}
	else if(typeid(*onTile) == typeid(npc)){

		std::cout << "Is npc type" << std::endl;
	}
	else{

		std::cout << "Unexpected type" << std::endl;
	}




	this->current = onTile;

	this->current->setX(this->getX());

	this->current->setY(this->getY());

	this->passable = false;

}

//any item returned
object* tile::getCurrent(){

	//cast and return

	/*if(typeid(*this->current) == typeid(trainer)){

		std::cout << "Is trainer type at: getCurrent" << std::endl;
		trainer* tr = dynamic_cast<trainer*>(this->current);
		this->removeCurrent();
		this->current = tr;
		
	}*/

	return this->current;


}


//move current here




void tile::removeCurrent(){

	//delete this->current;

	this->current = nullptr;

	this->passable = true;
}


void tile::setCurrent(object* new_current){

	this->current = new_current;

}