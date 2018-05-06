//
//  Tree234.h
//  Lab5
//
//  Created by Jim Bailey on 5/12/17.
//  Copyright © 2017 jim. All rights reserved.
//

#ifndef Tree234_h
#define Tree234_h

#include <string>

#include "Node234.h"

class Tree234 {
	Node234 * root;

	// private methods
	// delete all nodes for destructor
	void recDelete(Node234 * ptr);

	// recursive find
	bool recFind(int value, Node234 * ptr);

	// recursive display
	std::string recDisplay(Node234 * thisNode, int level, int childNumber);

	// split a node
	void split(Node234* ptr);

	// get the next higher child
	Node234 * getNextChild(Node234* theNode, int value);

public:

	void addValue(int value);
	bool isThere(int value);
	std::string inOrder();
	
	Tree234();
	~Tree234();

	// add value to tree
	void insert(int value);
	// find a value,
	bool find(int value);

	// display tree
	std::string display();

};




#endif /* Tree234_h */
