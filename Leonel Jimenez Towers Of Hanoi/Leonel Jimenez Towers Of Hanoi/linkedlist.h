#pragma once

#include "list.h"
#include "exceptions.h"
#include <sstream>
#include "bubble.h"

using std::stringstream;
using std::getline;

template <typename TYPE>
class Node
{
public:

    Node* next;
    Node* prev;
    TYPE data;


    Node()
    {
        next = nullptr;
        prev = nullptr;
    }

};

template <typename TYPE>
class LinkedList : public ADTList<TYPE>
{
public:

    LinkedList();
    ~LinkedList();
   
    virtual void insert(TYPE item, int index = 0);

    virtual void remove(int index);
    
    //Used to retrieve an item at the given index
    virtual TYPE at(int index);

    virtual void sort(int(*cmp)(const TYPE& item1, const TYPE& item2));

    // Used to search for an item, returns an index
    virtual int search(TYPE item, int(*cmp)(const TYPE& item1, const TYPE& item2));

    // Used to get the size of the list
    virtual int getSize();

private:
    Node<TYPE>* head;
    Node<TYPE>* tail;
    int count;

    Node<TYPE>* nodeAt(int index);
    void swapNodes(Node<TYPE>* node1, Node<TYPE>* node2);
};


template <typename TYPE>
LinkedList<TYPE>::LinkedList()
{
    head = nullptr;
    tail = nullptr;
    count = 0;
}

template <typename TYPE>
LinkedList<TYPE>::~LinkedList()
{
    while (count)
    {
        remove(0);
    }
}


template<typename TYPE>
void LinkedList<TYPE>::insert(TYPE item, int index)
{
    if (index == -1)
    {
        index = count;
    }
    Node<TYPE>* newNode = new Node <TYPE>;
    newNode->data = item;

    try
    {

        Node<TYPE>* current = nodeAt(index);
        Node<TYPE>* previousNode = current->prev;
        newNode->next = current;
        newNode->prev = previousNode;
        current->prev = newNode;



        if (previousNode != NULL)
        {
            previousNode->next = newNode;
        }


    }
    catch (IndexOutOfBounds exception)
    {
        if (index == count)
        {
            newNode->prev = tail;
            if (tail != NULL)
            {
                tail->next = newNode;
            }

            tail = newNode;
        }

        else
        {
            throw exception;
        }

    }


    if (index == 0)
    {
        head = newNode;
    }

    count++;
}

template<typename TYPE>
void LinkedList<TYPE>::remove(int index)
{
    if (head == NULL)
    {
        stringstream sstream;
        sstream << "Index " << index << " is out of bounds";
        string msg;
        getline(sstream, msg);
        throw IndexOutOfBounds(msg);

        return;
    }


    Node<TYPE>* current = nodeAt(index);
    Node<TYPE>* nextNode = current->next;
    Node<TYPE>* previousNode = current->prev;

    if (previousNode != NULL)
    {
        previousNode->next = nextNode;
    }

    if (nextNode != NULL)
    {
        nextNode->prev = previousNode;
    }

    if (current == head)
    {
        head = nextNode;
    }

    if (current == tail)
    {
        tail = previousNode;
    }

    delete current;

    count--;
}

template<typename TYPE>
TYPE LinkedList<TYPE>::at(int index)
{
    Node<TYPE>* temp = nodeAt(index);

    return temp->data;
}



template<typename TYPE>
void LinkedList<TYPE>::sort(int(*cmp)(const TYPE& item1, const TYPE& item2))
{
    bool swapped;
    swapped = true;
    while (swapped)
    {
        swapped = false;
        Node<TYPE>* current = head;
        while (current->next != nullptr)
        {
            Node<TYPE>* next = current->next;
            if (cmp(current->data, next->data) > 0)
            {
                swapNodes(current, next);
                swapped = true;
                continue;
            }
            current = current->next;
        }
    }
}


template<typename TYPE>
int LinkedList<TYPE>::search(TYPE item, int(*cmp)(const TYPE& item1, const TYPE& item2))
{
    Node<TYPE>* temp = head;
    int index = 0;
    while (temp != nullptr)
    {

        if (cmp(temp->data, item) == 0)
        {
            return index;

        }
        temp = temp->next;
        index++;
    }
    return -1;
}

template<typename TYPE>
int LinkedList<TYPE>::getSize()
{
    return count;
}


template <typename TYPE>
typename Node<TYPE>* LinkedList<TYPE>::nodeAt(int index)
{
    int position = 0;
    if (index < 0 || index >= count)
    {
        // Throw an index out of bounds exception
        stringstream sstream;
        sstream << "Index " << index << " is out of bounds";
        string msg;
        getline(sstream, msg);
        throw IndexOutOfBounds(msg);
    }
    Node<TYPE>* temp = head;

    while (index != position)
    {
        temp = temp->next;
        position++;

    }

    return temp;
}

// Swap nodes next to each other

template <typename TYPE>
void LinkedList<TYPE>::swapNodes(Node<TYPE>* node1, Node<TYPE>* node2)
{
    Node <TYPE>* temp = node1->prev;

    Node <TYPE>* temp2 = node2->next;

    if (temp != NULL)
    {
        temp->next = node2;
    }

    if (temp2 != NULL)
    {
        temp2->prev = node1;
    }

    node2->next = node1;
    node1->next = temp2;

    node2->prev = temp;
    node1->prev = node2;

    if (node1 == head)
    {
        head = node2;

    }

    if (node2 == tail)
    {
        tail = node1;

    }
}