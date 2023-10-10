#pragma once

template <typename TYPE>
class ADTList
{
public:
	
	// Insert at a specific index
	virtual void insert(TYPE item, int index = 0) = 0;

	// Remove at a given index
	virtual void remove(int index) = 0;

	// Retrieve an item at a given index
	virtual TYPE at(int index) = 0;

	/********************************************************************************* 
	* Sort data in the list using a comparison function, returns - 1 if the first
	* item is less than second, 0 if they are equal
	* and 1 if the second is larger than the first
	**********************************************************************************/
	virtual void sort(int(*cmp)(const TYPE& item1, const TYPE& item2)) = 0;

	// Search for a given item, returns the index if the item is found
	virtual int search(TYPE item, int(*cmp)(const TYPE& item1, const TYPE& item2)) = 0;

	// Attain the size of the list
	virtual int getSize() = 0;
};
