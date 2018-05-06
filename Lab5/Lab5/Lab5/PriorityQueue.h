#pragma once
class PriorityQueue
{
	Heap* heap;
public:
	PriorityQueue();
	PriorityQueue(int size);
	void insert(int value);
	int peek();
	int remove();

	~PriorityQueue();
};

