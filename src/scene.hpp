#include <iostream>
#include "map.cpp"


#pragma once


class scene{

public:

	scene();

	map* getGrid();

	trainer* getPlayer();

	npc* getNPC(int i); //get by index

	item* getItem(int i); //get by index

	void emptyScene();

	void addNPC(npc* add);

	void addItem(item* add);

	void activate();

	void deactivate();

	void setPlayer(trainer* t);

	void setGrid(map* m);


//88, 136, 160
//22, 34, 40
//
	



private:


	map* grid;

	trainer* player;

	std::vector<npc*> npcs;

	std::vector<item*> items;

	bool active;


};