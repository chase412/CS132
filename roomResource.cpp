#include <iostream>
#include <string>
#include "room.h"

using namespace std;

//This is a resource file for room class

room::room() {
	building = 'z';
	customer = -1;
	price = -1;
}
room::room (char b, int c, double p){
	building = b;
	customer = c;
	price = p;
}
room::~room(){ // destructor

}

//Copy Constructor
room::room(room&obj){
	building = obj.building;
	customer = obj.customer;
	price = obj.price;
}

bool room::operator >(const room& right) {// opeartor >
	bool check;
	if (building > right.building){
		check = true;
	}
	else
		check = false;
	return check;
}
bool room::operator <(const room& right){ // Operator <
	bool check;
	if (building < right.building){
		check = true;
	}
	else
		check = false;
	return check;
}
bool room::operator==(int right){ // opeartor ==
	bool check;
	if (customer==right)
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
