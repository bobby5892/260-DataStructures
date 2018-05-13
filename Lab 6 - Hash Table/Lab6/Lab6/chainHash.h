#include <sstream>
#include <iostream>
#include <ostream>
#include <string>
#include <exception>
#include <cmath>
#pragma once
/*
CHAINED HASH TABLE
	ROBERT MOORE
	5/13/2018
*/
/*

LINK CLASS


*/
template <typename T> class Link {
public:
	Link() {
		this->next = nullptr;
	}
	Link(Link<T>* next, T value) {
		this->next = next;
		this->value = value;
	}
	T get() {
		return this->value;
	}
	std::string ToString() {
		// If its a string or char 
		std::istringstream iss(this->value);
		if (iss.str().length() == 0) {
			// Might be a number
			std::stringstream string;
			
			string << this->value;
			return string.str();
		}
		else {
			return iss.str();
		}
	}
	void set(T value) {
		this->value = value;
	}
	void setNext(Link* next) {
		this->next = next;
	}
	Link* getNext() {
		return this->next;
	}
private:
	Link<T>* next;
	T value;
};
/*

LIST CLASS


*/
template <typename T> class List {
public:	
	List() {
		this->head = nullptr;
	}
	void add(T value) {
		Link<T>* temp = head;
		head = new Link<T>(nullptr,value);
		head->setNext(temp);
	}
	bool find(T value) {
		Link<T>* temp = head;
		while (temp != nullptr) {
			if (temp->get() == value) { 
				return true; 
			}
			temp = temp->getNext();
		}
		return false;
	}
	bool removeValue(T value) {
		Link<T>* temp = this->head;
		Link<T>* prev = temp;
		while (temp != nullptr) {
			// Find the value
			if (temp->get() == value) {
				T found = temp->get();
				// Link previous to one after
				prev->setNext(temp->getNext());
				delete temp;
				//return found;
				return true;
			}
			// Set previous
			prev = temp;
			// Grab next
			temp = temp->getNext();
		}
		return false;
	}
	std::string displayList() {
		std::stringstream output;
		Link<T>* temp = this->head;
		if (temp != nullptr) {
			std::istringstream iss(temp->ToString());
			output << iss.str();
			output << ",";
			while (temp->getNext() != nullptr) {
				std::istringstream iss(temp->ToString());
				output << iss.str();
				
					output << ",";
				
				temp = temp->getNext();
			}
		}
		return output.str();
	}

private:
	Link<T>* head;
};
/*

CHAIN HASH TABLE CLASS  


*/
template <typename T> class ChainHashTable
{
public:
	ChainHashTable() {
		this->sizeOfData = 31;
		this->data = new List<T>[this->sizeOfData];
	}
	ChainHashTable(int size) {
		this->sizeOfData = size;
		this->data = new List<T>[this->sizeOfData];
	}
	bool findValue(T value) {
		List<T>* location = &this->data[this->index(value)];
		return   location->find(value);
	}
	bool removeValue(T value) {
		List<T>* location = &this->data[this->index(value)];
		return location->removeValue(value);
	}
	void addValue(T value) {
		List<T>* location = &this->data[this->index(value)];
		location->add(value);
	}
	// print out the table
	std::string displayTable() {
		std::stringstream output;
		for (int i = 0; i < this->sizeOfData; i++) {
			List<T> currentData = this->data[i];
 			output  << currentData.displayList();
		}
		return output.str();
	}
	~ChainHashTable() {}
private:
	List<T>* data;
	int sizeOfData;
	// Get an index for it
	int index(T value) {
		std::istringstream iss(value);

		int asciiValue = 0;
		std::string temp = iss.str();
		// get ascii value
		for (int i = 0; i < temp.length(); i++) {
			// Multiply by 10 ^ i
			asciiValue += pow(10, i)*(int)(temp[i]);
		}
		int hashedIndex = asciiValue % this->sizeOfData;
		return hashedIndex;

	}
};
