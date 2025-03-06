#include <iostream>
#include <cassert>
#include "../src/dbManager.cpp"


int main(){

	dbManager* db = new dbManager();

	std::vector<std::string> vec;
	std::vector<std::string>* v = &vec;
	std::string line = "4 20 25 2 Absorb 100";
	std::cout << "Right here" << std::endl;
	substring(line, 0, 0, v, 6);

	std::cout << "Size: " << vec.size() << std::endl;

	for(auto i=0; i<vec.size(); ++i){

		std::cout << i << ": " << vec[i] << std::endl;
		
	}
	db->printSelect(1);
	/*pkmn p = db->printSelect(1);
	pkmn* pika = &p;
	std::cout << "T1: " << pika->type1->getID() << std::endl;
	std::cout << "T2: " << pika->type2->getID() << std::endl;
	*/

/*	assert(db->openFile("../tests/txt/moves.txt") == true);
	std::cout << "File opened successfully" << std::endl;

	db->begin();
	//db->loadTypes();
	//db->insertFromFile();
	//db->db_clearTable();
	//db->resetAutoInc();

	//std::cout << "Here" << std::endl;
	//db->loadMoves();
	db->commit();
	db->close();


	//db->printSelectType(24, 5, 0);


	
	
	
*/
	//db->printSelect(25);

	std::cout << "All tests passed" << std::endl;

	return 0;
}