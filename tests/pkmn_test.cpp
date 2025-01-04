#include <iostream>
#include <cassert>
#include "../src/pkmn.cpp"
#include "../src/calc.cpp"



int main(){

	std::string arr[19] = {"none", "normal", "fire", "water", "grass", "electric", "psychic", "fighting", "dark", "steel", "bug", "flying", "poison", "ice", "ground", "rock", "dragon", "ghost", "fairy"};

	calc* cal = new calc();

	type* t1 = new type(2);

	type* t2 = new type(0);

	move* mv = new move("Test Move", 1, t1, false, 10, 50);



	cal->setType(t1);

	cal->setType(t2);


	pkmn* pk = new pkmn(t1, t2, 1, "Pokemon1", 35, 50, 37, 35, 50, 40, 5, 80, "Adamant");


	assert(t1->getName() == "Fire");

	assert(mv->getType()->getName() == "Fire");

	
	for(int i=0; i<19; i++){

		std::cout << arr[i] << ": ";
		cal->calculate(pk, i);
		std::cout << pk->getFactor() << std::endl;
		pk->resetFactor();
	}

	std::cout << "All Tests Passed" << std::endl;


	delete mv;

	delete t1;

	delete cal;

	delete pk;


	return 0;
}