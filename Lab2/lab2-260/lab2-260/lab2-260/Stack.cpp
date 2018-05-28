#include "stdafx.h"
#include "Dequeue.h"
#include "Stack.h"



Stack::Stack()
{
	this->que = new Dequeue;
}
Stack::Stack(int howBig)
{
	this->que = new Dequeue(howBig);
}

void Stack::push(int value)
{
	this->que->insertLeft(value);
}

int Stack::pop()
{
	return this->que->removeLeft();
}

int Stack::peek()
{
	int temp = this->que->removeLeft();
	this->que->insertLeft(temp);
	return temp;
}
Stack::~Stack()
{
	delete[] this->que;
}
