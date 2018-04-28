//
//  List.h
//  Double Ended Single Linked List
//
//  Created by Jim Bailey on 4/22/17.
//  Copyright © 2017 jim. All rights reserved.
//

#ifndef List_h
#define List_h

#include <stdexcept>
#include <sstream>


class Link {
    private:
            // data contained in link
        int value;
            // pointer to the next link in the list
        Link * next;
            // pointer to the previous link in the list
        Link * prev;
    public:
            // constructor, default initialization of next to nullptr
        Link(int v, Link * n = nullptr, Link * p = nullptr) : value(v), next(n), prev(p) { }
    
            // basic setters and getters
        void setNext(Link * n) { next = n; }
        Link * getNext() { return next; }
        void setPrev(Link * p) { prev = p; }
        Link * getPrev() { return prev; }
        int getValue() { return value; }
};

class List {
    private:
            // a pointer to the start of the list
        Link * head;
            // a pointer to the end of the list
        Link * tail;
            // a pointer to a recently found item
        Link * iter;
    public:
            // constructor initializes the head and iter
        List();
            // destructor, deletes any remaining links
        ~List();
    
            // add a new link to the start of the list
        void addHead(int value);
            // add a new link to the end of the list
        void addTail(int value);
            // remove a link from the start of the list, returning
            // its value. Throw an exception on an empty list
        int removeHead();
            // remove a link from the end of the list, returning
            // its value. Throw an exception on an empty list
        int removeTail();
    
            // see if a value is present in the list
        bool findValue(int value);
            // delete a value if present
        bool findRemove(int value);
    
            // display list starting at head
        std::string displayList();
    
            // support list sorted smallest to largest
        void addSorted(int value);
    
            // methods to support pointers to recently found items
        bool findIter(int value);
        bool insertIter(int value);
        bool appendIter(int value);
        bool removeIter();
};

class Stack {
    private:
        List theList;
    public:
        void push(int value) { theList.addHead(value); }
        int pop() { return theList.removeHead(); }
};

class Queue {
private:
    List theList;
public:
    void add(int value) { theList.addTail(value); }
    int remove() { return theList.removeHead(); }
};

#endif /* List_h */
