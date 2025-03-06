#include <iostream>
#include <sqlite3.h>
#include <string>
#include <fstream>
#include <vector>
#include <stdexcept>


#pragma once

class dbManager{

public:

	//all non-named non-db associated functions
	//refer to dex table
	//all others have names
	//not overwriting them for debugging purposes

	dbManager();

	bool db_Open();

	bool db_CreateTable();

	bool db_Insert(std::string name);

	bool db_Insert(int t1, int t2);

	bool db_Insert (std::vector<std::string> vec);

	bool openFile(std::string open); //open file

	void closeFile();

	void insertFromFile();

	void printSelect(int num);

	void db_Close();

	void db_clearTable();

	void resetAutoInc();

	void loadTypes();

	void loadMoves();

	void addCol(); //debug

	void printSelectType(int id, int t1, int t2);

	void begin();

	void commit();

	void close();

	//only used for fixing initial insert query
	void update();

	bool db_CreatePCTable(); //all of user's pokemon

	bool db_CreateMoveTable();

	void FK_ON();

	std::string getData(int i);





	//void substring(std::string line, int i, int last, std::<std::string> vec, int n);
	//need bag table

	//and user info table (money, id, progress, badges, etc.) - could do this in txt file as well


private:
	//why private
	
	std::ifstream file;
	
	sqlite3* db;

	int err; //for checking status

	char* msg; //for error message

	

};


std::vector<std::string> col;
