#include <iostream>
#include <cassert>
#include <typeinfo>
#include "../src/tile.cpp"
#include "../src/calc.cpp"



int main(){
	


	//will condense assertions into functions
	trainer* user1 = new trainer("User", 1, 0, 0);

	item* generalItem = new general(1, 0, 0);

	npc* comp1 = new npc("Breeder", 1, 0, 0);

	tile* tl = new tile(4, 0, 0);

	
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



	tl->addCurrent(user1);

	assert(typeid(*tl->getCurrent()) == typeid(trainer));

	assert(tl->getCurrent() != nullptr);

	assert(tl->checkPassable() == false);

	assert(tl->isPassable() == false);



	tl->removeCurrent();

	assert(tl->getCurrent() == nullptr);

	assert(tl->checkPassable() == true);

	assert(tl->isPassable() == true);


	//for npc here
	tl->addCurrent(comp1);


	assert(typeid(*tl->getCurrent()) == typeid(npc));

	assert(tl->getCurrent() != nullptr);

	assert(tl->checkPassable() == false);

	assert(tl->isPassable() == false);	

	

	tl->removeCurrent();

	assert(tl->getCurrent() == nullptr);

	assert(tl->checkPassable() == true);

	assert(tl->isPassable() == true);

	std::cout << "All Tests Passed." << std::endl;

	delete user1;

	delete generalItem;

	delete comp1;

	delete tl;

	return 0;
}