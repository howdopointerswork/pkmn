#include <iostream>
#include "../include/object.hpp"

#pragma once

object::object(int id, int x, int y){
	
	this->x = x;

	this->y = y;

	this->id = id;

}


const int object::getX(){


	return this->x;
}



const int object::getY(){


	return this->y;
}


void object::setX(int x){

	this->x = x;
	std::cout << this->getX() << std::endl;
}


void object::setY(int y){

	this->y = y;
	std::cout << this->getY() << std::endl;
}


int object::getID(){

	return this->id;
}
