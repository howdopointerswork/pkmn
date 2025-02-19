#include <iostream>
#include <sqlite3.h>
#include <string>
#include <fstream>

#pragma once

class dbManager{

public:

	dbManager();

	bool db_CreateTable();

	bool db_Insert(std::string name);

	bool openFile(std::string file); //open file

	void insertFromFile(std::ifstream file);

	void db_Close();






private:

	bool db_Open();

	sqlite3* db;

	int err; //for checking status

	char* msg; //for error message



};