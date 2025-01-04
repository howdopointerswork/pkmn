#include <iostream>
#include "item.hpp"




item::item(std::string name, int id){

		this->name = name;

		this->id = id;

		this->qty = 1;

}






void item::incQty(){

	this->qty++;

}

void item::decQty(){

	this->qty--;
}


const int item::getID(){

	return this->id;
}


/*void item::use(){

	if(this->checkQty() > 0){



		return;


	}

}*/



general::general(std::string name, int id) : item(name, id){


}




void general::effect(int id){

	return;

}



medicine::medicine(int type, int amount, std::string name, int id) : item(name, id){

	this->type = type;
	this->amount = amount;

}


void medicine::effect(int id){

	return;

}

//medicine constructor should call super constructor


pokeball::pokeball(int catchrate, std::string name, int id) : item(name, id){


	this->catchrate = catchrate;;

}



void pokeball::effect(int id){

	return;

}



berry::berry(int type, int amount, std::string name, int id) : item(name, id){

	this->type = type;

	this->amount = amount;



}



void berry::effect(int id){

	return;

	
}



battle::battle(int num, std::string name, int id) : item(name, id){


	this->num = num;
}


void battle::effect(int id){

	return;
	
}


tmhm::tmhm(move* mv, std::string name, int id) : item(name, id){

	this->mv = mv;

}


void tmhm::effect(int id){

	return;
}


key::key(std::string name, int id) : item(name, id){



}



void key::effect(int id){

	return;	
}