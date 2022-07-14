

#ifndef __EMPLOYEE_H_
#define __EMPLOYEE_H_
#include"Date.h"
#include"String.h"
#include<iostream>
using namespace std;
#define SECRETARY 0
#define EMPLOYED 1
#define MANAGER 2
#define DIRECTOR  3


class Employee
{
public:
	Employee(String name, String lastname, Date birthday, int id, Date startdate, double salary, int status); // Ctor with values
	Employee(const Employee& emp); // CCtor
	~Employee(); // Dtor
	void print(Date today) const; // Prints the object
	Date Seniority(Date today) const; // Cheacks the siniority of an employee
	Date Age(Date today) const; // Cheacks the age of an employee
	void promotion(); // Promotes an employee
	Employee& operator=(const Employee& temp); // operator =

private:
	String Name;
	String LastName;
	const Date BirthDate;
	const int EmployeeId;
	const Date StartDay;
	double Salary;
	int EmployeeStatus;
};






#endif