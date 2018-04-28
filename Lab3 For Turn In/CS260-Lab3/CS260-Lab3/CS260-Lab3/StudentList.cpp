#include "stdafx.h"
#include <iostream>
#include <ostream>
#include <string>
#include <stdexcept>
#include "StudentList.h"
//#define DEBUG

// Insert a link pointing to s at the head of the list
void StudentList::insertHead(Student*s) {
	Link* newStudent = new Link;
	newStudent->value = s;
	newStudent->next = this->head;

	if (this->head == nullptr) {
		this->tail = newStudent;
	}
	this->head = newStudent;
#ifdef DEBUG
	std::cout << "Adding Student at head: " << s->getName() << std::endl;
	this->displayList();
#endif // DEBUG
}
//Insert a link pointing to s at the end of the list
void StudentList::insertTail(Student*s) {
	Link* newStudent = new Link;
	newStudent->value = s;
	
	if (this->tail == nullptr) {
		this->head = newStudent;
	}
	this->tail->next = newStudent;
	newStudent->next = nullptr;
	this->tail = newStudent;

#ifdef DEBUG
	std::cout << "Adding Student at tail: " << s->getName() << std::endl;
	this->displayList();
#endif // DEBUG

}
//Delete first link and return its value.Throw anexception if the list is empty.
Student* StudentList::deleteHead() {
	if (this->head == nullptr) {
		throw std::underflow_error("Empty List");
	}
	Link* temp = this->head;
	this->head = this->head->next;
	if (this->head == nullptr) {
		this->tail = nullptr;
	}

#ifdef DEBUG
	std::cout << "Deleting Student at head" << std::endl;
	this->displayList();
#endif // DEBUG
	return temp->value;
}

// None Return true if list is empty Return true if a link exists containing a Student with
bool StudentList::isEmpty() {
	if (this->head == nullptr)
		return true;
#ifdef DEBUG
	std::cout << "List Reporting Empty" << std::endl;
	this->displayList();
#endif // DEBUG

	return false;
}


//String name the name.If the key is not found in the list, return false 
bool StudentList::findKey(std::string name) {
	Link* temp = this->head;
	while (temp != nullptr) {
		if (temp->value->getName() == name) { 
			return true; 
		}
		temp = temp->next;
	}
	return false;
}

// String Name Delete the first link you find that contains a Student 
//with the name.Return true if success, false if failure.
bool StudentList::deleteKey(std::string name) {
	Link* temp  = this->head;
	Link *before = this->head;
	while (temp != nullptr) {
		if (temp->value->getName() == name) {
			before->next = temp->next;
			
			
			temp = temp->next;
			
#ifdef DEBUG
			std::cout << "Deleting Student at Key: " << name << std::endl;
			this->displayList();
#endif // DEBUG
			return true;
		}
		before = temp;
		temp = temp->next;

	}
	return false;

}

// show the list
void StudentList::displayList() {
	Link* temp = this->head;
	while (temp != nullptr) {
		std::cout << temp->value->getName() << " " << std::endl;
		temp = temp->next;
	}
}

StudentList::StudentList() {
	this->head = nullptr;
	this->tail = nullptr;
}

StudentList::~StudentList() {
	Link *temp = this->head;
	while (this->head != nullptr) {
		temp = this->head;
		this->head = this->head->next;
		delete temp;
	}
#ifdef DEBUG
	
	this->displayList();
#endif // DEBUG
}