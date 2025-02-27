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

bool dbManager::db_CreatePCTable(){

	const char* makeTable = "CREATE TABLE IF NOT EXISTS pc (id INTEGER, name TEXT, lvl INTEGER, inParty INTEGER, isShiny INTEGER, status INTEGER, m1 INTEGER, m2 INTEGER, m3 INTEGER, m4 INTEGER, FOREIGN KEY (id) REFERENCES dex(id) );";

	err = sqlite3_exec(db, makeTable, nullptr, nullptr, &msg);

	if (err != SQLITE_OK){

		std::cerr << "Error: " << msg << std::endl;
		return 0;
	}
	std::cout << "Created table successfully" << std::endl;
	return 1;
}


bool dbManager::db_CreateMoveTable(){

	const char* makeTable = "CREATE TABLE IF NOT EXISTS moves (id INTEGER PRIMARY KEY AUTOINCREMENT, type INTEGER, dmg INTEGER, pp INTEGER, phys_spec INTEGER);";

	err = sqlite3_exec(db, makeTable, nullptr, nullptr, &msg);

	if(err != SQLITE_OK){

		std::cerr << "Error: " << msg << std::endl;
		return 0;
	}
	std::cout << "Created table successfully" << std::endl;
	return 1;


}


void dbManager::FK_ON(){

	sqlite3_exec(db, "PRAGMA foreign_keys = ON;", nullptr, nullptr, &msg);
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



bool dbManager::db_Insert(int t1, int t2){


	std::string query = "INSERT INTO dex (name, type1, type2) VALUES(''," + std::to_string(t1) + ", " + std::to_string(t2) + ");";

	const char* insert = query.c_str();

	err = sqlite3_exec(db, insert, nullptr, nullptr, &msg);

	if(err != SQLITE_OK){

		std::cerr << "Error: " << sqlite3_errmsg(db) << std::endl;
		
		return 1;
	}
	else{

		std::cout << "Inserted successfully" << std::endl;
	}

	return true;
}



bool dbManager::openFile(std::string open){

	file.open(open);

	return file.is_open() ? true : false;
}


void dbManager::closeFile(){

	file.close();
}


void dbManager::insertFromFile(){


	std::string line;

	while(std::getline(file, line)){

		//std::cout << line << std::endl;
		db_Insert(line);
	}
}


void dbManager::loadTypes(){

	std::string line;
	int count = 0;



	while(std::getline(file, line)){

		//split here
		//convert to ints here
		//insert both here

		std::cout << "line: " << line << std::endl; 
		std::cout << "line subtr: " << line.substr(0,line.size()) << std::endl;

		int i=1;

		while(line.at(i) != ' '){

			++i;
		}

		std::cout << line.substr(0,i) << std::endl;
		std::cout << line.substr(i+1, line.size()) << std::endl;

		int t1 = std::stoi(line.substr(0,i));
		int t2 = std::stoi(line.substr(i+1,line.size()));

		std::cout << "t1: " << t1 << std::endl;
		std::cout << "t2: " << t2 << std::endl;


		db_Insert(t1, t2);

		i=1;

		
	
	

	}


}



void dbManager::db_Close(){

	sqlite3_close(db);
}



static int callback(void* data, int argc, char** argv, char** colname){


	std::cout << argv[1] << std::endl;

	return 0;
}


static int callbackMulti(void* data, int argc, char** argv, char** colname){


	std::cout << argv[1] << argv[2] << argv[3] << std::endl;

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



void dbManager::printSelectType(int id, int t1, int t2){

	std::string query = "SELECT * FROM dex WHERE id=" + std::to_string(id) + " AND type1=" + std::to_string(t1) + " AND type2=" + std::to_string(t2) + ";";

 	const char* select = query.c_str();

 	err = sqlite3_exec(db, select, callbackMulti, nullptr, &msg);

 	if(err != SQLITE_OK){

 		std::cerr << "Error: " << sqlite3_errmsg(db) << std::endl;


 	}else{

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


void dbManager::addCol(){


	std::string query = "ALTER TABLE moves ADD COLUMN acc INTEGER;";


	const char* add = query.c_str();

	err=sqlite3_exec(db, add, nullptr, nullptr, &msg);

	if(err != SQLITE_OK){

		std::cerr << "Error: " << sqlite3_errmsg(db) << std::endl;
	}
	else{

		std::cout << "Added column successfully" << std::endl;
	}


}


void dbManager::begin(){

	sqlite3_exec(db, "BEGIN TRANSACTION;", 0, 0, 0);
}


void dbManager::commit(){

	sqlite3_exec(db, "COMMIT;", 0, 0, 0);
}


void dbManager::close(){

	sqlite3_close(db);
}

void dbManager::update(){

	int i=1;

	std::string line;

	while(std::getline(file, line)){

		std::string query = "UPDATE dex SET name = '" + line + "' WHERE id=" + std::to_string(i) + ";";
		const char* update = query.c_str();

		err=sqlite3_exec(db, update, nullptr, nullptr, &msg);

		if(err !=SQLITE_OK){

			std::cerr << "Error: " << sqlite3_errmsg(db) << std::endl;
		}
		else{
			std::cout << "Updated successfully" << std::endl;
		}

		++i;

	}



}