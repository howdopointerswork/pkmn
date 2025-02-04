#include <iostream>
#include <stdio.h>
#include "move.cpp"
#include "object.cpp"

#pragma once


class item : public object{


public:

	item(int id, int x, int y);

	//virtual ~item() = default;

	virtual void effect(int id) = 0;

	void decQty();

	void incQty();

	const bool checkQty();

	const int getID();

	void use();





private:

	bool toUse; //holdable only or also usable

	bool canUse; //whether or not the item can be used

	std::string name; //name of the item

	int id; //id of the item to be used in switch cases

	int qty; //quantity of the item

	

};



class general : public item{

public:

	general(int id, int x, int y);

	void effect(int id) override;




};


class medicine : public item{
//need to account for status condition

public:

	medicine(int type, int amount, int id, int x, int y);

	void effect(int id) override;

	//status, health, revive, pp?
	//1 for status and which - amount
	//2 or health and how much - amount
	//3 for pp and how much - amount
	//no need for 4

	const int getAmount();

	const int getType();


private:
	
	int amount;

	int type;


};

class pokeball : public item{

public:

	pokeball(int catchrate, int id, int x, int y);

	void effect(int id) override;

private:

	int catchrate;

};





class berry : public item{

public:

	berry(int type, int amount, int id, int x, int y);	

	void effect(int id) override;

private:

	//consider medicine
	//but also holding, toUse can be false

	int amount;

	int type;

};


class battle : public item{

public:

	battle(int num, int id, int x, int y); //which stat

	void effect(int id) override;

private:

	int num;

};


class tmhm : public item{

public: 

	tmhm(move* mv, int id, int x, int y);

	void effect(int id) override;

private: 

	move* mv;

};


class key : public item{

public:

	key(int id, int x, int y);

	void effect(int id) override;

};