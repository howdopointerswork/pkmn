#include <iostream>
#include <stdexcept>
#include "pkmn.cpp"
#include "calc.cpp"


int main(){

//Tried override with virtual but c++11 is too new
	
//1 - normal


//4 - grass
/*
6 - psychic
7 - fighting
8 - dark
9 - steel
10 - bug
11 - flying
12 - poison
13 - ice
14 - ground
15 - rock
16 - dragon
17 - ghost
18 - fairy

*/
	std::string arr[19] = {"none", "normal", "fire", "water", "grass", "electric", "psychic", "fighting", "dark", "steel", "bug", "flying", "poison", "ice", "ground", "rock", "dragon", "ghost", "fairy"};
	int input;
	calc c;


while(true){

	for(int i=0; i<19; ++i){

		std::cout << i << ": " << arr[i] << std::endl;

	}

	std::cout << "Enter type 1 (0 for none): ";

	
	std::cin >> input;

	if(input >= 0 && input < 19){
			
		type* t1 = new type(input);
		std::cout << "Enter type 2 (0 for none): ";
		std::cin >> input;


		if(input >=0 && input < 19){

			type* t2 = new type(input);
			pkmn* p = new pkmn(t1, t2);
			c.setType(t1);
			c.setType(t2);

			for(int i=0; i<19; i++){

				std::cout << arr[i] << ": ";
				c.calculate(p, i);
				std::cout << p->getFactor() << std::endl;
				p->resetFactor();
			}

			delete p;
			p = nullptr;

			delete t1;
			t1 = nullptr;

			delete t2;
			t2 = nullptr;
		}

		else{

			continue;
		}
		

	}

	else{

		continue;
		
	}

	std::cout << std::endl << std::endl;
	std::cout << "Press 1 to recalculate or anything else to quit" << std::endl;
	std::cin >> input;

	if(input == 1){

		continue;
	}
	else{

		break;
	}
}





	return 0;
}