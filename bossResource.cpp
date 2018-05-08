#include "employee.h"
#include "boss.h"
#include <iostream>
#include <string>



Boss::Boss()                   //constructor
{
	paidTimeOff = 0;
	salary = 0;
	numHours = 0;
}
Boss::Boss(int day, double sal, double num, int iD, double nh, double hw, int s, int e) : Employee(iD, nh, hw, s, e)  //defalt constructor
{
	paidTimeOff = day;
	salary = sal;
	numHours = num;
}

//void Boss::setHours(double h)
//{
//	numHours = h;
//}
//double Boss::getHours()        //boss can set 
//{
//	return numHours;
//}

/////////////////////////////////////////////
//This function will ask for user to enter
//the numebr of days that boss want to
//take off, and set the days to "numberOfDays"
//Day is range [0-20]
/////////////////////////////////////////////
void Boss::setNumberOfDays()
{
	int d;
	cout << "How many days are you going to take off? [0-10 days]" << endl;
	cin >> d;
	while (d < 0 || d > 20)
	{
		cout << "ERROR. DAY NEED TO BE RANGE OF 0-10 DAYS" << endl;
		cout << "How many days are you going to take off? ";
		cin >> d;
	}
	numberOfDays = d;
}

//////////////////////////////////////////////////////
//This function will is getter for the "numberOfDays"
//It will return the number Of Days that boss want 
//to take a break.
/////////////////////////////////////////////////////
int Boss::getNumberOfDays()
{
	return numberOfDays;
}

//////////////////////////////////////////////////////
//This function will ask for user enter the amount of 
//salary for staff.
//Boss can decied how much mony the staff can make 
//an hour
//and set the salary by using employee member function
//////////////////////////////////////////////////////
void Boss::setSalary() //setter salary
{
	double s;
	cout << "Enter the salary: ";
	cin >> s;
	while (s < 0)
	{
		cout << "ERROR.SALARY CANNOT BE NEGATIVE NUMBER" << endl;
		cout << "Enter the salary: ";
		cin >> s;
	}
	//salary = s;
	Employee::setSalary(s);

}

/////////////////////////////////////
//This function will return the salary 
// for each employees
/////////////////////////////////////
double Boss::getSalary()      //getter salary
{
	salary = Employee::getSalary();
	return salary;
}

//////////////////////////////////////////////////
//This function will find and set how much
//money that boss can get during the day off
//////////////////////////////////////////////////
void Boss::setPaidTimeOff()
{
	double bonus = 100;
	paidTimeOff = (numberOfDays * salary) + bonus;
}

///////////////////////////////////////////////////
//This function will return how much money 
//that boss can get during the day off
///////////////////////////////////////////////////
double Boss::getPaidTimeOff()
{
	return paidTimeOff;
}
