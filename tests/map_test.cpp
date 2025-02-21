#include <iostream>
#include <cassert>
#include <typeinfo>
#include <math.h>
//#include "../src/map.cpp"
#include "../src/manager.cpp"


int main(){


	map* area1 = new map();

	trainer* p1 = new trainer("User", 192018324, 0, 0);

	item* generalItem = new general(4, 3, 2);
	//int type, int amount, int id, int x, int y
	item* medItem = new medicine(3, 20, 6, 4, 0);

	npc* comp1 = new npc("Breeder", 1, 1, 1);

	scene* scn = new scene();

	manager* mgr = new manager();

	int count = 0;

	int size = 7;

	int sq = pow(size,2);

	int pos = 0; //current index in the vector




	scn->setPlayer(p1);
	scn->vec_add({25,50});
	scn->vec_add({100,30});
	scn->vec_add({10,9});
	scn->vec_add({243,1});

	assert(scn->getPlayer() != nullptr);

	mgr->populateGrid(area1, size);

	area1->getTile(6)->addCurrent(generalItem); //at 1,1
	std::cout << "Test X: " << area1->getTile(6)->getX() << std::endl;
	std::cout << "Test Y: " << area1->getTile(6)->getY() << std::endl;
	area1->getTile(4)->addCurrent(medItem);
	std::cout << "Test X: " << area1->getTile(4)->getX() << std::endl;
	std::cout << "Test Y: " << area1->getTile(4)->getY() << std::endl;	
	//3,4: 0-4, 5-9, 10-14, 15-19, 20-24

	//area1->getTile
	area1->getTile(13)->addCurrent(comp1);
	std::cout << "NPC on: " << area1->getTile(13)->getX() << "," << area1->getTile(13)->getY() << std::endl; 
	//area1->getTile(size)->addCurrent(comp1);

	area1->getTile(0)->addCurrent(p1);

	mgr->tileCheck(area1);
	




	scn->setGrid(area1);

	assert(scn->getGrid() != nullptr);

	std::cout << "Size: " << area1->getSize() << std::endl;

	std::cout << "Size with pow: " << pow(size,2) << std::endl;

	assert(area1->getSize() == static_cast<int>(pow(size,2)));

	mgr->setCurrent(scn);

	assert(mgr->getCurrent() != nullptr);

	assert(typeid(*area1->getTile(0)->getCurrent()) == typeid(trainer));

	assert(typeid(*area1->getTile(4)->getCurrent()) == typeid(medicine));
	//should be item
	assert(typeid(*area1->getTile(6)->getCurrent()) == typeid(general));

	assert(typeid(*area1->getTile(13)->getCurrent()) == typeid(npc));
	
	mgr->movePlayer();

	assert(scn->getPlayer()->getPocketSize(0) == 1);

	assert(scn->getPlayer()->getPocketSize(1) == 1);

	//assert(typeid(*area1->getTile(size)->getCurrent()) == typeid(npc));

	//test movement here

	/*
	assert(area1->getTile(0)->getCurrent() != nullptr);
	assert(area1->getTile(5)->getCurrent() == nullptr);	

	


	//up
	
	assert(area1->getTile(5)->getCurrent() != nullptr);
	assert(area1->getTile(0)->getCurrent() == nullptr);

	area1->getTile(0)->removeCurrent();

	assert(area1->getTile(0)->getCurrent() == nullptr);


	//down

	area1->getTile(5)->addCurrent(p1);


	assert(area1->getTile(5)->getCurrent() != nullptr);
	assert(area1->getTile(0)->getCurrent() == nullptr);	

	mgr->resetChoice();
	mgr->movePlayer();

	
	assert(area1->getTile(0)->getCurrent() != nullptr);
	assert(area1->getTile(5)->getCurrent() == nullptr);


	//left

	area1->getTile(0)->removeCurrent();
	assert(area1->getTile(0)->getCurrent() == nullptr);

	area1->getTile(1)->addCurrent(p1);

	assert(area1->getTile(1)->getCurrent() != nullptr);
	assert(area1->getTile(0)->getCurrent() == nullptr);	

	mgr->resetChoice();
	mgr->movePlayer();

	
	assert(area1->getTile(0)->getCurrent() != nullptr);
	assert(area1->getTile(1)->getCurrent() == nullptr);	




	//right

	area1->getTile(1)->removeCurrent();
	assert(area1->getTile(1)->getCurrent() == nullptr);

	area1->getTile(0)->addCurrent(p1);

	assert(area1->getTile(0)->getCurrent() != nullptr);
	assert(area1->getTile(1)->getCurrent() == nullptr);	

	mgr->resetChoice();
	mgr->movePlayer();

	
	assert(area1->getTile(1)->getCurrent() != nullptr);
	assert(area1->getTile(0)->getCurrent() == nullptr);	
*/



	//interaction here



	//clean up

	area1->emptyGrid();

	assert(area1->getSize() == 0);
	

	std::cout << "All Tests Passed" << std::endl;

	delete area1;

	delete p1;

	delete generalItem;

	delete comp1;

	delete scn;

	delete mgr;


	//"multidimensionall" map here
	//all at x,y = min, max should be obstacles


	return 0;
}