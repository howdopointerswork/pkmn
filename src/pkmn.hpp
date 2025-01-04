#include <iostream>
#include "type.cpp"
#include "item.hpp"
#include "move.hpp"

#pragma once

typedef std::string str;

class pkmn{
	
	public:

		pkmn(type* t1, type* t2, int dexnum, str name, int atk, int def, int spd, int spatk, int spdef, int hp, float ht, float wt, str nature);

		void altFactor(float alt);

		void resetFactor();

		float getFactor();

		void setNature(str nature);
		
		str getName();

		void setName(str name);

		int getAtk();

		int getDef();

		int getSpd();

		int getHP();

		int getSpAtk();

		int getSpDef();

		int getDexNo();

		str getNature();


		type* type1; //public for now

		type* type2; //public for now



		

	private:



		float factor; //for type calculating

		int atk; //attack

		int def; //defense

		int spd; //speed

		int spatk; //special attack

		int spdef; //special defense

		int hp; //hp

		str name; //name

		float ht; //height

		float wt; //weight

		int dexnum; //dex number

		int lvl; //level

		str nature; //nature

		int status; //status condition

		item* current; //currently held item, based on toUse 

		str egg_group;

		move* moveset[4];


};