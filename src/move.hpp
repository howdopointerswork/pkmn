#include <iostream>
#include "type.cpp"


#pragma once

typedef std::string str;

class move{


	public:

		move(str name, int id, type* tp, bool is_physical, int pp, int dmg);

		const str getName();

		const int getID();

		type* getType();

		const bool getPhysical();

		const int getPP();

		void setPP(int pp);

		const int getDmg();



	
	private:

		str name;

		int id;

		type* tp; 

		bool is_physical; //special or physical

		int pp;

		int dmg;

		bool isTM; //false if learned, taught, or HM

};