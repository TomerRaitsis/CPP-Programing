

#include"Employee.h"


Employee::Employee(String name, String lastname, Date birthday, int id, Date startdate, double salary, int status) : Name(name), LastName(lastname), BirthDate(birthday), EmployeeId(id), StartDay(startdate)
{
	// Uses Ctors to initialize the const values and objects
	Salary = salary;
	if (status >= 0 && status <= 3) // Checks if the status is valid (0-3)
	{
		EmployeeStatus = status;
	}
	else
	{
		EmployeeStatus = 0; // Default status incase the the given status is not valid
	}
}


Employee::Employee(const Employee& emp) :Name(emp.Name), LastName(emp.LastName), BirthDate(emp.BirthDate), EmployeeId(emp.EmployeeId), StartDay(emp.StartDay)
{   
	// Uses Ctors to initialize the const values and objects
	Salary = emp.Salary;
	if (emp.EmployeeStatus >= SECRETARY && emp.EmployeeStatus <= DIRECTOR) // Incase the status is valid
	{
		EmployeeStatus = emp.EmployeeStatus;
	}
	else
	{
		EmployeeStatus = SECRETARY; // If the status is not valid
	}
}


Employee::~Employee() // Dtor
{
}


Date Employee::Seniority(Date today) const
{
	Date Seniority = today.SubDate(StartDay); // Calculates the seniority
	return Seniority;
}


Date Employee::Age(Date today) const
{
	Date Age = today.SubDate(this->BirthDate);  // Calculates the age
	return Age;
}


void Employee::print(Date today) const
{
	cout << "Name: ";
	this->Name.PrintString(); // Prints the name

	cout << "Last name: ";
	this->LastName.PrintString(); // Prints the lastname

	cout << "Employee ID: ";
	cout << EmployeeId << endl; // Prints the ID

	cout << "Salary: ";  // Prints the salary
	cout << Salary << endl;

	cout << "Employee status: "; // Prints the status
	switch (EmployeeStatus)
	{
	case SECRETARY: cout << "Secretery" << endl;
		break;
	case EMPLOYED: cout << "Employed" << endl;
		break;
	case MANAGER: cout << "Manager" << endl;
		break;
	case DIRECTOR: cout << "Director" << endl;
		break;

	}
	cout << "Age: "; // Prints the age
	Date age = Age(today);
	age.PrintDate();

	cout << "Seniority: "; // Prints the seniority
	Date seniority = Seniority(today);
	seniority.PrintDate();
}


void Employee::promotion() // Promotes the employee
{
	if (EmployeeStatus < DIRECTOR) // Incase the employee is not a director
	{
		EmployeeStatus++;
		Salary *= 1.1;  // 10% raise
	}
	else
	{
		if (EmployeeStatus == DIRECTOR)  // Incase the employee is a director
		{
			Salary *= 2; // doubles the salary
		}
	}
}


Employee& Employee::operator=(const Employee& temp)
{
	if (this != &temp) // Check if the object point at the same adress
	{
		this->Name = temp.Name; // Copying the non const values
		this->LastName = temp.LastName;
		this->Salary = temp.Salary;
		this->EmployeeStatus = this->EmployeeStatus;
	}

	return *this; // returns the objects
}