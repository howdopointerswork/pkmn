#include <iostream>
#include <map>
#include "../src/map.cpp"


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

	void printBag();

	void printNPCs();

	void vec_add(std::array<int,2> arr);

	void vec_clear();

	int getRate(int index);

	int getID(int index);

	int vec_size();

	std::vector<std::array<int, 2>> getVec();

	pkmn* getUsr();

	void setUsr(pkmn* p);
	
	pkmn* getTgt();

	void setTgt(pkmn* p);

//88, 136, 160
//22, 34, 40
//
	



private:


	map* grid;
	//for the arrays, [0] is id, [1] is rate
	std::vector<std::array<int, 2>> vec;

	trainer* player;

	pkmn* usr;

	pkmn* tgt;

	std::vector<npc*> npcs;

	std::vector<item*> items;

	bool active;


};