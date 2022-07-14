

#include"DataBase.h"

DataBase::Node::Node() // Default Ctor
{
	this->Emp = NULL; // Sets to NULL
	this->Next = NULL; // Sets to NULL
}


DataBase::Node::Node(Employee& emp, Node* next) : Emp(&emp), Next(next)
{
	// Uses the Ctors of the objects to initialize the values
}


DataBase::Node::~Node() // Dtor
{
	delete this->Emp; // deletes the employee pointer
	delete this->Next; // deletes the next pointer
}


Employee* DataBase::Node::GetEmployee() const
{
	return this->Emp; //return the employee
}


DataBase::Node* DataBase::Node::GetNext() const
{
	return this->Next; // returns the Next
}


void DataBase::Node::SetEmployee(Employee& emp)
{
	this->Emp = &emp; // Sets the employee
}


void DataBase::Node::SetNext(Node* next)
{
	this->Next = next; // Sets the Next
}




DataBase::DataBase() // Default Ctor
{
	this->Head = NULL; // Sets to NULL
	this->CurrentNumOfEmployees = 0; // 0 employees at first
}


DataBase::~DataBase() // Dtor
{
	if (this->Head != NULL) // Incase the Head is not NULL
	{
		Node* current = this->Head;

		while (current != NULL) //Goes from the first Node to the last Node
		{
			this->Head = current->GetNext(); // "Disconnects" the Node from the list
			current->SetNext(NULL);
			delete current; // Deletes the Node
			current = this->Head; //Points to the next Node
		}
	}
}


Employee* DataBase::getEmployee(int index) const // The first employee is number 1 ( not 0)
{
	Node* current = this->Head;

	while (current != NULL) // Goes from the first Node to the last one
	{
		if (index == 1) // Incase the current index is the employee we need
		{
			return current->GetEmployee(); // Returns the employee
		}
		else
		{
			index--; // Index - 1
			current = current->GetNext(); // Moves to the next Node
		}
	}
	return NULL; // If the is not valid returns NULL
}


void DataBase::addEmployee(Employee& emp)
{

	if (this->Head == NULL) // Adding the first Node
	{
		this->Head = new Node; // Allocating memmory
		if (this->Head == NULL) // Checks if allocation was succesful
		{
			cout << "Could not allocate memory.";
			exit(1); // Finishing the program if its unsuccesful
		}
		this->Head->SetEmployee(emp); // Sets the employee
		this->Head->SetNext(NULL); // Sets the next
	}
	else // Adding the other Nodes
	{
		Node* current = this->Head;
		while (current->GetNext() != NULL) // Finds the last Node
		{
			current = current->GetNext();
		}
		Node* NewNode = new Node;
		if (NewNode == NULL) // Checks if allocation was succesful
		{
			cout << "Could not allocate memory.";
			exit(1); // Finishing the program if its unsuccesful
		}
		NewNode->SetEmployee(emp); // Sets the employee
		NewNode->SetNext(NULL); // Sets the next
		current->SetNext(NewNode); // Now the last Node points to the new one



	}
	this->CurrentNumOfEmployees++; // Number of employees increased by 1


}


Employee* DataBase::removeEmployee(int index) // The first employee is number 1 ( not 0)
{
	Node* current = this->Head; // Current Node
	Node* Prev = current; // Previous Node


	while (current != NULL) // Goes from the first Node to the last one
	{

		if (index == 1) // Incase we are in the wanted Node
		{
			if (Prev == Head) // If the first Node or the second Node
			{
				if (current->GetNext() == NULL) // Removing the second Node (while he is the last one too)
				{
					Head->SetNext(NULL); 
				}
				else // Removing the first node
				{
					Head = (current->GetNext());
				}
			}
			else // Any other Node beside the first or the second one
			{
				Prev->SetNext(current->GetNext());
			}

			if (this->CurrentNumOfEmployees == 1) //If the Node is the last one
				Head = NULL; // Sets it to NULL


			this->CurrentNumOfEmployees--; // employees - 1
			return current->GetEmployee(); // Returns the wanted Employee

		}
		else // If the index is not the wanted one
		{
			index--; //index - 1
			Prev = current; // Sets the previous 
			current = current->GetNext(); // Sets the cuurrent
		}

	}


	return NULL; // If the index is not right, return NULL

}


void DataBase::print(Date today) const // Prints the linked list
{
	if (this->Head != NULL) // If the list is not empty
	{
		Node* current = this->Head;
		while (current->GetNext() != NULL) // Goes from the first Node to the one before last
		{
			Employee x = *(current->GetEmployee());
			x.print(today); // Prints the Employee

			current = current->GetNext(); // Moves to the next Node
		}
		Employee x = *(current->GetEmployee()); 
		x.print(today); // Prints the last employee
	}

}