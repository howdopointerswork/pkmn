#include <iostream>
#include "map.cpp"
#include "npc.cpp"
#include "trainer.cpp"


struct choice{

	std::string txt;

	int num;

};




int main(){

	srand(time(0));
	
	std::cout << "Hello, my name is Professor C." << std::endl;

	std::cout << "Welcome to the world of Pokemon!" << std::endl;

	std::cout << "Here you will live alongside these wonderous creatures." << std::endl;

	//set these two vars to choice struct

	choice input;

	std::string name; 

	while(input.num != 0){

		std::cout << "Tell me, what is your name?" << std::endl;
		
		std::cin >> input.txt;

		std::cout << "So your name is " << name << "? (1 for yes)" << std::endl;

		std::cin >> input.num;

	}

	int r = rand()%9999999999+0000000000;
	trainer player(name, r); //make pointer
	std::cout << player.getID() << std::endl;


	//create trainer here with name
	//and randomize id




	return 0;
}