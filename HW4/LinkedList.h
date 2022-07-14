

#ifndef __LINKEDKIST_H_
#define __LINKEDKIST_H_
#include"Node.h"

template<class T>
class LinkedList
{
private:
	Node<T>* Head; // First Node of the linked list
	int Size; // Amounts of Nodes in the linked list / Number of employees

public:
	LinkedList(); // Default Ctor
	~LinkedList(); //Dtor
	LinkedList(const LinkedList<T>& temp); // CCtor
	LinkedList<T>& operator=(const LinkedList<T>& temp); // Opeator =
	void operator+=( T& data); // Adds a new node with the given data
	int operator-=(const T& data); // Removes a node with the given data
	LinkedList<T>& Union(const LinkedList<T>& templist); // Union beteen two lists
	LinkedList<T>& Intersection(const LinkedList<T>& templist); // Intersection between two lists
	template<class T>
	friend ostream& operator<<(ostream& os, const LinkedList<T>& temp); // Printing function ( opertor << )
	void SetSize(int num); // Sets the size
	bool IfExists(T& temp); // Checks if a data is already in the list
	Node<T>* GetHead(); // Returns the Head Node
	int GetSize(); // Returns the size of the list
};
#endif

template<class T>
LinkedList<T>::LinkedList() // Ctor
{
	Head = NULL; // Sets to NULL
	Size = 0; // Sets size to 0
}

template<class T>
LinkedList<T>::~LinkedList() // Dtor
{
	if (this->Head != NULL) // Incase the Head is not NULL
	{
		Node<T>* current = this->Head;
		while (current != NULL)
		{
			this->Head = current->GetNext(); // "Disconnects" the Node from the list
			current->SetNext(NULL);
			delete current; // Deletes the Node
			current = this->Head; //Points to the next Node
		}
	}
}

template<class T>
LinkedList<T>::LinkedList(const LinkedList<T>& temp) // CCtor
{
	this->Size = 0;
	Node<T>* Current = temp.Head; // Points to the head of the temp list
	this->Head = NULL;

	for (int i = 0; i < temp.Size; i++)
	{
		this->operator+=(Current->GetData()); // Adds every Node in the temp list 
		Current = temp.Head->GetNext(); // Moves to the next Node
	}
}

template<class T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& temp)
{
	if (this != &temp) // If the objects are different
	{
		this->Head = NULL;
		this->SetSize(0);
		Node<T>* Current2 = temp.Head; // Points to the head of the temp list

		while (Current2 != NULL)
		{
			this->operator+=(Current2->GetData()); // Adds every Node in the temp list
			Current2 = Current2->GetNext(); // Moves to the next Node
		}
	}
	return *this; //Returns the object
}

template<class T>
void LinkedList<T>::operator+=( T& data)
{
	if (this->Head == NULL) // If it is the first Node
	{
		this->Head = new Node<T>;
		if (this->Head == NULL) // Checks if allocation was succesful
		{
			cout << "Could not allocate memory.";
			exit(1); // Finishing the program if its unsuccesful
		}
		this->Head->SetData(data); // Sets the data
		this->Head->SetNext(NULL); // Sets the Next to NULL
	}
	else
	{
		Node<T>* Current = this->Head;
		while (Current->GetNext() != NULL)
		{
			Current = Current->GetNext(); // Moves to the last Node of the list
		}
		Node<T>* NewNode = new Node<T>;
		if (NewNode == NULL) // Checks if allocation was succesful
		{
			cout << "Could not allocate memory.";
			exit(1); // Finishing the program if its unsuccesful
		}
		NewNode->SetData(data);  // Sets the data
		NewNode->SetNext(NULL);  // Sets the Next to NULL
		Current->SetNext(NewNode); // Adds the Node to the list
	}
	this->Size++; // Adding 1 to the size of the list
}


