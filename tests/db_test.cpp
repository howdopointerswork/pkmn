#include <iostream>
#include <cassert>
#include "../src/dbManager.cpp"


int main(){

	dbManager* db = new dbManager();

	assert(db->openFile("../tests/txt/moves.txt") == true);
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
/*

	
	
	
*/
	//db->printSelect(25);

	std::cout << "All tests passed" << std::endl;

	return 0;
}