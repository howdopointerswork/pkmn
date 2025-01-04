#include <iostream>
#include "object.hpp"

object::object(){
	

}


const int object::getX(){


	return this->x;
}



const int object::getY(){


	return this->y;
}


void object::setX(int x){

	this->x = x;
}


void object::setY(int y){

	this->y = y;
}