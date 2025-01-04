#include <iostream>
#include <cassert>
#include <typeinfo>
#include "../src/tile.cpp"
#include "../src/calc.cpp"



int main(){

	//item here	
	
	trainer* user = new trainer("User", 1);

	item* generalItem = new general("Item1", 1);

	tile* tl = new tile(4);

	
	assert(tl->getCurrent() == nullptr);

	assert(tl->checkPassable() == true);

	assert(tl->isPassable() == true);

	

	tl->addCurrent(generalItem);

	assert(typeid(*tl->getCurrent()) == typeid(general));

	assert(tl->getCurrent() != nullptr);

	assert(tl->checkPassable() == false);

	assert(tl->isPassable() == false);

	

	tl->removeCurrent();

	assert(tl->getCurrent() == nullptr);

	assert(tl->checkPassable() == true);

	assert(tl->isPassable() == true);	



	tl->addCurrent(user);

	assert(typeid(*tl->getCurrent()) == typeid(trainer));

	assert(tl->getCurrent() != nullptr);

	assert(tl->checkPassable() == false);

	assert(tl->isPassable() == false);



	tl->removeCurrent();

	assert(tl->getCurrent() == nullptr);

	assert(tl->checkPassable() == true);

	assert(tl->isPassable() == true);


	//for npc here


	

	std::cout << "All Tests Passed." << std::endl;

	delete user;

	delete generalItem;

	delete tl;

	return 0;
}