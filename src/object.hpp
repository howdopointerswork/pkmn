#include <iostream>


class object{
	
public:

	virtual ~object() = default;

	object();

	const int getX();

	const int getY();

	void setX(int x);

	void setY(int y);

private:

	int x;

	int y;	

};