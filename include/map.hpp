#include <iostream>
#include <vector>
#include "tile.cpp"

#pragma once

class map{

public:

	map();

	tile* getTile(int i); //const?

	tile* getTile_xy(int x, int y);

	void addTile(tile* t);

	void emptyGrid();

	void setX(int min, int max);

	void setY(int min, int max);

	const int getMinX();

	const int getMaxX();

	const int getMinY();

	const int getMaxY();

	int getSize();

	//need checkTile to see if occupied

	bool isTileEmpty(int index);

	//move player

	//check bounds
	bool isInBoundsX(object* obj, int lim, bool lr);

	bool isInBoundsY(object* obj, int lim, bool ud);




private:


	std::vector<tile*> grid;

	int minX;

	int maxX;

	int minY;

	int maxY;


};