#include <iostream>
#include "../include/type.hpp"

#pragma once

type::type(int id){

	this->id = id;
}


void type::addW(int w){

	this->weakness.push_back(w);

}


void type::addR(int r){

	this->resistance.push_back(r);
}


void type::addI(int i){

	this->immune.push_back(i);

}


const int type::getID(){

	return this->id;
}


const std::string type::getName(){

	return this->name;
}


void type::setName(std::string name){

	this->name = name;
}