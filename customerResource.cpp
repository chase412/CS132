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
customer::customer(customer& obj){
	name = obj.name;
	id = obj.id;
}
customer::~customer(){
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
bool customer::operator ==(const customer &right){ //Operator ==
	bool check;
	if (id == right.id&&name==right.name){
		check = true;
	}
	else{
		check = false;
	}
	return check;
}

