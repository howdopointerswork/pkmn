#include <iostream>
#include "scene.hpp"


#pragma once


scene::scene(){

	this->active = false;

}


map* scene::getGrid(){

	return this->grid;

}



trainer* scene::getPlayer(){

	return this->player;
}



npc* scene::getNPC(int i){

	return this->npcs[i];
}



item* scene::getItem(int i){

	return this->items[i];
}


void scene::emptyScene(){

	this->grid = nullptr;

	this->player = nullptr;

	this->npcs.clear();

	this->items.clear();

	delete this->grid;

	delete this->player;

	//iterate through vectors and make null/delete??
}


void scene::addNPC(npc* add){

	this->npcs.push_back(add);
}


void scene::addItem(item* add){

	this->items.push_back(add);

}

void scene::activate(){

	this->active = true;
}

void scene::deactivate(){

	this->active = false;
}



void scene::setPlayer(trainer* t){

	this->player = t;
}


void scene::setGrid(map* m){

	this->grid = m;
}



void scene::vec_add(std::array<int,2> arr){

	this->vec.push_back(arr);
}

void scene::vec_clear(){

	this->vec.clear();

}

int scene::getRate(int index){

	return this->vec[index][1];
}

int scene::getID(int index){

	return this->vec[index][0];
}

int scene::vec_size(){

	return this->vec.size();
}

std::vector<std::array<int, 2>> scene::getVec(){

	return this->vec;
}
