#ifndef DEQUEUE_H
#define DEQUEUE_H
#include <string>


/*
Create a class thatimplements a double-ended queue as described in Moodle. This class should be
implemented using an array as the underlying data structure.

Your default constructor should create an
array of 100 elements and you should have a overloaded constructor with a parameter for the array size.

This class should have methods for insertLeft, insertRight, removeLeft, removeRight, isEmpty, and isFull.

The double-ended queue should wrap on the array.

That is, you do not move any items already in the
array, just increment and decrement the markers for right and left.

If asked to insert when full, you should create a new array twice as large and copy the existing elements
to it and when asked to remove an item when empty, you should throw an exception.
Note, you should not initialize the underlying array to NULL or zero or any other value.

*/

/*
[2]    -> [ 1]   -> [ 0]
[TAIL]-> [ DATA] -> [HEAD]
*/
class Dequeue
{
public:
	Dequeue();
	Dequeue(int specialSize);
	virtual ~Dequeue();
	// Add to tail
	void insertLeft(int entry);
	// Add to Head
	void insertRight(int entry);
	// Remove from Tail
	int removeLeft();
	// Remove from Head
	int removeRight();
	// Is the Queue Empty
	bool isEmpty();
	// Is the Queue Full
	bool isFull();
	// How many things are in the queue?
	int Count();
	// Display full array
	void displayArray();
	// Display Queue
	std::string displayQueue();
	// listLeftRight
	std::string listLeftRight();
	// Resize Queue
	void resizeArray(int newSize);

	//Added for Driver (that didn't match spec sheet ) //
	void addLeft(int entry) { this->insertLeft(entry); }
	int getLeft() { return this->removeLeft(); }
	void addRight(int entry) { this->insertRight(entry); }
	int getRight() { return this->removeRight(); }
protected:

private:
	// Pointer to an array of data
	int* data;
	// reference for front of the array
	int headIndex;
	// reference for tail of the array
	int tailIndex;
	// How big is the array
	int dataSize;

	// Setup
	void init(int howBig);

};

#endif // DEQUEUE_H
