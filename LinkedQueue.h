#ifndef LINKEDQUEUE_H
#define LINKEDQUEUE_H

#include "Node.h"
#include <assert.h>
#include <string>
#include <stdexcept>

template <class itemtype>
class LinkedQueue
{
private:
    Node<itemtype>* headPtr;
    int itemCount;
    Node<itemtype>* getNodeAt(int pos) const;
public:
    LinkedQueue();
    LinkedQueue(Node<itemtype>* headPtr);
    LinkedQueue(const LinkedQueue& aList);
    ~LinkedQueue();
    
    bool isEmpty() const;
    int size() const;
    bool insert(int pos, const itemtype& newEntry);
    bool enqueue(const itemtype& newEntry);
    bool dequeue();
    void clear();
    itemtype getEntry(int pos) const;
    itemtype& operator[](int pos) const;
    
    void setEntry(int pos, const itemtype& newEntry);
};



// LinkedQueue -----------------------------------------------------------------
template <class itemtype>
Node<itemtype>* LinkedQueue<itemtype>::getNodeAt(int pos) const
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
LinkedQueue<itemtype>::LinkedQueue() : headPtr(nullptr), itemCount(0)
{
}

template <class itemtype>
LinkedQueue<itemtype>::LinkedQueue(Node<itemtype>* headPtr) : itemCount(0)
{
    this->headPtr = headPtr;
}

template <class itemtype>
LinkedQueue<itemtype>::~LinkedQueue()
{
    clear();
}

template <class itemtype>
LinkedQueue<itemtype>::LinkedQueue(const LinkedQueue& aList)
{
    this->headPtr = aList.headPtr;
    this->itemCount = aList.itemCount;
}

template <class itemtype>
bool LinkedQueue<itemtype>::isEmpty() const
{
    return (headPtr == nullptr);
}

template <class itemtype>
int LinkedQueue<itemtype>::size() const
{
    return itemCount;
}

template <class itemtype>
bool LinkedQueue<itemtype>::insert(int pos, const itemtype& newEntry)
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
bool LinkedQueue<itemtype>::dequeue()
{
    int pos = itemCount;
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
void LinkedQueue<itemtype>::clear()
{
    while (!isEmpty())
        this->dequeue();
}

template <class itemtype>
itemtype LinkedQueue<itemtype>::getEntry(int pos) const
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
void LinkedQueue<itemtype>::setEntry(int pos, const itemtype& newEntry)
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
itemtype& LinkedQueue<itemtype>::operator[](int pos) const
{
    itemtype* p = &headPtr->item;
    return *p;
}

template <class itemtype>
bool LinkedQueue<itemtype>::enqueue(const itemtype& newEntry)
{
    return insert(size() + 1, newEntry);
}

#endif //LINKEDQUEUE_H

