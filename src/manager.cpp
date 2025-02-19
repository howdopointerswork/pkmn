#include <iostream>
#include "manager.hpp"
#include <math.h>

#pragma once

//1 regular tile
//2 immovable tile (object)
//3 wild grass
//4 border


manager::manager(){

	this->choice = -1;

}

//rename from grid - confusing
void manager::populateGrid(map* grid, int size){

	//change to make it so grids are customizable
	//or make custom scenes for each
	// and a struct to hold these scenes

	int count = 0;

	for(int i=0; i<size; ++i){

		for(int j=0; j<size; ++j){


			if(i==4 && j<=4){
				std::cout << "J: " << j << std::endl;
				count = 2;
			}
			else if((i>=2 && i<=3) && j<=3){

				count = 3;
			}
			else if((i>=5 && i<=6) && j==0){

				count = 4;
			}
			else{

				count = 1;
				std::cout << "J (else): " << j << std::endl;
			}

			grid->addTile(new tile(count, j, i));
			std::cout << "Initializing tile: " << grid->getTile(grid->getSize()-1)->getX() << " " << grid->getTile(grid->getSize()-1)->getY() << std::endl; 
			

		}

	}


}




void manager::tileCheck(map* grid){

	

	for(int i=0; i<grid->getSize(); ++i){

		grid->getTile(i)->isPassable();

	}

}




void manager::mainLoop(){



}




void manager::movePlayer(){


	while(this->choice != 0){
		std::cout << "Move which way?" << std::endl;
		std::cout << "0. Quit" << std::endl;
		std::cout << "1. Up" << std::endl;
		std::cout << "2. Left" << std::endl;
		std::cout << "3. Right" << std::endl;
		std::cout << "4. Down" << std::endl;
		std::cout << "5. Interact" << std::endl;
		//add menu and change actions based on context

		std::cin >> choice; 
		this->boundaryCheck();

		//boundary check

	}


}


