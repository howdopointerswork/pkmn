#include <iostream>

#pragma once

class object{
	
public:

	virtual ~object() = default;

//	object();

	object(int id, int x, int y);

	const int getX();

	const int getY();

	void setX(int x);

	void setY(int y);




private:

	int x;

	int y;
	
	int id;

};