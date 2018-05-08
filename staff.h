#ifndef BOSS_H
#define BOSS_H
#include "employee.h"
#include <iostream>
#include <string>

using namespace std;

class Staff :public Employee
{
private:
	//double bonus;
	int numberOfDays;
	double paidTimeOff;

public:
	Staff();               //Constractor
	Staff(int, double, int, double, double, int, int);  //defalt constructor
	void setPaidTimeOff();
	double getPaidTimeOff();
	void setNumberOfDays();
	int getNumberOfDays();
};
#endif