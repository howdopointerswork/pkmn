#include <iostream>
#include "item.hpp"




item::item(int id, int x, int y) : object(id, x, y){

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



general::general(int id, int x, int y) : item(id, x, y){


}




void general::effect(int id){

	return;

}



medicine::medicine(int type, int amount, int id, int x, int y) : item(id, x, y){

	this->type = type;
	this->amount = amount;

}


void medicine::effect(int id){

	return;

}

//medicine constructor should call super constructor


pokeball::pokeball(int catchrate, int id, int x, int y) : item(id, x, y){


	this->catchrate = catchrate;;

}



void pokeball::effect(int id){

	return;

}



berry::berry(int type, int amount, int id, int x, int y) : item(id, x, y){

	this->type = type;

	this->amount = amount;



}



void berry::effect(int id){

	return;

	
}



battle::battle(int num, int id, int x, int y) : item(id, x, y){


	this->num = num;
}


void battle::effect(int id){

	return;
	
}


tmhm::tmhm(move* mv, int id, int x, int y) : item(id, x, y){

	this->mv = mv;

}


void tmhm::effect(int id){

	return;
}


key::key(int id, int x, int y) : item(id, x, y){



}



void key::effect(int id){

	return;	
}