#include <iostream>
#include "type.cpp"


#pragma once

typedef std::string str;

class move{


	public:

		move(int id, type* tp, int dmg, int pp, int cat, str name, int acc);

		const str getName();

		const int getID();

		type* getType();

		const int getCat();

		const int getPP();

		void setPP(int pp);

		const int getDmg();



	
	private:

		str name;

		int id;

		type* tp; 

		int cat; //category - 0 for status, 1 for physical, 2 for special

		int pp;

		int dmg;

		int acc;

		bool isTM; //false if learned, taught, or HM

};