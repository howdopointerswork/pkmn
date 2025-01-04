#include <iostream>
#include <cassert>
#include "../src/trainer.cpp"




int main(){

	trainer* t = new trainer("Trainer", 1234567890);

	assert(t->getName() == "Trainer");

	assert(t->getID() == 1234567890);

	assert(t->getBadges() == 0);

	assert(t->getMoney() == 0);

	t->incBadges();

	assert(t->getBadges() == 1);

	t->addMoney(100);

	assert(t->getMoney() == 100);



	//bag tests / adding items


	item* general1 = new general("Item", 1);

	t->addItem(general1);

	assert(t->getPocketSize(0) == 1);

	delete general1;



	item* medicine1 = new medicine(1, 100, "MooMoo Milk", 5);

	t->addItem(medicine1);

	assert(t->getPocketSize(1) == 1);

	delete medicine1;

	//delete toAdd;

	//test that each item goes into the appropriate pocket

	item* pokeball1 = new pokeball(25, "Great Ball", 2);

	t->addItem(pokeball1);

	assert(t->getPocketSize(2) == 1);

	delete pokeball1;


	//type
	//move
	//tmhm

	//type* type1 = 

	type* type1 = new type(1);

	move* move1 = new move("Test Move", 1, type1, false, 5, 50);

	item* tm01 = new tmhm(move1, "TM01", 1);

	t->addItem(tm01);

	assert(t->getPocketSize(3) == 1);

	delete tm01;
	delete move1;
	delete type1;



	
	item* berry1 = new berry(11, 20, "Test Berry", 71);

	t->addItem(berry1);

	assert(t->getPocketSize(4) == 1);	

	delete berry1;



	item* battle1 = new battle(4, "Atk Boost", 14);

	t->addItem(battle1);

	assert(t->getPocketSize(5) == 1);

	delete battle1;


	
	item* key1 = new key("Key Card", 22);

	t->addItem(key1);

	assert(t->getPocketSize(6) == 1);

	delete key1;


	delete t;

	std::cout << "Tests passed" << std::endl;
	
	


	return 0;
}