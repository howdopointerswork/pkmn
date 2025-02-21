#include <iostream>
#include <cassert>
#include "../src/dbManager.cpp"


int main(){

	dbManager* db = new dbManager();

	assert(db->openFile("txt/dex.txt") == true);

	db->db_CreateTable();
/*
	db->db_clearTable();
	db->resetAutoInc();
	db->insertFromFile();
*/
	//db->printSelect(25);

	std::cout << "All tests passed" << std::endl;

	return 0;
}