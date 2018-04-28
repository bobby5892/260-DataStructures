//
//  List.cpp
//  Double Ended Double Linked List
//
//  Created by Jim Bailey on 4/22/17.
//  Copyright © 2017 jim. All rights reserved.
//

#include "List.h"

// constructor initializes the head, tail, and iter
List::List()
{
    head = tail = iter = nullptr;
}

// destructor, deletes any remaining links
List::~List()
{
        // start at the head
    Link * ptr = head;
    
        // continue until done
    while ( ptr != nullptr )
    {
            // temporarily save the link
        Link * temp = ptr;
            // move pointer to the next one
        ptr = ptr->getNext();
            // delete the no longer needed link
        delete temp;
    }
}

// add a new link to the start of the list
void List::addHead(int value)
{
        // if the list is empty, initialize both head and tail
    if ( head == nullptr )
        head = tail = new Link(value);
    
        // otherwise, just add a new link at the head
    else
    {
            // create new link will nullptr for prev
        Link * temp = new Link(value, head, nullptr);
            // set first link and head to point to it
        head->setPrev(temp);
        head = temp;
    }
}

// add a new link to the end of the list
void List::addTail(int value)
{
    // if the list is empty, initialize both head and tail
    if ( tail == nullptr )
        head = tail = new Link(value);
    
    // otherwise, just add a new link at the end
    else
    {
            // create the new link
        Link * temp = new Link(value, nullptr, tail);
            // set last link and tail to point to it
        tail->setNext(temp);
        tail = temp;
    }
}

// remove a link from the start of the list, returning
// its value. Throw an exception on an empty list
// take care of setting tail when list becomes empty
int List::removeHead()
{
        // if list is empty, throw an exception
    if ( head == nullptr )
        throw std::out_of_range("Empty List");
    
        // save the link and its value
    Link * temp = head;
    int value = temp->getValue();
    
        // update head
    head = head->getNext();
    
        // if list is now empty, update tail
    if ( head == nullptr )
        tail = nullptr;
        // otherwise, update prev on new first
    else
        head->setPrev(nullptr);
    
        // delete the old link and return
    delete temp;
    return value;
}

// remove a link from the end of the list, returning
// its value. Throw an exception on an empty list
// take care of setting head when list becomes empty
int List::removeTail()
{
    // if list is empty, throw an exception
    if ( tail == nullptr )
        throw std::out_of_range("Empty List");
    
    // save the link and its value
    Link * temp = tail;
    int value = temp->getValue();
    
    // update head
    tail = tail->getPrev();
    
    // if list is now empty, update tail
    if ( tail == nullptr )
        head = nullptr;
    // otherwise, update prev on new first
    else
        tail->setNext(nullptr);
    
    // delete the old link and return
    delete temp;
    return value;
}

// see if a value is present in the list
bool List::findValue(int value)
{
        // walk down the list from head until reach terminator
    for(Link * ptr = head; ptr != nullptr; ptr = ptr->getNext())
            //check each link for the desired value
        if ( ptr->getValue() == value )
                // and return true if it is found
            return true;
    
        // if you reach the end without finding the value, not there
    return false;
}


// delete a value if present
bool List::findRemove(int value)
{
        // special case empty list
    if ( head == nullptr )
        return false;
    
        // walk down the list, looking for the value
    for(Link * ptr = head; ptr; ptr = ptr->getNext())
    {
            // see if link is it
        if ( ptr->getValue() == value )
        {
                // special case head
            if ( ptr == head )
            {
                removeHead();
                return true;
            }
                // special case tail
            if ( ptr == tail )
            {
                removeTail();
                return true;
            }
                // typical link, set pointers around it
            ptr->getPrev()->setNext(ptr->getNext());
            ptr->getNext()->setPrev(ptr->getPrev());
            
                // delete it and return
            delete ptr;
            return true;
        }
    }
    
        // done with list without finding it
    return false;
}

// display list starting at head
std::string List::displayList()
{
        // define a string stream to gather the information
    std::stringstream ss;
    
        // walk down the list, until we reach terminating nullptr
    for(Link * ptr = head; ptr; ptr = ptr->getNext())
            // add next value to the stream
        ss << ptr->getValue() << " ";
    
        // add terminating endline
    ss << "\n";
    
        // return the string out of the stringstream
    return ss.str();
}

// support list sorted smallest to largest
void List::addSorted(int value)
{
        // if list is empty, insert at head
    if ( head == nullptr )
    {
        head = tail = new Link(value);
        return;
    }
    
        // if head is larger, special case
    if ( head->getValue() > value )
    {
        addHead(value);
        return;
    }
    
        // otherwise, walk down the list to find the right place to insert it
        // again, we have to look ahead as we go down the list
    Link * ptr = head;
    while ( ptr->getNext() != nullptr and ptr->getNext()->getValue() < value  )
        ptr = ptr->getNext();
    
        // ptr now points to the last link <= value
        // so create a new link and put it after ptr
    Link * temp = new Link(value, ptr->getNext(), ptr);
    ptr->setNext(temp);
    
        // fix the next links previous if necessary
    if ( temp->getNext() != nullptr )
        temp->getNext()->setPrev(temp);
    
        // otherwise, it is the new tail
    else
        tail = temp;
    
        // done, go away
    return;
}


// methods to support pointers to recently found items

//first find and set iter
bool List::findIter(int value)
{
    // walk down the list from head until reach terminator
    for(Link * ptr = head; ptr != nullptr; ptr = ptr->getNext())
        //check each link for the desired value
        if ( ptr->getValue() == value )
        {
            // save ptr and return true if it is found
            iter = ptr;
            return true;
        }
    
    // if you reach the end without finding the value, not there
    iter = nullptr;
    return false;
}

// now use iter for insert
bool List::insertIter(int value)
{
        // if iter not set, fail
    if ( iter == nullptr )
        return true;
    
        // special case head
    if ( iter == head )
    {
        head = new Link(value, head, nullptr);
        iter->setPrev(head);
        return true;
    }
    
        // otherwise do it
    Link * temp = new Link(value, iter, iter->getPrev());
    iter->getPrev()->setNext(temp);
    iter->setPrev(temp);
    
        // and return
    return true;
}

// now use iter for append
bool List::appendIter(int value)
{
        // if iter not set, fail
    if ( iter == nullptr )
        return true;
    
        // special case tail
    if ( iter == tail )
    {
        tail = new Link(value, nullptr, iter);
        iter->setNext(tail);
        return true;
    }
    
        // otherwise do it
    Link * temp = new Link(value, iter->getNext(), iter);
    iter->getNext()->setPrev(temp);
    iter->setNext(temp);
    
        // and return
    return true;
}

// now remove that link
bool List::removeIter()
{
        // if iter not set, fail
    if ( iter == nullptr )
        return false;
    
        // special case head
    if ( iter == head )
        removeHead();
    else
            // special case tail
        if ( iter == tail )
            removeTail();
    
            // typical link, deal with it
        else
        {
            iter->getNext()->setPrev(iter->getPrev());
            iter->getPrev()->setNext(iter->getNext());
            delete iter;
        }
    
        // now clean up and return
    iter = nullptr;
    return true;
}


