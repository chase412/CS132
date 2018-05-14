//This is a resource file for boss

#include "employee.h"
#include "boss.h"
#include <iostream>
#include <string>



Boss::Boss(): Employee()                  //constructor
{
	setHourWage(50);
}


void Boss::changeStaffWage(Staff &x) {
	double temp;
	cout << "Current " << x.getId() << "'s wage is $" << x.getHourWage() << endl;
	cout << "What is new Hour Wage? : ";
	cin >> temp;
	x.setHourWage(temp);
}
double Boss::calculateHours() {
	int start = getStart();
	int end = getEnd();
	
	if (end == -1 || start == -1) {
		cout << "Input Start and End Time first" << endl;
		return -1;
	}
	int startMinutes = (start / 100) * 60 + start % 100;
	int endMinutes = (end / 100) * 60 + end % 100;
	double temp = (endMinutes - startMinutes) / 60 + ((endMinutes - startMinutes) % 60) / 60.00;
	temp = temp + 1; //Just adding extra hour for boss
	setHours(temp);
	return temp;

}