//to be refactored with args
//debug version
bool manager::boundaryCheck(){ //change to move function

	//variables here

	 trainer* user = this->current->getPlayer();
	 map* area = this->current->getGrid();
	 std::string result;
	
	 int size = pow(area->getSize(), 0.5);
	 int xy = size*(user->getY()); //current position
	 int xyu = size*(user->getY()+1); //one row up
	 int xyd = size*(user->getY()-1); //one row down



	switch(this->choice){


			case 0:

				std::cout << "Quitting.." << std::endl;

				break;
				//sleep here

			case 1:
				//put coordinates on these 
				//multiple ifs for debugging

				//move the player from tile to tile

				std::cout << "Moving up.." << std::endl;

				if(area->isInBoundsY(user, size, true)){

						 //1,1: 6
	 

					std::cout << "In bounds" << std::endl;

					if(xy+user->getX() < area->getSize()-size){

						if(area->isTileEmpty(xyu+user->getX())){
								
								user->setDir(this->choice);
								swapPlayer(area->getTile(xy+user->getX()), area->getTile(xyu+user->getX()), user);
								user->move(this->choice);
								user->matchDir(user->getX(), user->getY());
								std::cout << "X: " << user->getX() << std::endl;
								std::cout << "Y: " << user->getY() << std::endl;

								std::cout << "ID: " << area->getTile(xyu+user->getX())->getID() << std::endl;

								return true;
						}
						else{

							std::cout << "Error: Tile is occupied" << std::endl;
							user->setDir(this->choice);
						
							user->matchDir(area->getTile(xyu+user->getX())->getX(), area->getTile(xyu+(user->getX()))->getY());

						}		

					}
					else{

						std::cout << "Error: Bad indexing" << std::endl;


					}

				}
				else{

					std::cout << "Error: Out of bounds" << std::endl;
			
				}

				break;

			case 2:

				if(area->isInBoundsX(user, size, false)){

					std::cout << "Moving left.." << std::endl;
					
					//separate
					if(user->getX()-1 >= 0){

						if(area->isTileEmpty((xy+user->getX())-1)){

								//
								user->setDir(this->choice);
								std::cout << "ID: " << area->getTile(xy+user->getX()-1)->getID() << std::endl;
								swapPlayer(area->getTile(xy+user->getX()), area->getTile(xy+user->getX()-1), user);
								std::cout << "ID: " << area->getTile(xy+user->getX()-1)->getID() << std::endl;
								user->move(choice);
								std::cout << "ID: " << area->getTile(xy+user->getX()-1)->getID() << std::endl;
								user->matchDir(user->getX(), user->getY());
								std::cout << "X: " << user->getX() << std::endl;
								std::cout << "Y: " << user->getY() << std::endl;

								std::cout << "ID: " << area->getTile(xy+user->getX()-1)->getID() << std::endl;

								return true;
						}
						else{
							
							std::cout << "Tile is occupied" << std::endl;
							user->setDir(this->choice);
							user->matchDir(area->getTile(xy+user->getX()-1)->getX(), area->getTile(xy+(user->getX()-1))->getY());
					
						}
						

					}
					else{

						std::cout << "Error: Bad indexing" << std::endl;
					}
				}
				else{

					std::cout << "Error: Out of bounds" << std::endl;
				
				}

				break;

			case 3:


				if(area->isInBoundsX(user, size, true)){

					std::cout << "Moving right.." << std::endl;
					
					//separate
					if(user->getX()+1 < size){
 
						if(area->isTileEmpty(xy+user->getX()+1)){
								user->setDir(this->choice);
								swapPlayer(area->getTile(xy+user->getX()), area->getTile(xy+user->getX()+1), user);
								user->move(this->choice);
								user->matchDir(user->getX(), user->getY());
								std::cout << "X: " << user->getX() << std::endl;
								std::cout << "Y: " << user->getY() << std::endl;

								std::cout << "ID: " << area->getTile(xy+user->getX()+1)->getID() << std::endl;
								return true;
						}
						else{
							//fix occupied error 

							std::cout << "Tile is not empty: " << xy+1 << std::endl;
							user->setDir(this->choice);
							user->matchDir(area->getTile(xy+user->getX()+1)->getX(), area->getTile(xy+(user->getX()+1))->getY());
						}
					}
					else{

						std::cout << "Error: Bad indexing" << std::endl;
					}
				}
				else{

					std::cout << "Error: Out of bounds" << std::endl;
				}	

				
				break;

			case 4:
		
				if(area->isInBoundsY(user, size, false)){

					std::cout << "Moving down.." << std::endl;
					
					//separate

					if(xy-user->getX() > 0){


						if(area->isTileEmpty(xyd+user->getX())){
							//size*y-1
							//2,1 = 11
							//1,1 = 6
							//xyd = 5*(1) = 5+1 = 6
							//
								user->setDir(this->choice);
								swapPlayer(area->getTile(xy+user->getX()), area->getTile(xyd+user->getX()), user);
								user->move(this->choice);
								user->matchDir(user->getX(), user->getY());
								std::cout << "X: " << user->getX() << std::endl;
								std::cout << "Y: " << user->getY() << std::endl;

								std::cout << "ID: " << area->getTile(xyd+user->getX())->getID() << std::endl;
								return true;
						}
						else{

							std::cout << "Error: Tile is occupied" << std::endl;
							user->setDir(this->choice);
							user->matchDir(area->getTile(xyd+user->getX())->getX(), area->getTile(xyd+(user->getX()))->getY());
						}

						
					}
					else{

						std::cout << "Error: Bad indexing" << std::endl;
					}	
				}
				else{

					std::cout << "Error: Out of bounds" << std::endl;
				}	
				
				break;

			case 5:
				
				//user->matchDir(this->choice);
				std::cout << "Interacting..." << std::endl;
				
				tile* tmp;
				std::cout << "Here" << std::endl;

				//if(typeid(*area->getTile(xy+user->getX()+1)->getCurrent()) == typeid(general)){

				//	std::cout << "Good" << std::endl;
				//}

				switch(user->getDir()){

					case 1:
						tmp = area->getTile(xyu+user->getX());
						break;
					case 2:
						tmp = area->getTile(xy+user->getX()-1);
						break;
					case 3:
						tmp = area->getTile(xy+user->getX()+1);
						break;
					case 4:
						tmp = area->getTile(xyd+user->getX());
						break;

				}


				interact(user, tmp);
				result = user->canInteract() ? "Interaction: Facing Object" : "Interaction: Not Facing Object";
				std::cout << result << std::endl;

				//check dir here and pass to interact

				//interaction calls here
				return true;
				break;



			default:

				std::cout << "Unknown input" << std::endl;	
				std::cout << "X: " << user->getX() << std::endl;
				std::cout << "Y: " << user->getY() << std::endl;


				
				break;


		}





	return false;

}




