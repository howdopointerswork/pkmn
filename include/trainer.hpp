#include <iostream>
#include <vector>
#include "pkmn.cpp"
#include "item.cpp"
#include "object.cpp"




#pragma once

typedef std::string str;
typedef std::vector<item*> pocket;




class trainer : public object{

public:

	trainer(str name, int id, int x, int y); //constructor

	const str getName(); //get name of trainer

	const pkmn* getPartyPkmn(int num); //get party pokemon by index

	const int getID(); //get trainer id

	const int getBadges(); //get number of badges

	const int getMoney(); //get money

	void incBadges(); //increment badge count by 1

	void setMoney(int amount); //set trainer money

	void addMoney(int amount); //add trainer money, can be negative

	void stop(); //stop player from moving

	void go(); //allow player to move

	void addItem(item* toAdd); //add item to bag based on subclass type

	const bool checkItemExists(item* toCheck, int n); //check if item is in bag for qty

	const item* getItem(); //returns an item for use/selection

	const int getPocketSize(int n); //get amount of unique items in pocket

	const int getPocketSizeQty(int n); //get amount of unique/non-unique items

	void removeItem(int id);

	const int getDir();

	void checkDir(int choice);

	void matchDir(int x, int y);

	void setDir(int dir);

	void move(int mv); //check for canMove bool

	bool canInteract();



	//reset position
	//set both x and y



private:

	str name; //trainer name

//	int id; //trainer id

	int dir; //direction user is facing based on last movement

	int x; //x coordinate

	int y; //y coordinate

	int badges; //number of badges

	int money; //money

	bool canMove; //determines if trainer can move

	bool interact; //interact with NPCs, items, etc.

	pkmn* party[6]; //array of 6 pokemon

	pocket bag[7]; //bag with 7 pockets
	//items
	//key
	//med
	//ball
	//berry
	//battle
	//tm/hm


};