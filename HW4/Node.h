#define _CRT_SECURE_NO_WARNINGS


#ifndef __NODE_H_
#define __NODE_H_
#include<iostream>
using namespace std;

template<class T>
class Node // A template class Node
{
public:
	Node(); //Default Ctor
	Node(T temp, Node* next); // Ctor with values
	~Node(); // Dtor
	Node(const Node<T>& temp); // CCtor
	Node<T>& operator=(const Node<T>& temp); // Operator=
	void SetNext(Node<T>* NextNode); // Setting the next value
	Node<T>* GetNext(); // Getting the next value
	void SetData(T& temp); // Setting the data
	T& GetData(); // Getting the data

private:
	T* Data;
	Node<T>* Next;
};

#endif

template<class T>
Node<T>::Node() // the default Ctor sets the values to NULL
{
	Data = NULL;
	Next = NULL;
}

template<class T>
Node<T>::Node(T temp, Node* next)
{
	this->Data = new T; // Allocates memory for the value
	*this->Data = temp; // Sets the value
	this->Next = next; // Sets the next pointer
}

template<class T>
Node<T>::~Node() // Dtor
{
	delete this->Next; // Deletes the next pointer
}

template<class T>
Node<T>::Node(const Node<T>& temp) // CCtor
{
	this->Data = new T; // Allocates memory for the value
	*this->Data = *temp.Data; // Sets the value
	this->Next = temp.Next; // Sets the next pointer
}

template<class T>
void Node<T>::SetNext(Node<T>* NextNode)
{
	this->Next = NextNode; // Sets the Next
}

template<class T>
Node<T>* Node<T>::GetNext()
{
	return this->Next; // Gets the Next
}

template<class T>
Node<T>& Node<T>::operator=(const Node<T>& temp)
{
	if (this != &temp) // If the object are different
	{
		this->Data = new T; // Allocates memory for the value
		*this->Data = *temp.Data; // Sets the value
		this->Next = temp.Next; // Sets the next pointer
	}
	return *this; // Returns the object
}

template<class T>
void Node<T>::SetData(T& temp)
{
	this->Data = &temp; // Sets the data
}

template<class T>
T& Node<T>::GetData()
{
	return *this->Data; // Gets the data
}