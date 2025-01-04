#include <stdio.h>
#include <iostream>
#include "trainer.cpp"
#include "npc.cpp"


class tile : public object{

public: 

	tile(int id); //set id, if passable, and current item, null if none

	int getID();

	bool checkPassable(); //returns passable boolean
 
	bool isPassable(); //returns true if current is nullptr

	void checkInteract(bool interact); //check player interact bool, handle, return interact bool

	void changePassable(bool passable);

	void addCurrent(object* onTile);

	void removeCurrent();

	object* getCurrent();



private: 

	int id; //to identify tile type

	size_t size; //for allocating data

	bool passable; //player can pass through

	object* current; //item (if existent) on the tile


};