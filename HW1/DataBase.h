

#ifndef __DATABASE_H_
#define __DATABASE_H_
#include"Employee.h"

class DataBase
{
private:
	class Node //Private inner class
	{
	public:
		Node(); //Default Ctor
		Node(Employee& emp, Node* next); // Ctor with values
		~Node(); // Dtor
		Employee* GetEmployee() const; // Gets the employee pointer in the Node (Employee* object)
		Node* GetNext() const; // Gets the Next pointer in the Node (Node* object)
		void SetEmployee(Employee& emp); // Sets the Employee
		void SetNext(Node* next); // Sets th Next

	private:
		Employee* Emp;
		Node* Next;
	};

	Node* Head; // First Node of the linked list
	int CurrentNumOfEmployees; // Amounts of Nodes in the linked list / Number of employees


public:
	DataBase(); // Ctor
	~DataBase(); // Dtor
	Employee* getEmployee(int index) const; // Return an Employee* object (finds him by a given index)
	void addEmployee(Employee& emp); // Adds an employee 
	Employee* removeEmployee(int index); // Removes an employee
	void print(Date today) const; // Prints al the employees and thier data ( all the linked list)


};


#endif
