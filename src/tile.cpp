#include <iostream>
#include <cstdint>
#include <typeinfo>
#include "tile.hpp"



#pragma once



tile::tile(int id){

	this->id = id;

	this->passable = true;

	this->current = nullptr;



	//initialize here

}


int tile::getID(){


	return this->id;
}


bool tile::checkPassable(){


	return this->passable;
}

void tile::checkInteract(bool interact){


	interact ? (typeid(this->getCurrent() == typeid(item) ? this->removeCurrent() : (typeid(this->getCurrent()) == typeid(npc) ? std::cout << "Handle NPC Here" << std::endl : std::cout << "Object is not an Item or NPC")) : std::cout << "Interact boolean is false");

}


void tile::changePassable(bool passable){


	this->passable = passable;
}


bool tile::isPassable(){

	if(this->current == nullptr){

		passable = true;
	}

	else{

		passable = false;
	}

	return this->passable;


}


void tile::addCurrent(object* onTile){

	this->current = onTile;

	this->passable = false;
}


object* tile::getCurrent(){


	return this->current;
}




void tile::removeCurrent(){

	this->current = nullptr;

	this->passable = true;
}