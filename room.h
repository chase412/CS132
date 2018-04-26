#ifndef ROOM_H
#define ROOM_H
#include <iostream>
#include <string>

//This is a Header file for room class


using namespace std;
class room {
private:
	char building;
	int customer;
	double price;

public:
	room();
	void setBuilding(char);
	void setCustomer(int);
	void setPrice(double);
	char getBuilding();
	int getCustomer();
	double getPrice();
};

#endif
