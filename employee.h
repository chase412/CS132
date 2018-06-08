//This is a header file for employee

#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <iostream>
#include <string>

using namespace std;

class Employee{
private:
	int id;
	double numHours;
	double hourWage;
	int start;
	int end;

public:
	Employee();
	void setHourWage(double);//setter salary
	int getId();
	double getHours();
	double getHourWage();
	double getSalary();
	virtual double calculateHours();
	void setHours(double);
	void setStart();
	void setEnd();
	int getStart();
	int getEnd();

};













#endif