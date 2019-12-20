#pragma once


#ifndef _NODE_h_
#define _NODE_h_

// Node -------------------------------------------------------------------------------------------
template <typename ItemType>
class Node
{
private:
public:
    Node();
    Node(const ItemType& anItem);
    Node(const ItemType& anItem, Node<ItemType>* nextNodePtr);
    ItemType item;
    Node<ItemType>* next;
    void setItem(const ItemType& anItem);
    void setNext(Node<ItemType>* nextNodePtr);
    ItemType getItem() const;
    Node<ItemType>* getNext() const;
};



// Node implementation -------------------------------------------------------------------------------------------
template <typename ItemType>
Node<ItemType>::Node() : next(nullptr)
{
}

template <typename ItemType>
Node<ItemType>::Node(const ItemType& anItem) : item(anItem), next(nullptr)
{
}

template <typename ItemType>
Node<ItemType>::Node(const ItemType& anItem, Node<ItemType>* nextNodePtr) : item(anItem), next(nextNodePtr)
{
}

template <typename ItemType>
void Node<ItemType>::setItem(const ItemType& anItem)
{
    item = anItem;
}

template <typename ItemType>
void Node<ItemType>::setNext(Node<ItemType>* nextNodePtr)
{
    next = nextNodePtr;
}

template <typename ItemType>
ItemType Node<ItemType>::getItem() const
{
    return item;
}

template <typename ItemType>
Node<ItemType>* Node<ItemType>::getNext() const
{
    return next;
}



#endif


