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
	Employee(int, double, double, int, int);
	void setSalary(double);//setter salary
	int getId();
	double getHours();
	double getHourWage();
	double getSalary();
	void setHours();
	void setStart();
	void setEnd();


};













#endif