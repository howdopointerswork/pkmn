#include <iostream>
#include "dbManager.hpp"

#pragma once

dbManager::dbManager(){

	this->db_Open();
}


bool dbManager::db_Open(){

	err = sqlite3_open("../db/pokedex.db", &db);

	if(err != SQLITE_OK){

		std::cerr << "Error: " << sqlite3_errmsg(db) << std::endl;
		return 0;
	}

	std::cout << "Successfully opened database" << std::endl;
	return 1;
}






bool dbManager::db_CreateTable(){

	const char* makeTable = "CREATE TABLE IF NOT EXISTS dex (id INTEGER PRIMARY KEY AUTOINCREMENT, name TEXT NOT NULL);";

	err = sqlite3_exec(db, makeTable, nullptr, nullptr, &msg);

	if(err != SQLITE_OK){

		std::cerr << "Error: " << msg << std::endl;
		return 0;
	}


	std::cout << "Created table successfully" << std::endl;
	return 1;
	

}


bool dbManager::db_Insert(std::string name){

	std::string query = "INSERT INTO dex VALUES('" + name + "');";

	const char* insert = query.c_str();

	err = sqlite3_exec(db, insert, nullptr, nullptr, &msg);

	if(err != SQLITE_OK){

		std::cerr << "Error: " << sqlite3_errmsg(db) << std::endl;
		return 0;
	}

	std::cout << "Successfully inserted value(s)" << std::endl;
	return 1;
}



bool dbManager::openFile(std::string file){

	std::ifstream inFile(file);

	return inFile.is_open() ? true : false;
}


void dbManager::insertFromFile(std::ifstream file){


	std::string line;

	while(std::getline(file, line)){

		db_Insert(line);
	}
}




void dbManager::db_Close(){

	sqlite3_close(db);
}
