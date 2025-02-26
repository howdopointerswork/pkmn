#include <iostream>
#include <cassert>
#include "../src/dbManager.cpp"


int main(){

	dbManager* db = new dbManager();

	assert(db->openFile("txt/types.txt") == true);
	std::cout << "File opened successfully" << std::endl;

	db->begin();
	/*db->db_CreateTable();
	db->db_clearTable();
	db->resetAutoInc();
	//db->insertFromFile();
	//db->addCol();
	db->loadTypes();
	db->closeFile();
	db->openFile("txt/dex.txt");

	//db->db_clearTable();
	db->update();*/
	db->FK_ON();
	db->db_CreatePCTable();
	db->commit();
	db->close();

	//db->printSelectType(24, 5, 0);
/*

	db->db_clearTable();
	
	
*/
	//db->printSelect(25);

	std::cout << "All tests passed" << std::endl;

	return 0;
}