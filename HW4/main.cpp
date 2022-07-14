

#include"LinkedList.h"
#include"Fraction.h"
#include"String.h"
#define Int 1
#define Double 2
#define Char 3
#define Frac 4
#define EXIT 5
template<class T>
int NumberOfBigger(LinkedList<T> list, T temp);
template<class T>
bool IfCommon(LinkedList<T> list1, LinkedList<T> list2);
template<typename T>
void ListTest(T t);
void Menu();
void intlist();
void doublelist();
void charlist();
void Fractoinlist();

void main()
{
	bool Run = true;
	int choice;

	while (Run)
	{
		Menu();
		cin >> choice;
		switch (choice)
		{
		case Int: // List of int
			intlist(); // Builts a list and goes over all the funtions
			break;
		case Double: // List of Double
			doublelist(); // Builts a list and goes over all the funtions
			break;
		case Char: // List of Char*
			charlist(); // Builts a list and goes over all the funtions
			break;
		case Frac: // List of Fraction
			Fractoinlist(); // Builts a list and goes over all the funtions
			break;
		case EXIT:
			Run = false; //Exits the program
			break;
		}
			

	}
}


template<class T>
int NumberOfBigger(LinkedList<T> list, T temp)
{
	int count = 0;
	Node<T>* current = list.GetHead();

	while (current != NULL) // Goes all over the list
	{
		/*if (sizeof(current->GetData()) == sizeof(char*))
		{
			if (strlen(current->GetData()) > strlen(temp))
				count++;
		}*/
		/*else*/ if (current->GetData() > temp) // Checks if the data is bigger than the parameter
			count++; // Counting it if it is bigger
		current = current->GetNext(); // Moving to the next node
	}
	return count; // Returning the amount of bigger values
}

template<class T>
bool IfCommon(LinkedList<T> list1, LinkedList<T> list2)
{
	Node<T>* current1 = list1.GetHead();
	Node<T>* current2 = list2.GetHead();

	while (current1 != NULL) // Goes all over list 1
	{
		current2 = list2.GetHead(); 
		while (current2 != NULL) // Goes all over list 2
		{
			/*if (sizeof(current1->GetData()) == sizeof(char*))
			{
				if (strlen(current1->GetData()) > strlen(current2->GetData()))
					return true;
			}*/
			/*else*/ if (current1->GetData() == current2->GetData()) // If the data is the same
				return true;
			current2 = current2->GetNext();
		}
		current1 = current1->GetNext(); // Moving to the next node
	}
	return false;
}

void Menu() // The menu for the user
{
	cout << "Please choose a type you want to work with(number from 1 to 5): " << endl;
	cout << "1. int " << endl;
	cout << "2. double " << endl;
	cout << "3. char*" << endl;
	cout << "4. Fraction" << endl;
	cout << "5. Exit" << endl;
}

