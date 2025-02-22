#include <iostream>
#include <sqlite3.h>
#include <string>
#include <fstream>

#pragma once

class dbManager{

public:

	dbManager();

	bool db_Open();

	bool db_CreateTable();

	bool db_Insert(std::string name);

	bool db_Insert(int t1, int t2);

	bool openFile(std::string open); //open file

	void insertFromFile();

	void printSelect(int num);

	void db_Close();

	void db_clearTable();

	void resetAutoInc();

	void loadTypes();

	void addCol(); //debug





private:
	//why private
	
	std::ifstream file;
	
	sqlite3* db;

	int err; //for checking status

	char* msg; //for error message



};