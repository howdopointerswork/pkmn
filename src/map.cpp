#include "../include/map.hpp"

#pragma once

map::map(){

	this->minX = 0;

	this->maxX = 0;

	this->minY = 0;

	this->maxY = 0;


}


tile* map::getTile(int i){


	return this->grid[i];

}


int map::getSize(){


	return this->grid.size();
}


void map::addTile(tile* t){
	
	this->grid.resize(this->grid.size()+1);
	this->grid[this->grid.size()-1] = t;

}



void map::emptyGrid(){

	for(int i=0; i < this->grid.size(); ++i){

		this->grid[i] = nullptr;
	}

	this->grid.clear();

}



void map::setX(int min, int max){


	this->minX = min;

	this->maxX = max;

}



void map::setY(int min, int max){


	this->minY = min;

	this->maxY = max;

}


const int map::getMinX(){

	return this->minX;

}


const int map::getMaxX(){

	return this->maxX;

}



const int map::getMinY(){


	return this->minY;
}



const int map::getMaxY(){

	return this->maxY;
}


bool map::isTileEmpty(int index){

	return this->getTile(index)->getCurrent() == nullptr ? true : false;


}

//X version
bool map::isInBoundsX(object* obj, int lim, bool lr){

	std::cout << "X at bound check: " << obj->getX() << std::endl;
	std::cout << "Y at bound check: " << obj->getY() << std::endl;

	if(lr){
		if(obj->getX() < lim){

			return true;

		}
	}else{

		if(obj->getX() > 0){

			return true;
		}
	}


	return false;
}




//Y version
bool map::isInBoundsY(object* obj, int lim, bool ud){

	std::cout << "X at bound check: " << obj->getX() << std::endl;
	std::cout << "Y at bound check: " << obj->getY() << std::endl;
	
	if(ud){
		if(obj->getY() < lim){

			return true;
		}
	}else{

		if(obj->getY() > 0){

			return true;

		}
	}

	return false;
}



