#ifndef BOSS_H
#define BOSS_H
#include "employee.h"
#include <iostream>
#include <string>

using namespace std;

class Boss :public Employee
{
private:
	double paidTimeOff; //numebr of days off but can get money
	int numberOfDays;
	double salary;
	double numHours;
	
public:
	Boss();                 //constructor
	Boss(int, double, double, int, double, double, int, int);   //defalt constructor
	//void setHours(double);
	//double getHours();      //boss can set 

	void setNumberOfDays();
	int getNumberOfDays();

	void setSalary(); //setter 
	double getSalary();     //getter

	void setPaidTimeOff();
	double getPaidTimeOff();

};
#endif