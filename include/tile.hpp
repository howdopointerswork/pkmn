#include <stdio.h>
#include <iostream>
#include "../src/object.cpp"
#include "../src/npc.cpp"
#include "../src/trainer.cpp"


#pragma once


class tile : public object{

public: 

	tile(int id, int x, int y); //use object constructor here

	//int getID();

	bool checkPassable(); //returns passable boolean
 
	void isPassable(); //returns true if current is nullptr

	void checkInteract(bool interact); //check player interact bool, handle, return interact bool

	void changePassable(bool passable);

	void addCurrent(object* onTile);

	void removeCurrent();

	object* getCurrent();

	void setCurrent(object* new_current);

	



private: 

	//int id; //to identify tile type

	size_t size; //for allocating data

	bool passable; //player can pass through

	object* current; //item (if existent) on the tile


};