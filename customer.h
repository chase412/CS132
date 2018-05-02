#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <iostream>
#include <string>

using namespace std;

//This is a Header file for customer class

class room;

class customer {
private:
	string name;
	int id;


public:
	customer();
	customer(string, int);
	customer(customer&);
	bool operator ==(int);
	~customer();
	void setName(string);
	void setID(int);
	int getID();
	string getName();
	bool customer::operator >(const customer &);
	friend ofstream& operator<< (ofstream &, customer &);
};


#endif