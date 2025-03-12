#include <iostream>
#include <random>
#include <map>
#include <math.h>
#include "../src/scene.cpp"
#include "../src/dbManager.cpp"
#include <chrono>
#include <unistd.h>


#pragma once

//for loading scenes, handling menus, interaction, dialogue, etc.
class manager{

public: 

	manager();

	scene* getCurrent();

	void customizeScene(); //add args

	void wildEncounter(int id);

	void populateGrid(map* grid, int size);

	void tileCheck(map* grid);

	void mainLoop();

	void movePlayer();

	bool boundaryCheck(); //debug version first

	void setCurrent(scene* scn);

	void swapPlayer(tile* t1, tile* t2, trainer* current);

	void resetChoice();

	void interact(trainer* user, tile* pos);

	bool checkEncounter(tile* t); //map - distribution and correlating ID

	int rng(int min, int max);

	bool checkBorder(tile* t);

	void battleMenu();

	void battleChoice(int n);

	void battleBag();

	dbManager* getDB();





	//resolve type here



	//swap scene

private:

	scene* current; //scene loader 

	dbManager* db;

	int choice;

	bool encounter;


};