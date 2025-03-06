#include <iostream>
#include <vector>
#include "type.cpp"
#include "item.hpp"
#include "move.hpp"

#pragma once

typedef std::string str;

class pkmn{
	
	public:

		pkmn(int dexnum, str name, type* t1, type* t2);

		void altFactor(float alt);

		void resetFactor(); //reset type effects if handling >1 pkmn

		float getFactor(); //type effectiveness 

		void setNature(int nature);
		
		str getName();

		void setName(str name);

		unsigned int getStat(int id); //check 48-55

		void setStat(int id, int val);

		void addStats(int hp, int atk, int def, int spatk, int spdef, int spd);

		int getDexNo();

		int getNature();


		type* type1; //public for now

		type* type2; //public for now
		

	private:



		float factor; //for type calculating

		std::vector<unsigned int> stats; //to hold all stats
		/*
		0 - HP
		1 - Atk
		2 - Def
		3 - Sp. Atk
		4 - Sp. Def
		5 - Spd	
		*/

		str name; //name

		float ht; //height

		float wt; //weight

		int dexnum; //dex number

		int lvl; //level

		int nature; //nature

		int status; //status condition

		int egg_group;

		item* current; //currently held item, based on toUse 

		move* moveset[4];


};