#include <iostream>
#include <string>
#include "room.h"

using namespace std;

//This is a resource file for room class

room::room() {
	building = '-1';
	customer = -1;
	price = -1;
}
room::room(char b, int c, double p){
	building = b;
	customer = c;
	price = p;
}
room::~room(){

}


bool room::operator >(const room& right){
	bool check;
	if (building > right.building){
		check = true;
	}
	else
		check = false;
	return check;
}
bool room::operator <(const room& right){ //Operator <
	bool check;
	if (building < right.building){
		check = true;
	}
	else
		check = false;
	return check;
}
bool room::operator==(const room& right){
	bool check;
	if (building == right.building&&price == right.price&&customer == right.customer)
		check = true;
	else
		check = false;
	return check;
}
void room::setBuilding(char x) {
	building = x;
}

void room::setCustomer(int x) {
	customer = x;
}
void room::setPrice(double x) {
	price = x;
}
char room::getBuilding() {
	return building;
}
int room::getCustomer() {
	return customer;
}
double room::getPrice() {
	return price;
}
