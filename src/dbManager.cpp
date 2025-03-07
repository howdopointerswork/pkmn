#include <iostream>
#include "../include/dbManager.hpp"

#pragma once





static int callback(void* data, int argc, char** argv, char** colname){


	std::cout << argv[1] << std::endl;
	std::cout << argc << std::endl;
	std::vector<std::string> vec;

	col.clear();

	for(auto i=0; i<argc; ++i){
			std::string amal;	
			int j = 0;         
			while(argv[i][j] != '\0'){

				amal += argv[i][j];
				++j;
			}

			std::cout << "String: " << amal << std::endl;
			
			vec.push_back(amal);
			col.push_back(amal);
			//std::cout << col.at(0) << std::endl;
			//col->push_back(result);
	}

	for(auto k = 0; k<argc; ++k){

		std::cout << vec.at(k) << std::endl;
		std::cout << "col: " << col.at(k) << std::endl;
	}
	return 0;
}



static int callbackMulti(void* data, int argc, char** argv, char** colname){


	std::cout << argv[1] << argv[2] << argv[3] << std::endl;

	return 0;
}


 static void substring(std::string line, int i, int last, std::vector<std::string>* vec, int n){

 		std::cout << "Size is: " << vec->size() << std::endl;
		if(vec->size() == n || i == line.length()){

			return;
		}
		else{

			while(line[i] != ' '){

				++i;

			
			}
			vec->push_back(line.substr(last, i-last));
			last = i+1;
			substring(line, ++i, last, vec, n);
		}
}




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
		
		return 0;
	}
	else{

		std::cout << "Inserted successfully" << std::endl;
	}

	return true;
}


bool dbManager::db_Insert(std::vector<std::string> vec){

	/*int type = std::stoi(vec[0]);
	int dmg = std::stoi(vec[1]);
	int pp = std::stoi(vec[2]);
	int cat = std::stoi(vec[3]);
	int acc = std::stoi(vec[5]);*/

	//vec[4] is name string
	std::cout << "Size check: " << vec.size() << std::endl;
	std::string query = "INSERT INTO moves (type, dmg, pp, phys_spec, name, acc) VALUES (" + vec[0] + ", " + vec[1] + ", " + vec[2] + ", " + vec[3] + ", '" + vec[4] + "', " + vec[5] + ");";

	const char* insert = query.c_str();
	std::cout << "Before exec" << std::endl;
	err = sqlite3_exec(db, insert, nullptr, nullptr, &msg);
	std::cout << "After exec" << std::endl;
	if(err != SQLITE_OK){

		std::cerr << "Error: " << sqlite3_errmsg(db) << std::endl;

		return 0;
	}
	else{

		std::cout << "Inserted successfully" << std::endl;

	}
	

	return 1;

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


void dbManager::loadMoves(){

	std::string line;
	int i=0;
	int last = 0;
	std::vector<std::string> vec;
	while(std::getline(file, line)){

		while(i < line.length()){

			if(line.at(i) == ' '){

	
				std::cout << line.substr(last,i-last) << std::endl;
			//	std::cout <<  << std::endl;
				vec.push_back(line.substr(last,i-last));
				last = i+1;
				
				
			}
			++i;
		}

		if(line.substr(line.length()-4,1) == " "){

			std::cout << "3 length acc" << std::endl;
			std::cout << line.substr(line.length()-3, 3) << std::endl;
			vec.push_back(line.substr(line.length()-3, 3));
		}
		else{

			std::cout << "2 length acc" << std::endl;
			std::cout << line.substr(line.length()-2, 2) << std::endl;
			vec.push_back(line.substr(line.length()-2, 2));
		}
		
		std::cout << "Made it here" << std::endl;
		std::cout << "First size check: " << vec.size() << std::endl;
		db_Insert(vec);
		i=0;
		last = i;
		vec.clear();
			

	}		
}



void dbManager::db_Close(){

	sqlite3_close(db);
}



void dbManager::printSelect(int num, std::string table){

	std::string query = "SELECT * FROM " + table + " WHERE id=" + std::to_string(num) + ";";

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

	std::string query = "DELETE FROM moves;";

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

	std::string query = "DELETE FROM sqlite_sequence WHERE name = 'moves';";

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

std::string dbManager::getData(int i){

	return col.at(i);
}


void dbManager::fixDex(){

	int id = 356;

	if(id <= 561){
		
		std::string query = 
		"UPDATE dex SET 
		t1 =(SELECT t1 WHERE id=" + std::to_string(id+1) + "), 
		t2 =(SELECT t2 WHERE id=" + std::to_string(id+1) + "), 
		
		;";

		const char* update = query.c_str();

		err=sqlite3_exec(db, add, nullptr, nullptr, &msg);

		if(err != SQLITE_OK){

			std::cerr << "Error: " << sqlite3_errmsg(db) << std::endl;
		}
		else{

			std::cout << "Added column successfully" << std::endl;
	}

	}

}