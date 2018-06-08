//This is a header file for boss
//Derived for employee

#ifndef BOSS_h
#define BOSS_h
#include "employee.h"
#include "staff.h"
#include <iostream>
#include <string>

using namespace std;

class Boss :public Employee
{
private:

	
public:
	Boss();                 //Default constructor
	//void setHours(double);
	//double getHours();      //boss can set 

	void changeStaffWage(Staff &);
	double calculateHours();

};
#endif