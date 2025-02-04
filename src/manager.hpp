#include <iostream>
#include "scene.cpp"


#pragma once

//for loading scenes, handling menus, interaction, dialogue, etc.
class manager{

public: 

	manager();

	scene* getCurrent();

	void customizeScene(); //add args

	void forkScene();

	void populateGrid(map* grid, int size);

	void tileCheck(map* grid);

	void mainLoop();

	void movePlayer();

	bool boundaryCheck(); //debug version first

	void setCurrent(scene* scn);

	void swapPlayer(tile* t1, tile* t2, trainer* current);

	void resetChoice();



	//swap scene

private:

	scene* current; //scene loader 

	int choice;


};