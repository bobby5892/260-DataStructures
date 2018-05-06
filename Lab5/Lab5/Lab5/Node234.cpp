//
//  Node234.cpp
//  Lab5
//
//  Created by Jim Bailey on 5/12/17.
//  Copyright © 2017 jim. All rights reserved.
//
#include "stdafx.h"
#include "Node234.h"
#include <sstream>

// constructor, set children to nullptr
// and number of values to zero
Node234::Node234()
{
	for (int i = 0; i < DEGREE; i++)
		children[i] = nullptr;
	numValues = 0;
}


// add or remove a child node
void Node234::addChild(int index, Node234 * child)
{
	children[index] = child;
	if (child != nullptr)
		child->parent = this;
}

Node234 * Node234::removeChild(int index)
{
	Node234 * temp = children[index];
	children[index] = nullptr;
	return temp;
}

// given an index, return that child pointer
Node234 * Node234::getChild(int index)
{
	return children[index];
}

// given an index, return that value
int Node234::getValue(int index)
{
	return values[index];
}

// return the parent pointer
Node234 * Node234::getParent()
{
	return parent;
}

// are there any children?
bool Node234::isLeaf()
{
	return children[0] == nullptr;
}

//how many values are present?
int Node234::getNumValues()
{
	return numValues;
}

// room for more values?
bool Node234::isFull()
{
	return numValues == DEGREE - 1;
}

// add a new value
// assume the node is not full
// return index where stored
int Node234::insertValue(int value)
{
	// insert value in proper place
	int index = numValues - 1;
	while (index >= 0 && values[index] > value)
	{
		values[index + 1] = values[index];
		index--;
	}
	values[++index] = value;
	numValues++;

	return index;
}

// remove the largest value present
// assumes node not empty
int Node234::removeValue()
{
	return values[--numValues];
}

// find a value, if present return its index
// if not present, return -1
int Node234::findValue(int value)
{
	for (int i = 0; i < numValues; i++)
		if (values[i] == value)
			return i;
	return -1;
}

// display this node
std::string Node234::displayNode()
{
	std::stringstream output;

	for (int i = 0; i < numValues; i++)
		output << "/" << values[i];     // "/value"

	output << "/" << std::endl;         // final "/"

	return output.str();
}
