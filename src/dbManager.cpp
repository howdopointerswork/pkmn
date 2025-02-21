#include <iostream>
#include "dbManager.hpp"

#pragma once

dbManager::dbManager(){

	this->db_Open();
	this->db_CreateTable();


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

	std::string query = "INSERT INTO dex (name) VALUES('" + name + "');";

	const char* insert = query.c_str();

	err = sqlite3_exec(db, insert, nullptr, nullptr, &msg);

	if(err != SQLITE_OK){

		std::cerr << "Error: " << sqlite3_errmsg(db) << std::endl;
		return 0;
	}

	std::cout << "Successfully inserted value(s)" << std::endl;
	return 1;
}



bool dbManager::openFile(std::string open){

	file.open(open);

	return file.is_open() ? true : false;
}


void dbManager::insertFromFile(){


	std::string line;

	while(std::getline(file, line)){

		//std::cout << line << std::endl;
		db_Insert(line);
	}
}




void dbManager::db_Close(){

	sqlite3_close(db);
}



static int callback(void* data, int argc, char** argv, char** colname){


	std::cout << argv[1] << std::endl;

	return 0;
}


void dbManager::printSelect(int num){

	std::string query = "SELECT * FROM dex WHERE id=" + std::to_string(num) + ";";

	const char* select = query.c_str();

	err = sqlite3_exec(db, select, callback, nullptr, &msg);

	if(err != SQLITE_OK){

		std::cerr << "Error: " << sqlite3_errmsg(db) << std::endl; 
	}
	else{

		std::cout << "Select statement executed successfully" << std::endl;
	}
}



void dbManager::db_clearTable(){

	std::string query = "DELETE FROM dex;";

	const char* del = query.c_str();

	err = sqlite3_exec(db, del, nullptr, nullptr, &msg);

	if(err != SQLITE_OK){

		std::cerr << "Error: " << sqlite3_errmsg(db) << std::endl; 
	}
	else{

		std::cout << "Delete statement executed successfully" << std::endl;
	}
}


void dbManager::resetAutoInc(){

	std::string query = "DELETE FROM sqlite_sequence WHERE name = 'dex';";

	const char* autoinc = query.c_str();

	err = sqlite3_exec(db, autoinc, nullptr, nullptr, &msg);

	if(err != SQLITE_OK){

		std::cerr << "Error: " << sqlite3_errmsg(db) << std::endl; 
	}
	else{

		std::cout << " Auto Increment reset successfully" << std::endl;
	}

}