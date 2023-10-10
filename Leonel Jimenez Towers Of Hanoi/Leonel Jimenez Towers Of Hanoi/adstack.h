#pragma once
#include <string>
#include "linkedlist.h"
#include "exceptions.h"
#include "bubble.h"
#include <iostream>

using std::string;

template <typename TYPE>
class ADTStack {
public:

	//Pushes the item on to the top of the stack
	virtual void push(TYPE item) = 0;

	//Removes the top item from the stack
	virtual void pop() = 0;

	//Returns the top item stored on the stack
	virtual TYPE peek() = 0;

	//Returns the number of items currently stored in the stack
	virtual long getSize() = 0;

	/*************************************************************************************
	* Function to convert the contents of the stack to a string. The stack should be
	* converted with | at the bottom, and a comma separated list of each element
	* (all on one line)
	*
	* For example, if my stack had the values 5, 4, 3, 2, 1 (with 1 at the top), then
	* the output would be:
	* | 5, 4, 3, 2, 1
	*************************************************************************************/
	virtual string toString() = 0;
};

