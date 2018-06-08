//This is a resource file for employee

#include <iostream>
#include <string>
#include "employee.h"

using namespace std;







Employee::Employee(){
	id = -1;
	numHours = -1;
	hourWage = -1;
	start = -1;
	end = -1;
}

void Employee::setHourWage(double d)//setter
{
	hourWage = d;
}
int Employee::getId(){
	return id;
}
double Employee::getHours(){
	if (end == -1 || start == -1){
		cout << "Input Start and End Time first" << endl;
		return -1;
	}

	return numHours;
}
double Employee::getHourWage(){
	return hourWage;
}
double Employee::getSalary(){ //This can be done better. After certain time, raise hourWage. 
	return numHours*hourWage;
}
double Employee::calculateHours() {
	if (end == -1 || start == -1){
		cout << "Input Start and End Time first" << endl;
		return -1;
	}
	int startMinutes = (start / 100) * 60 + start % 100;
	int endMinutes = (end / 100) * 60 + end % 100;
	numHours = (endMinutes - startMinutes) / 60 + ((endMinutes - startMinutes) % 60) / 60.00;
	return numHours;
}


void Employee::setHours(double x) {
	numHours = x;
}


void Employee::setStart(){
	cout << "Start time?(HHMM Example: 1230) : ";
	cin >> start;
	int hours = start / 100;
	int minute = start % 100;
	while (hours > 24 || hours < 0 || minute>60 || minute < 0){
		cout << "Hours have to be between 0-24 and minutes have to be between 0-60" << endl;
		cout << "Start time?(HHMM Example: 1230) : ";
		cin >> start;
		hours = start / 100;
		minute = start % 100;
	}

}
void Employee::setEnd(){
	cout << "End time?(HHMM Example: 1230) : ";
	cin >> end;
	int hours = end / 100;
	int minute = end % 100;
	while (hours > 24 || hours < 0 || minute>60 || minute < 0){
		cout << "Hours have to be between 0-24 and minutes have to be between 0-60" << endl;
		cout << "End time?(HHMM Example: 1230) : ";
		cin >> end;
		hours = end / 100;
		minute = end % 100;
	}
	calculateHours();
}

int Employee::getStart() {
	return start;
}
int Employee::getEnd() {
	return end;
}