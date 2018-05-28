#pragma once
class Stack
{

	Dequeue *que;
public:
	Stack();
	//Overloaded Constructor
	Stack(int howBig);
	void push(int value);
	int pop();
	int peek();
	~Stack();

};

