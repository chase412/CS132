#include "employee.h"
#include "staff.h"
#include <iostream>
#include <string>


Staff::Staff() : Employee()      //Constructor
{
	numberOfDays = 0;
	paidTimeOff = 0;
} 
Staff::Staff(int numD, double paid, int iD, double nh, double hw, int s, int e) : Employee(iD, nh, hw, s, e)  //defalt constructor
{
	numberOfDays = numD;
	paidTimeOff = paid;
}

//////////////////////////////////////////////////
//This function will find and set how much
//money that staff can get during the day off
//////////////////////////////////////////////////
void Staff::setPaidTimeOff()
{
	double salary = getSalary();
	paidTimeOff = (numberOfDays * Employee::getSalary());
}

///////////////////////////////////////////////////
//This function will return how much money 
//that staff can get during the day off
///////////////////////////////////////////////////
double Staff::getPaidTimeOff()
{
	return paidTimeOff;
}


/////////////////////////////////////////////
//This function will ask for user to enter
//the numebr of days that staff want to
//take off, and set the days to "numberOfDays"
//Day is range [0-10]
/////////////////////////////////////////////
void Staff::setNumberOfDays()
{
	int d;
	cout << "How many days are you going to take off? [0-10 days]" << endl;
	cin >> d;
	while (d < 0 || d > 10)
	{
		cout << "ERROR. DAY NEED TO BE RANGE OF 0-10 DAYS" << endl;
		cout << "How many days are you going to take off? ";
		cin >> d;
	}
	numberOfDays = d;
}

//////////////////////////////////////////////////////
//This function will is getter for the "numberOfDays"
//It will return the number Of Days that staff want 
//to take a break.
/////////////////////////////////////////////////////
int Staff::getNumberOfDays()
{
	return numberOfDays;
}