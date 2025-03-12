#include <iostream>
#include <cassert>
#include "../src/manager.cpp"
#include "../src/calc.cpp"

int main(){

	manager* mgr = new manager();
	calc* cal = new calc();
	std::string arr[18] = {"normal", "fire", "water", "grass", "electric", "psychic", "fighting", "dark", "steel", "bug", "flying", "poison", "ice", "ground", "rock", "dragon", "ghost", "fairy"};
	


	mgr->getDB()->printSelect(1, "dex");

	mgr->getDB()->close();
	//std::cout << "Data Size: " << mgr->getDB()->dataSize() << std::endl;
	//std::cout << "Size: " << size << std::endl;
	for(int i=0; i<col.size(); ++i){
	
		std::cout << "Vector: " << col.at(i)	<< std::endl;
	}
	type* grass = new type(std::stoi(col.at(2)));
	type* poison = new type(std::stoi(col.at(3)));
	pkmn* bulbasaur = new pkmn(std::stoi(col.at(0)), col.at(1), grass, poison);	

	cal->setType(bulbasaur->type1);
	cal->setType(bulbasaur->type2);
	
	std::cout << "Array: " << arr[0] << std::endl;
	for(auto j=1; j<18; ++j){
		cal->calculate(bulbasaur, j); 
		std::cout << arr[j-1] << ": " << bulbasaur->getFactor() << std::endl;
		bulbasaur->resetFactor();
	}
	mgr->getDB()->db_Open();
	mgr->getDB()->printSelect(6, "moves");

	std::cout << "Expected: 7 " << "Actual: " << col.size() << std::endl;
	std::cout << col.at(1) << std::endl;
	move* mv = new move(std::stoi(col.at(0)), new type(std::stoi(col.at(1))), std::stoi(col.at(2)), std::stoi(col.at(3)), std::stoi(col.at(4)), col.at(5), std::stoi(col.at(6)));

	std::cout << "Move name: " << mv->getName() << std::endl;

	mgr->getDB()->printSelect(384, "dex");

	type* dragon = new type(std::stoi(col.at(2)));
	type* flying = new type(std::stoi(col.at(3)));
	pkmn* rayquaza = new pkmn(std::stoi(col.at(0)), col.at(1), dragon, flying);	
	

	cal->setType(bulbasaur->type1);
	cal->setType(bulbasaur->type2);

	std::cout << rayquaza->getName() << std::endl;
	std::cout << rayquaza->type1->getID() << std::endl;
	std::cout << rayquaza->type2->getID() << std::endl;

	

	std::cout << "Inserting move..." << rayquaza->insertMove(mv) << std::endl;;
	rayquaza->printMoveset();
	std::cout << "Right here" << std::endl;
	//clean up
	/*delete grass;
	delete poison;*/
	delete bulbasaur;

	/*delete mv;
	delete dragon;
	delete flying;*/
	delete rayquaza;

	
	delete cal;
	delete mgr;



	return 0;
}