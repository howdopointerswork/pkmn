#include <iostream>
#include "calc.hpp"

#pragma once

/*
1 - normal
2 - fire
3 - water
4 - grass
5 - electric
6 - psychic
7 - fighting
8 - dark
9 - steel
10 - bug
11 - flying
12 - poison
13 - ice
14 - ground
15 - rock
16 - dragon
17 - ghost
18 - fairy

*/

void calc::setType(type* t){


	switch(t->getID()){


		case 1:

			t->setName("Normal");

			t->addW(7);

			t->addI(17);

			break;


		case 2:

			t->setName("Fire");

			t->addW(3);
			t->addW(14);
			t->addW(15);

			t->addR(2);
			t->addR(4);
			t->addR(9);
			t->addR(10);
			t->addR(13);

			break;


		case 3:

			t->setName("Water");

			t->addW(4);
			t->addW(5);

			t->addR(2);
			t->addR(3);
			t->addR(9);
			t->addR(13);

			break;

		case 4:

			t->setName("Grass");

			t->addW(2);
			t->addW(10);
			t->addW(11);
			t->addW(12);
			t->addW(13);

			t->addR(3);
			t->addR(4);
			t->addR(5);
			t->addR(14);

			break;

		case 5:

			t->setName("Electric");

			t->addW(14);

			t->addR(5);
			t->addR(9);
			t->addR(11);

			break;


		case 6:

			t->setName("Psychic");

			t->addW(8);
			t->addW(10);
			t->addW(17);

			t->addR(6);
			t->addR(7);

			break;

		case 7:

			t->setName("Fighting");

			t->addW(6);
			t->addW(11);
			t->addW(18);

			t->addR(8);
			t->addR(10);
			t->addR(15);

			break;


		case 8:

			t->setName("Dark");

			t->addW(7);
			t->addW(10);
			t->addW(18);

			t->addR(8);
			t->addR(17);

			t->addI(6);

			break;


		case 9:

			t->setName("Steel");

			t->addW(2);
			t->addW(7);
			t->addW(14);

			t->addR(1);
			t->addR(4);
			t->addR(6);
			t->addR(9);
			t->addR(10);
			t->addR(11);
			t->addR(13);
			t->addR(15);
			t->addR(16);
			t->addR(18);

			t->addI(12);

			break;


		case 10:

			t->setName("Bug");

			t->addW(2);
			t->addW(11);
			t->addW(15);

			t->addR(4);
			t->addR(7);
			t->addR(14);

			break;


		case 11:

			t->setName("Flying");

			t->addW(5);
			t->addW(13);
			t->addW(15);

			t->addR(4);
			t->addR(7);
			t->addR(10);

			t->addI(14);

			break;

		case 12:

			t->setName("Poison");

			t->addW(6);
			t->addW(14);

			t->addR(4);
			t->addR(7);
			t->addR(10);
			t->addR(12);
			t->addR(18);

			break;

		case 13:

			t->setName("Ice");

			t->addW(2);
			t->addW(7);
			t->addW(9);
			t->addW(15);

			t->addR(13);

			break;


		case 14:

			t->setName("Ground");

			t->addW(3);
			t->addW(4);
			t->addW(13);

			t->addR(12);
			t->addR(13);

			t->addI(5);

			break;


		case 15:

			t->setName("Rock");

			t->addW(3);
			t->addW(4);
			t->addW(7);
			t->addW(9);
			t->addW(14);

			t->addR(1);
			t->addR(2);
			t->addR(11);
			t->addR(12);

			break;

		case 16:

			t->setName("Dragon");

			t->addW(13);
			t->addW(16);
			t->addW(18);

			t->addR(2);
			t->addR(3);
			t->addR(4);
			t->addR(5);

			break;

		case 17:

			t->setName("Ghost");

			t->addW(8);
			t->addW(17);

			t->addR(10);
			t->addR(12);

			t->addI(1);
			t->addI(7);

			break;

		case 18:

			t->setName("Fairy");

			t->addW(9);
			t->addW(12);

			t->addR(7);
			t->addR(8);
			t->addR(10);

			t->addI(16);

			break;


	}


}


bool calc::checkVecs(std::vector<int> v, int alt){

	for(int i=0; i<v.size(); i++){

		if(v.at(i) == alt){

			return true;
		}
	}

	return false;

}



void calc::calculate(pkmn* p, int type){

	if(checkVecs(p->type1->weakness, type)){

		p->altFactor(2.0);
	}
	else if(checkVecs(p->type1->resistance, type)){

		p->altFactor(0.5);
	}
	else if(checkVecs(p->type1->immune, type)){

		p->altFactor(0);
	}

	if(checkVecs(p->type2->weakness, type)){

		p->altFactor(2.0);
	}

	else if(checkVecs(p->type2->resistance, type)){

		p->altFactor(0.5);
	}

	else if(checkVecs(p->type2->immune, type)){

		p->altFactor(0);
	}
	

	

}