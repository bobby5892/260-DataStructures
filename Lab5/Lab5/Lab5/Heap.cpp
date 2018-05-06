#include "stdafx.h"
#include "Heap.h"
#include <stdexcept>
#include <utility>
/*
Heap
Arr[i/2]	Returns the parent node
Arr[(2*i)+1]	Returns the left child node
Arr[(2*i)+2]	Returns the right child node
*/
Heap::Heap()
{
	this->init();
}
Heap::Heap(int howManyValues) {
	this->init();
	this->maxSizeOfHeap = howManyValues;
	this->setEmpty();
}
Heap::Heap(int starters[]) {
	this->init();
	int counter = 0;
	// lets figure out how many there
	while (starters[counter] != NULL) {
		counter++;
	}
	// put em in
	for (int i = 0; i < counter; i++) {
		this->heap[i] = starters[i];
	}
}
void Heap::init() {
	this->maxSizeOfHeap = DEFAULT_SIZE;
	this->currentSize = 0;
	this->heap = new int[this->maxSizeOfHeap];
	this->setEmpty();
}
void Heap::insert(int value) {
	if (currentSize + 1 > maxSizeOfHeap) {
		growHeap(maxSizeOfHeap * 2);
	}
	this->heap[currentSize++] = value;
	// check for swap
	this->heapify();
}
void Heap::recSwapParent(int size) {
	if (size > 0) {
		if (this->heap[this->getParent(size)] < this->heap[size]) {

			int temp = this->heap[this->getParent(size)];

			this->heap[this->getParent(size)] = this->heap[size];

			this->heap[size] = temp;

			this->recSwapParent(this->getParent(size));
		}
	}
}
void Heap::heapify() {
	for(int i = this->currentSize; i > 0; i--){
		recSwapParent(i);
	}
}
void Heap::setEmpty() {
	for (int i = 0; i < this->maxSizeOfHeap; i++) {
		this->heap[i] = EMPTY;
	}
}
int Heap::remove() {
	if (this->currentSize == 0) {
		throw std::length_error("emtpy heap");
	}
	//Fill hole with last node added(largest index in array)
	
	int temp = this->heap[0];
	this->heap[0] = this->heap[currentSize--];
	this->heapify();
		
	return temp;
}
void Heap::growHeap(int newSize) {
	int* temp = this->heap;
	this->heap = new int[newSize];
	// adjust sizes
	this->maxSizeOfHeap = newSize;
	int currentSize = this->maxSizeOfHeap;
	// Set empty
	this->setEmpty();
	// move the values
	for (int i = 0; i < this->currentSize; i++) {
		this->heap[i] = temp[i];
	}
	
}
int Heap::largest() {
	return this->heap[0];
}
int Heap::getLeft(int index) {
	//Arr[(2 * i) + 1]	Returns the left child node
	return (2 * index) + 1;
}
int Heap::getRight(int index) {
	//Arr[(2 * i) + 2]	Returns the right child node
	return (2 * index) + 2;
}
int Heap::getParent(int index) {
	//Arr[i / 2]	Returns the parent node
	return  index / 2;
}

Heap::~Heap()
{
}
