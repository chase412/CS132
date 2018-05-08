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
	room(char, int, double);
	~room();//destructor
	room(room&);
	bool operator >(const room &);// > operator 
	bool operator <(const room &);//< operator
	bool operator ==(int);//operator ==
	void setBuilding(char);
	void setCustomer(int);
	void setPrice(double);
	char getBuilding();
	int getCustomer();
	double getPrice();
	
	
};

#endif