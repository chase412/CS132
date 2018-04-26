#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <iostream>
#include <string>

using namespace std;

//This is a Header file for customer class

class customer {
private:
	string name;
	int id;


public:
	customer();
	
	void setName(string);
	void setID(int);
	int getID();
	string getName();

};













#endif
