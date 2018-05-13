#include <sstream>
#include <ostream>
#include <string>
#include <exception>
#include <cmath>
#pragma once
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
		return "0";
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
template <typename T> class ChainHashTable
{
public:
	ChainHashTable(){
		this->sizeOfData = 31;
		this->data = new Link<T>[this->sizeOfData];
	}
	ChainHashTable(int size) {
		this->sizeOfData = size;
		this->data = new Link<T>[this->sizeOfData];
	}
	bool findValue(T value) {
		Link<T>* temp = (this->data + (this->index(value) % this->sizeOfData));
		while (temp != nullptr) {
			if (temp->get() == value) {
				return true;
			}
			temp = temp->getNext();
		}
		return false;
	}
	bool removeValue(T value) {
		Link<T>* temp = (this->data + (this->index(value) % this->sizeOfData));
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
	void addValue(T value) {
		int index = (this->index(value) % this->sizeOfData);
		Link<T>* temp = (this->data + index);
		// Move to open position - nullptr
		while (temp != nullptr) {
			temp = temp->getNext();
		}
		// put it there
		temp = new Link<T>(nullptr, value);
	}
	// print out the table
	std::string displayTable() {
		std::stringstream  output;
		for (int i = 0; i < this->sizeOfData; i++) {
			Link<T>* temp = (this->data + i);
			while (temp != nullptr) {
				output << temp->ToString() << " ";
				temp = temp->getNext();
			}
		}
		return output.str();
	}
	~ChainHashTable(){}
private:
	Link<T>* data;
	int sizeOfData;
	// Get an index for it
	int index(T value) {
		std::istringstream iss(value);

		int asciiValue = 0;
		std::string temp = iss.str();
		// get ascii value
		for (int i = 0; i < temp.length(); i++) {
			// Multiply by 10 ^ i
			asciiValue += pow(10,i)*(int)(temp[i]);
		}
		
		return asciiValue;
	
	}
};

