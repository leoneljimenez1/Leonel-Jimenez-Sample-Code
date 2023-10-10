#pragma once

#include "adstack.h"
#include "linkedlist.h"

template<typename TYPE>
class LinkedStack : public ADTStack<TYPE>
{
	LinkedList <TYPE> data;
public:

	
	// Pushes the item on to the top of the stack
	void push(TYPE item);

	//Removes the top item from the stack
	void pop();

	//Returns the top item stored on the stack
	TYPE peek();

	//Returns the number of items currently stored in the stack
	long getSize();

	/*************************************************************************************
	* Function to convert the contents of the stack to a string. The stack should be
	* converted with | at the bottom, and a comma separated list of each element
	* (all on one line)
	*
	* For example, if my stack had the values 5, 4, 3, 2, 1 (with 1 at the top), then
	* the output would be:
	* | 5, 4, 3, 2, 1
	*************************************************************************************/
	string toString();
};

template<typename TYPE>
void LinkedStack<TYPE>::push(TYPE item)
{
	data.insert(item, 0);
}

template<typename TYPE>
void LinkedStack<TYPE>::pop()
{
	data.remove(0);
}

template<typename TYPE>
TYPE LinkedStack<TYPE>::peek()
{
	return data.at(0);
}

template<typename TYPE>
long LinkedStack<TYPE>::getSize()
{
	return data.getSize();

}

template<typename TYPE>
string LinkedStack<TYPE>::toString()
{
	stringstream sstream;
	sstream << "| ";

	for (int i = data.getSize() - 1; i >= 0; i--)
	{
		sstream << data.at(i);

		if (i != 0)
		{
			sstream << ", ";
		}

	}

	return sstream.str();
}