void manager::setCurrent(scene* scn){

	this->current = scn;
}


scene* manager::getCurrent(){


	return this->current;
}


void manager::swapPlayer(tile* t1, tile* t2, trainer* current){

	//dynamic cast
	t2->setCurrent(dynamic_cast<trainer*>(current));
	t1->setCurrent(nullptr);

	//this->current->getPlayer()->matchDir(t2->getX(), t2->getY());

	std::string result;
		
	//result = this->current->getPlayer()->canInteract() ? "Interaction Detected" : "No Interaction Detected..";

	//std::cout << result << std::endl;	

}


void manager::resetChoice(){


	this->choice = -1;
}


void manager::interact(trainer* user, tile* pos){

	std::cout << "Interact function called" << std::endl;

	//for debugging
	switch(user->getDir()){

		case 1:
			std::cout << "Interact function: Up" << std::endl;
			break;
		case 2:
			std::cout << "Interact function: Left" << std::endl;
			break;
		case 3:
			std::cout << "Interact function: Right" << std::endl;
			break;
		case 4:
			std::cout << "Interact function: Down" << std::endl;
			break;

	}


	//check each type of item? can use ||
	//general for now for debugging
	if(typeid(*pos->getCurrent()) == typeid(general)){

		std::cout << "Interacting with type: Item" << std::endl;
		//handle item here
		//type cast
		//pos->setCurrent(dynamic_cast<general*>(pos->getCurrent()));
		user->addItem(dynamic_cast<general*>(pos->getCurrent()));
		pos->removeCurrent();
	}
	else if(typeid(*pos->getCurrent()) == typeid(medicine)){

		user->addItem(dynamic_cast<medicine*>(pos->getCurrent()));
		pos->removeCurrent();
	}
	else if(typeid(*pos->getCurrent()) == typeid(pokeball)){

		user->addItem(dynamic_cast<pokeball*>(pos->getCurrent()));
		pos->removeCurrent();
	}
	else if(typeid(*pos->getCurrent()) == typeid(berry)){

		user->addItem(dynamic_cast<berry*>(pos->getCurrent()));
		pos->removeCurrent();
	}
	else if(typeid(*pos->getCurrent()) == typeid(battle)){

		user->addItem(dynamic_cast<battle*>(pos->getCurrent()));
		pos->removeCurrent();
	}
	else if(typeid(*pos->getCurrent()) == typeid(tmhm)){

		user->addItem(dynamic_cast<tmhm*>(pos->getCurrent()));
		pos->removeCurrent();
	}
	else if(typeid(*pos->getCurrent()) == typeid(npc)){

		std::cout << "Interacting with type: NPC" << std::endl;
		dynamic_cast<npc*>(pos->getCurrent())->setDialogue("Hello World!");
		dynamic_cast<npc*>(pos->getCurrent())->speak();

	}
	else if(typeid(*pos->getCurrent()) == typeid(object)){

		std::cout << "Interacting with type: Object" << std::endl;
		
	}
	else{

		std::cout << "Interacting with type: Unknown" << std::endl;
	}

	std::cout << "Tile at Interact: " << pos->getX() << ", " << pos->getY() << std::endl;
}