template<class T>
int LinkedList<T>::operator-=(const T& data)
{
	bool Check = false;
	int index = 1;
	int Count = 0;
	Node<T>* current = this->Head; // Current Node
	Node<T>* Prev = current; // Previous Node
	
	while (current != NULL) // Checking if the data exists in the list
	{
		if (data == current->GetData())
		{
			Check = true; // Incase the data was found
			break;
		}
		current = current->GetNext();
		index++; // Adding 1 to the index, so it will be known where exactly the data is stored
	}
	current = this->Head;	
	while (current != NULL && Check)
	{
		if (index == 1) // if it is the right index
		{
			if (Prev == this->Head) // if the previous index is the Head
			{
				if (current->GetNext() == NULL) // There is only one Node in the list
				{
					this->Head->SetNext(NULL); // Setting it to NULL
					Check = false;
					Count++; // Counting to know if a node has been removed
					
				}
				else
				{
					this->Head = current->GetNext();// Setting the Head to the neaxt Node
					Check = false;
					Count++; // Counting to know if a node has been removed
					break;
				}
			}
			else
			{
				Prev->SetNext(current->GetNext()); //Setting the Previous Node to the next one
				Count++; // Counting to know if a node has been removed
				Check = false;
			}
			if (this->Size == 1)
				this->Head = NULL;

			

		}
		else // The current Node is not the right one
		{
			index--; 
			Prev = current;
			current = current->GetNext(); // Moving to the next Node
		}
		
	}
	this->Size--; // Size of the list - 1
	return Count;// returning the count to know of the data exists and the node has been deleted
}


template<class T>
LinkedList<T>& LinkedList<T>::Intersection(const LinkedList<T>& templist)
{
	LinkedList<T>* Temp = new LinkedList<T>; // New list
	Temp->Size = 0;
	Node<T>* current1 = this->Head; 
	Node<T>* current2 = templist.Head;

	while (current1 != NULL) 
	{
		current2 = templist.Head;
		while (current2 != NULL)
		{
			if (current1->GetData() == current2->GetData()) //if the Node are the same
			{
				if(!Temp->IfExists(current1->GetData())) // if the Node Don't exists in the list
				*Temp += (current1->GetData()); // Adding the Node to the list
			}
			current2 = current2->GetNext(); // Moving to the next Node
		}
		current1 = current1->GetNext(); // Moving to the next Node
	}
	return *Temp; // Retunring to the new list
}


template<class T>
LinkedList<T>& LinkedList<T>::Union(const LinkedList<T>& templist)
{
	LinkedList<T>* Temp = new LinkedList<T>;
	Node<T>* current1 = this->Head;
	Node<T>* current2 = templist.Head;

	while (current1 != NULL) // Copying all Of the list
	{
		if (!Temp->IfExists(current1->GetData()))
			*Temp += (current1->GetData());
		current1 = current1->GetNext();
	}

	current1 = this->Head;

	while (current2 != NULL) // Copying all the nodes from the second list that are dont exist in the first list
	{
		if (!Temp->IfExists(current2->GetData()))
			*Temp += current2->GetData();
		current2 = current2->GetNext();

	}

	return *Temp; // Returning the new list
}

template<class T>
void LinkedList<T>::SetSize(int num)
{
	this->Size = num; // Setting the new size
}

template<class T>
bool LinkedList<T>::IfExists(T& temp)
{
	Node<T>* Current = this->Head;
	while (Current != NULL) // Going all over the list
	{
		if (Current->GetData() == temp) // Checking if the data exists
			return true; // returning true
		Current = Current->GetNext(); // Moving to the next Node
	}
	return false; //returning false
}

template<class T>
Node<T>* LinkedList<T>::GetHead()
{
	return Head; // Returning the Head
}

template<class T>
int LinkedList<T>::GetSize()
{
	return this->Size; // Returning the size of the list
}
/////// Global Function \\\\\\\

template<class T>
ostream& operator<<(ostream& os, const LinkedList<T>& temp)
{
	Node<T>* current = temp.Head;
	while (current != NULL) // Printing all the list
	{
		os << current->GetData()<<"\t";
		current = current->GetNext();
	}
	os << endl;
	return os;
}