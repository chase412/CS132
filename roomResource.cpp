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
