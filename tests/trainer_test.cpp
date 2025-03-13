#include <iostream>
#include <cassert>
#include "../src/trainer.cpp"


//dbManager to be used in the future

int main(){

	trainer* t = new trainer("Trainer", 1234567890, 0, 0);

	assert(t->getName() == "Trainer");

	//assert(t->getID() == 1234567890);

	assert(t->getBadges() == 0);

	assert(t->getMoney() == 0);

	t->incBadges();

	assert(t->getBadges() == 1);

	t->addMoney(100);

	assert(t->getMoney() == 100);



	//bag tests / adding items


	item* general1 = new general(3, 4, 2);

	t->addItem(general1);

	assert(t->getPocketSize(0) == 1);

	delete general1;



	item* medicine1 = new medicine(1, 100, 5, 3, 5);

	t->addItem(medicine1);

	assert(t->getPocketSize(1) == 1);

	delete medicine1;

	//delete toAdd;

	//test that each item goes into the appropriate pocket

	item* pokeball1 = new pokeball(20, 1, 0, 1);

	t->addItem(pokeball1);

	assert(t->getPocketSize(2) == 1);

	delete pokeball1;


	//type
	//move
	//tmhm

	//type* type1 = 

	type* type1 = new type(1);

	move* move1 = new move(490, type1, 120, 10, 1, "Thrash", 100);
	//int id, type* tp, int dmg, int pp, int cat, str name, int acc){
	item* tm01 = new tmhm(move1, 490, 5, 5);

	t->addItem(tm01);

	assert(t->getPocketSize(3) == 1);

	delete tm01;
	delete move1;




	
	item* berry1 = new berry(11, 20, 4, 10, 7);

	t->addItem(berry1);

	assert(t->getPocketSize(4) == 1);	

	delete berry1;



	item* battle1 = new battle(4, 14, 0, 6);

	t->addItem(battle1);

	assert(t->getPocketSize(5) == 1);

	delete battle1;


	
	item* key1 = new key(22, 11, 4);

	t->addItem(key1);

	assert(t->getPocketSize(6) == 1);

	delete key1;

	std::cout << "Before party and move tests" << std::endl;

	move* thrash = new move(490, type1, 120, 10, 1, "Thrash", 100);
	type* t1 = new type(1);
	type* t2 = new type(0);
	pkmn* slaking = new pkmn(289, "Slaking", t1, t2);

	t->insertPkmn(slaking);

	assert(t->getPartySize() == 1);

	assert(t->getPartyPkmn(0)->getDexNo() == 289);


	slaking->insertMove(thrash);

	assert(slaking->movesetSize() == 1);

	assert(t->getPartyPkmn(0)->movesetSize() == 1);

	delete type1;
	delete t1;
	delete t2;
	delete thrash;
	delete slaking;
	delete t;


	std::cout << "Tests passed" << std::endl;
	
	
	

	return 0;
}