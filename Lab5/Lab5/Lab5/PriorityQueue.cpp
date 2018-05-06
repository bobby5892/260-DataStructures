#include "stdafx.h"
#include "Heap.h"
#include "PriorityQueue.h"

PriorityQueue::PriorityQueue(int size)
{
	this->heap = new Heap(size);
}

PriorityQueue::PriorityQueue()
{
	this->heap = new Heap;
}
void PriorityQueue::insert(int value) {
	this->heap->insert(value);
}
int PriorityQueue::peek() {
	return this->heap->largest();

}
int PriorityQueue::remove() {
	return this->heap->remove();
}

PriorityQueue::~PriorityQueue()
{
}
