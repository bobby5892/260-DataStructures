#pragma once
class Heap
{
	const int EMPTY = -1;
	const int DEFAULT_SIZE = 16;
	int maxSizeOfHeap;
	int currentSize;
	int* heap;
	void setEmpty();
	
	void recSwapParent(int size);
public:
	void insert(int value);
	int remove();
	int largest();
	void init();
	void growHeap(int newSize);
	int getLeft(int index);
	int getRight(int index);
	int getParent(int index);
	Heap();
	Heap(int howManyValues);
	Heap(int starters[]);
	void Heap::heapify();
	~Heap();
};