void intlist()
{
	int NumberFor_NumberOfBigger;
	int Nodemaount1;
	int Nodemaount2;
	int NodeToRemove = -1;
	int listnum;
	int* value = NULL;
	LinkedList<int> List1, List2;
	cout << "How many Nodes would you like in the first list?" << endl; // Creating the first list
	cin >> Nodemaount1;
	for (int i = 0; i < Nodemaount1; i++)
	{
		value = new int;
		cout << "Enter the value you want to add to the list: " << endl;
		cin >> *value;
		List1 += *value;
	}
	cout << "How many Nodes would you like in the second list?" << endl; // Creating the second list
	cin >> Nodemaount2;
	for (int i = 0; i < Nodemaount2; i++)
	{
		value = new int;
		cout << "Enter the value you want to add to the list: " << endl;
		cin >> *value;
		List2 += *value;
	}

	cout << "Choose the value of the Node you want to remove(one at a time), if you want to stop press 0" << endl;
	cin >> NodeToRemove;

	while (NodeToRemove != 0) // Removing the data if the user chose to do it
	{
		if ((List1 -= NodeToRemove) == 0)
			cout << "Value does not exists in list 1" << endl;
		else
			cout << "Value has been deleted from list 1" << endl;
		if((List2 -= NodeToRemove) == 0)
			cout << "Value does not exists in list 2" << endl;
		else
			cout << "Value has been deleted from list 2" << endl;

		cout << "Choose the value of the Node you want to remove(one at a time), if you want to stop press 0" << endl;
		cin >> NodeToRemove;
	}


	cout << "The intersection of the lists:" << endl; // The intersection of the lists
	cout << List1.Intersection(List2) << endl;

	cout << "The union of the lists:" << endl; //The union of the lists
	cout << List1.Union(List2) << endl;

	cout << "All of List number 1:" << endl;
	cout << List1 << endl;

	cout << "All of List number 2:" << endl;
	cout << List2 << endl;
	// Using funtion 1 for list 1
	cout << "Choose a number to check the amount of values in list1 that are bigger than the value:" << endl;
	cin >> NumberFor_NumberOfBigger;
	cout << "There are " << NumberOfBigger(List1, NumberFor_NumberOfBigger) << " value/s that are bigger than the value you chose." << endl << endl;
	// Using funtion 1 for list 2
	cout << "Choose a number to check the amount of values in list2 that are bigger than the value:" << endl;
	cin >> NumberFor_NumberOfBigger;
	cout << "There are " << NumberOfBigger(List2, NumberFor_NumberOfBigger) << " value/s that are bigger than the value you chose." << endl << endl;
	// Using funtion 2
	if (IfCommon(List1, List2))
		cout << "The lists have at least one common value" << endl << endl;
	else
		cout << "The lists have no common values" << endl << endl;

	cout << "*****************************************************************" << endl;
}
void doublelist()
{
	double NumberFor_NumberOfBigger;
	int Nodemaount1;
	int Nodemaount2;
	double NodeToRemove = -1;
	int listnum;
	double* value = NULL;
	LinkedList<double> List1, List2;
	cout << "How many Nodes would you like in the first list?" << endl; // Creating the first list
	cin >> Nodemaount1;
	for (int i = 0; i < Nodemaount1; i++)
	{
		value = new double;
		cout << "Enter the value you want to add to the list: " << endl; 
		cin >> *value;
		List1 += *value;
	}
	cout << "How many Nodes would you like in the second list?" << endl; // Creating the second list
	cin >> Nodemaount2;
	for (int i = 0; i < Nodemaount2; i++)
	{
		value = new double;
		cout << "Enter the value you want to add to the list: " << endl;
		cin >> *value;
		List2 += *value;
	}

	cout << "Choose the value of the Node you want to remove(one at a time), if you want to stop press 0" << endl;
	cin >> NodeToRemove;

	while (NodeToRemove != 0) // Removing the data if the user chose to do it
	{
		if ((List1 -= NodeToRemove) == 0)
			cout << "Value does not exists in list 1" << endl;
		else
			cout << "Value has been deleted from list 1" << endl;
		if((List2 -= NodeToRemove) == 0)
			cout << "Value does not exists in list 2" << endl;
		else
			cout << "Value has been deleted from list 2" << endl;

		cout << "Choose the value of the Node you want to remove(one at a time), if you want to stop press 0" << endl;
		cin >> NodeToRemove;
	}


	cout << "The intersection of the lists:" << endl; // The intersection of the lists
	cout << List1.Intersection(List2) << endl;

	cout << "The union of the lists:" << endl; // The union of the lists
	cout << List1.Union(List2) << endl;

	cout << "All of List number 1:" << endl;
	cout << List1 << endl;

	cout << "All of List number 2:" << endl;
	cout << List2 << endl;
	// Using funtion 1 for list 1
	cout << "Choose a number to check the amount of values in list1 that are bigger than the value:" << endl;
	cin >> NumberFor_NumberOfBigger;
	cout << "There are " << NumberOfBigger(List1, NumberFor_NumberOfBigger) << " value/s that are bigger than the value you chose." << endl << endl;
	// Using funtion 1 for list 2
	cout << "Choose a number to check the amount of values in list2 that are bigger than the value:" << endl;
	cin >> NumberFor_NumberOfBigger;
	cout << "There are " << NumberOfBigger(List2, NumberFor_NumberOfBigger) << " value/s that are bigger than the value you chose." << endl << endl;
	// Using funtion 2
	if (IfCommon(List1, List2))
		cout << "The lists have at least one common value" << endl << endl;
	else
		cout << "The lists have no common values" << endl << endl;

	cout << "*****************************************************************" << endl;
}
void charlist()
{
	String NumberFor_NumberOfBigger = NULL;
	int Nodemaount1;
	int Nodemaount2;
	String NodeToRemove;
	int listnum;
	String CharToInsert;
	String* value = new String;
	LinkedList<String> List1, List2;
	cout << "How many Nodes would you like in the first list?" << endl; // Creating the first list
	cin >> Nodemaount1;
	getchar();
	for (int i = 0; i < Nodemaount1; i++)
	{
		String* value = new String;
		cout << "Enter the value you want to add to the list: " << endl;
		cin >> CharToInsert;
		value[0] = new char[strlen(CharToInsert) + 1];
		strcpy(value[0], CharToInsert);
		List1 += value[0];
	}
	cout << "How many Nodes would you like in the second list?" << endl; // Creating the second list
	cin >> Nodemaount2;
	getchar();
	for (int i = 0; i < Nodemaount2; i++)
	{
		String* value = new String;
		cout << "Enter the value you want to add to the list: " << endl;
		cin >> CharToInsert;
		value[0] = new char[strlen(CharToInsert) + 1];
		strcpy(value[0], CharToInsert);
		List2 += value[0];
	}

	cout << "Choose the value of the Node you want to remove(one at a time), if you want to stop press 0" << endl;
	cin >> NodeToRemove;
	

	while (strcmp(NodeToRemove,"0")) // Removing the data if the user chose to do it
	{
		if ((List1 -= NodeToRemove) == 0)
			cout << "Value does not exists in list 1" << endl;
		else
			cout << "Value has been deleted from list 1" << endl;
		if((List2 -= NodeToRemove) == 0)
			cout << "Value does not exists in list 2" << endl;
		else
			cout << "Value has been deleted from list 2" << endl;

		cout << "Choose the value of the Node you want to remove(one at a time), if you want to stop press 0" << endl;
		cin >> NodeToRemove;
	}


	cout << "The intersection of the lists:" << endl; // The intersection of the lists
	cout << List1.Intersection(List2) << endl;
	 
	cout << "The union of the lists:" << endl; //  The union of the lists
	cout << List1.Union(List2) << endl;

	cout << "All of List number 1:" << endl;
	cout << List1 << endl;

	cout << "All of List number 2:" << endl;
	cout << List2 << endl;
	// Using funtion 1 for list 1
	cout << "Choose a word to check the amount of values in list1 that are bigger than the value:" << endl;
	cin >> CharToInsert;
	NumberFor_NumberOfBigger = new char[strlen(CharToInsert) + 1];
	strcpy(NumberFor_NumberOfBigger, CharToInsert);
	cout << "There are " << NumberOfBigger(List1, NumberFor_NumberOfBigger) << " value/s that are bigger than the value you chose." << endl << endl;
	// Using funtion 1 for list 2
	cout << "Choose a word to check the amount of values in list2 that are bigger than the value:" << endl;
	cin >> CharToInsert;
	NumberFor_NumberOfBigger = new char[strlen(CharToInsert) + 1];
	strcpy(NumberFor_NumberOfBigger, CharToInsert);
	cout << "There are " << NumberOfBigger(List2, NumberFor_NumberOfBigger) << " value/s that are bigger than the value you chose." << endl << endl;
	// Using funtion 2
	if (IfCommon(List1, List2))
		cout << "The lists have at least one common value" << endl << endl;
	else
		cout << "The lists have no common values" << endl << endl;

	cout << "*****************************************************************" << endl;
}
void Fractoinlist()
{
	Fraction* NumberFor_NumberOfBigger = NULL;
	int Nodemaount1;
	int Nodemaount2;
	int Numeratorand;
	int Denominator;
	Fraction* NodeToRemove = new Fraction(1,1);
	Fraction zero(0, 2);
	int listnum;
	Fraction* value = NULL;
	LinkedList<Fraction> List1, List2;
	cout << "How many Nodes would you like in the first list?" << endl; // Creating the first list
	cin >> Nodemaount1;
	for (int i = 0; i < Nodemaount1; i++)
	{
		value = new Fraction;
		cout << "Enter the Numerator and denominator you want to add to the list: " << endl;
		cin >> Numeratorand >> Denominator;
		value = new Fraction(Numeratorand, Denominator);
		List1 += *value;
	}
	cout << "How many Nodes would you like in the second list?" << endl; // Creating the second list
	cin >> Nodemaount2;
	for (int i = 0; i < Nodemaount2; i++)
	{
		value = new Fraction;
		cout << "Enter the Numerator and denominator you want to add to the list: " << endl;
		cin >> Numeratorand >> Denominator;
		value = new Fraction(Numeratorand, Denominator);
		List2 += *value;
	}

	cout << "Choose the Numerator and denominator you want to remove(one at a time), if you want to stop press 0" << endl;
	cin >> Numeratorand >> Denominator;
	NodeToRemove = new Fraction(Numeratorand, Denominator);

	while (*NodeToRemove != zero) // Removing the data if the user chose to do i
	{
		if ((List1 -= *NodeToRemove) == 0)
			cout << "Value does not exists in list 1" << endl;
		else
			cout << "Value has been deleted from list 1" << endl;
		if((List2 -= *NodeToRemove) == 0)
			cout << "Value does not exists in list 2" << endl;
		else
			cout << "Value has been deleted from list 2" << endl;

		cout << "Choose the Numerator and denominator you want to remove(one at a time), if you want to stop press 0" << endl;
		cin >> Numeratorand >> Denominator;
		NodeToRemove = new Fraction(Numeratorand, Denominator);
		
	}


	cout << "The intersection of the lists:" << endl; // The intersection of the lists
	cout << List1.Intersection(List2) << endl;

	cout << "The union of the lists:" << endl; // The union of the lists
	cout << List1.Union(List2) << endl;

	cout << "All of List number 1:" << endl;
	cout << List1 << endl;

	cout << "All of List number 2:" << endl;
	cout << List2 << endl;
	// Using funtion 1 for list 1
	cout << "Choose a numerator and denominator to check the amount of values in list1 that are bigger than the value:" << endl;
	cin >> Numeratorand >> Denominator;
	NumberFor_NumberOfBigger = new Fraction(Numeratorand, Denominator);
	cout << "There are " << NumberOfBigger(List1, *NumberFor_NumberOfBigger) << " value/s that are bigger than the value you chose." << endl << endl;
	// Using funtion 1 for list 2
	cout << "Choose a numerator and denominator to check the amount of values in list2 that are bigger than the value:" << endl;
	cin >> Numeratorand >> Denominator;
	NumberFor_NumberOfBigger = new Fraction(Numeratorand, Denominator);
	cout << "There are " << NumberOfBigger(List2, *NumberFor_NumberOfBigger) << " value/s that are bigger than the value you chose." << endl << endl;
	// Using funtion 2
	if (IfCommon(List1, List2))
		cout << "The lists have at least one common value" << endl << endl;
	else
		cout << "The lists have no common values" << endl << endl;

	cout << "*****************************************************************" << endl;
}
