#pragma once

#ifndef _LINKEDLIST_h_
#define _LINKEDLIST_h_

#include "Node.h"
#include <assert.h>
#include <string>
#include <stdexcept>

using namespace std;

// List ------------------------------------------------------------------------------------------
template <class itemtype>
class LinkedList
{
private:
    Node<itemtype>* headPtr;
    int itemCount;
    Node<itemtype>* getNodeAt(int pos) const;
public:
    LinkedList();
    LinkedList(Node<itemtype>* headPtr);
    LinkedList(const LinkedList& aList);
    ~LinkedList();
    
    bool isEmpty() const;
    int getLengh() const;
    bool insert(int pos, const itemtype& newEntry);
    bool push(const itemtype& newEntry);
    bool remove(int pos);
    void clear();
    itemtype getEntry(int pos) const;
    itemtype operator[](int pos) const;
    
    void setEntry(int pos, const itemtype& newEntry);
};



// LinkedList -----------------------------------------------------------------
template <class itemtype>
Node<itemtype>* LinkedList<itemtype>::getNodeAt(int pos) const
{
    assert((pos >= 1) && (pos <= itemCount));
    
    Node<itemtype>* tempPtr = headPtr;
    if (pos == 1)
        return tempPtr;
    else
        for (int i = 1; i < pos; i++)
            tempPtr = tempPtr->getNext();
    return tempPtr;
}


template <class itemtype>
LinkedList<itemtype>::LinkedList() : headPtr(nullptr), itemCount(0)
{
}

template <class itemtype>
LinkedList<itemtype>::LinkedList(Node<itemtype>* headPtr) : itemCount(0)
{
    this->headPtr = headPtr;
}

template <class itemtype>
LinkedList<itemtype>::~LinkedList()
{
    clear();
}

template <class itemtype>
LinkedList<itemtype>::LinkedList(const LinkedList& aList)
{
    this->headPtr = aList.headPtr;
    this->itemCount = aList.itemCount;
}

template <class itemtype>
bool LinkedList<itemtype>::isEmpty() const
{
    return (headPtr == nullptr);
}

template <class itemtype>
int LinkedList<itemtype>::getLengh() const
{
    return itemCount;
}

template <class itemtype>
bool LinkedList<itemtype>::insert(int pos, const itemtype& newEntry)
{
    bool isAbleToInsert = ((pos >= 1) && (pos <= itemCount + 1));
    if (isAbleToInsert)
    {
        Node<itemtype>* newNodePtr = new Node<itemtype>(newEntry);
        
        if (pos == 1)
        {
            newNodePtr->setNext(headPtr);
            headPtr = newNodePtr;
        }
        else
        {
            Node<itemtype>* prePtr = getNodeAt(pos - 1);
            newNodePtr->setNext(prePtr->getNext());
            prePtr->setNext(newNodePtr);
        }
        itemCount++;
    }
    return isAbleToInsert;
}

template <class itemtype>
bool LinkedList<itemtype>::remove(int pos)
{
    bool isAbleToRemove = ((pos >= 1) && (pos <= itemCount));
    if (isAbleToRemove)
    {
        Node<itemtype>* curPtr = nullptr;
        if (pos == 1)
        {
            curPtr = headPtr;
            headPtr = headPtr->getNext();
        }
        else
        {
            Node<itemtype>* prePtr = getNodeAt(pos - 1);
            curPtr = prePtr->getNext();
            prePtr->setNext(curPtr->getNext());
        }
        curPtr->setNext(nullptr);
        delete curPtr;
        curPtr = nullptr;
        itemCount--;
    }
    return isAbleToRemove;
}

template <class itemtype>
void LinkedList<itemtype>::clear()
{
    while (!isEmpty())
        remove(1);
}

template <class itemtype>
itemtype LinkedList<itemtype>::getEntry(int pos) const
{
    bool isAbleToGet = ((pos >= 1) && (pos <= itemCount));
    if (isAbleToGet)
    {
        Node<itemtype>* posPtr = getNodeAt(pos);
        return posPtr->getItem();
    }
    else
    {
        string message = "getEntry() called with an empty list or ";
        message += "invalid position.";
        throw logic_error(message);
    }
}

template <class itemtype>
void LinkedList<itemtype>::setEntry(int pos, const itemtype& newEntry)
{
    bool isAbleToSet = ((pos >= 1) && (pos <= itemCount));
    if (isAbleToSet)
    {
        Node<itemtype>* posPtr = getNodeAt(pos);
        posPtr->setItem(newEntry);
    }
    else
    {
        string message = "getEntry() called with an empty list or ";
        message += "invalid position.";
        throw logic_error(message);
    }
}

template <class itemtype>
itemtype LinkedList<itemtype>::operator[](int pos) const
{
    return getEntry(pos);
}

template <class itemtype>
bool LinkedList<itemtype>::push(const itemtype& newEntry)
{
    return insert(getLengh() + 1, newEntry);
}


#endif






