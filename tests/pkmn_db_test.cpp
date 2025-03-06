#include <iostream>
#include <cassert>
#include "../src/manager.cpp"
#include "../src/calc.cpp"

int main(){

	manager* mgr = new manager();
	calc* cal = new calc();
	std::string arr[18] = {"normal", "fire", "water", "grass", "electric", "psychic", "fighting", "dark", "steel", "bug", "flying", "poison", "ice", "ground", "rock", "dragon", "ghost", "fairy"};



	mgr->getDB()->printSelect(1);

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

	return 0;
}