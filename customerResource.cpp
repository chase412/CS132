#include <iostream>
#include <string>
#include "customer.h"

using namespace std;

//This is a resource file for customer class


customer::customer() {
	name = "";
	id = -1;
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









