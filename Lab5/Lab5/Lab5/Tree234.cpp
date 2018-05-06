//
//  Tree234.cpp
//  Lab5
//
//  Created by Jim Bailey on 5/12/17.
//  Copyright © 2017 jim. All rights reserved.
//
#include "stdafx.h"
#include "Tree234.h"
#include <sstream>


//constructor
Tree234::Tree234()
{
	// initialize tree with an empty node
	root = new Node234;
}


// destructor -- delete them all recursively
Tree234::~Tree234()
{
	recDelete(root);
}

// delete all nodes for destructor
void Tree234::recDelete(Node234 * ptr)
{
	// if done with this branch, stop
	if (ptr == nullptr)
		return;

	// delete children first
	for (int i = 0; i < Node234::DEGREE; i++)
		recDelete(ptr->getChild(i));

	delete ptr;
}

// recursive find, called by find
bool Tree234::recFind(int value, Node234* ptr)
{
	if (ptr == nullptr)
		return false;

	int num = ptr->getNumValues();
	// otherwise, look at the node
	for (int i = 0; i < num; i++)
	{
		if (ptr->getValue(i) == value)
			return true;
		if (ptr->getValue(i) > value)
			return recFind(value, ptr->getChild(i));
	}

	return recFind(value, ptr->getChild(num));
}

// recursive display, called by display
std::string Tree234::recDisplay(Node234 * thisNode, int level, int childNumber)
{
	std::stringstream output;

	output << "level=" << level << " child=" << childNumber << " ";

	output << thisNode->displayNode();               // display this node

													 // call ourselves for each child of this node
	int numValues = thisNode->getNumValues();
	for (int j = 0; j<numValues + 1; j++)
	{
		Node234 * nextNode = thisNode->getChild(j);
		if (nextNode != NULL)
			output << recDisplay(nextNode, level + 1, j);
		else
			break;
	}
	return output.str();
}

// split a node, private method used in insert
// assumes the node is full
void Tree234::split(Node234* ptr)
{
	int valueB, valueC;
	Node234 * parent;
	Node234 * child2;
	Node234 * child3;
	int valueIndex;

	// remove two largest values
	valueC = ptr->removeValue();
	valueB = ptr->removeValue();
	// remove two rightmost children
	child2 = ptr->removeChild(2);
	child3 = ptr->removeChild(3);

	// create a new node
	// and put rightmost stuff in it
	Node234 * newRight = new Node234;
	newRight->insertValue(valueC);
	newRight->addChild(0, child2);
	newRight->addChild(1, child3);

	// special case root
	if (ptr == root)
	{
		// make a new root and attach this node to it
		root = new Node234;
		parent = root;
		root->addChild(0, ptr);
	}
	else
		parent = ptr->getParent();

	// now modify parent
	// move second value up to it
	// and connect newRight appropriately
	valueIndex = parent->insertValue(valueB);

	// move child links to the right as needed
	for (int i = parent->getNumValues() - 1; i > valueIndex; i--)
	{
		Node234 * temp = parent->removeChild(i);
		parent->addChild(i + 1, temp);
	}

	// now add new link in remaining slot
	parent->addChild(valueIndex + 1, newRight);
}

// get Next Child larger than value
// helper function for insert
Node234 * Tree234::getNextChild(Node234 * theNode, int value)
{
	for (int i = 0; i < theNode->getNumValues(); i++)
		if (value < theNode->getValue(i))
			return theNode->getChild(i);
	return theNode->getChild(theNode->getNumValues());
}


// add value to tree
void Tree234::insert(int value)
{
	Node234 * ptr = root;

	// break out when we find proper leaf
	while (true)
	{
		// if full, split it
		if (ptr->isFull())
		{
			// split it up
			split(ptr);
			// go up to parent to start over
			ptr = ptr->getParent();

			// go back down proper branch
			ptr = getNextChild(ptr, value);
		}

		// not full, then see if leaf
		else if (ptr->isLeaf())
			break;

		// not leaf, not full, go on down
		else
			ptr = getNextChild(ptr, value);

	}

	// found a leaf, put value in it
	ptr->insertValue(value);
}

// find a value, uses recursive method
bool Tree234::find(int value)
{
	return recFind(value, root);
}

// display tree, uses recursive method
std::string Tree234::display()
{
	return recDisplay(root, 0, 0);
}
/// Robert Moore
void  Tree234::addValue(int value) {
	this->insert(value);
}
bool  Tree234::isThere(int value) {
	return find(value);
}

std::string  Tree234::inOrder() {
	 return this->recDisplay(root, 0, 0);
}
