#include <iostream>
#include <string>
#include "customer.h"

using namespace std;

//This is a resource file for customer class


customer::customer() {
	name = "";
	id = -1;
}
customer::customer(string nm, int x){
	name = nm;
	id = x;
}
customer::customer(customer& obj){ //copy constructor
	name = obj.name;
	id = obj.id;
}
customer::~customer(){ // destructor
}
void customer::setName(string x) {
	name = x;
}
void customer::setID(int x) {
	id = x;
};
int customer::getID() {
	return id;
}
string customer::getName() {
	return name;
}
bool customer::operator >(const customer &right){// operator >
	bool check;
	if (name > right.name)
		check = true;
	else
		check = false;

	return check;
}
bool customer::operator ==(int right){ //Operator ==
	bool check;
	if (id == right){
		check = true;
	}
	else{
		check = false;
	}
	return check;
}
void customer::option(int o)//For Option 
{
	if (o <= 6 && o >= 1)
	{
		inputOtion = o;
	}
	else
		throw ErrorOption();
}
