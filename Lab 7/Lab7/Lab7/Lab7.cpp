// Lab7.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
//
//  main.cpp
//  260_Lab 7
// Test Driver for Lab 7
//     Median via partitioning
//     Min Spanning Tree via Depth First
//     Min Spanning Tree via Breadth First
//
//  Created by Jim Bailey on 5/25/18.
//  Licensed under a Creative Commons Attribution 4.0 International License.
//

#define TEST_MEDIAN
#define TEST_DEPTH_FIRST
#define TEST_BREADTH_FIRST

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <algorithm>
#include <utility>
#include <string>
// helper functions
// generic display method
void displayArray(int theArray[], int length);
// load array with random numbers
void fillArray(int theArray[], int length);

#ifdef TEST_MEDIAN
#include "Partition.h"
#endif

#if defined TEST_DEPTH_FIRST || defined TEST_BREADTH_FIRST
#include "Graph.h"
#endif




// with a real datatype

int main() {
#ifdef TEST_MEDIAN
	std::cout << "This tests finding the median value via recursive partitioning" << std::endl;
	srand(static_cast<int>(time(NULL)));

	// create the array
	const int SIZE = 19;
	int * values = new int[SIZE];

	// initialize it with random numbers
	fillArray(values, SIZE);

	// Starting array
	std::cout << std::endl << "The unsorted data is " << std::endl;
	displayArray(values, SIZE);

	// Find median
	std::cout << std::endl << "The median value is " << findMedian(values, SIZE) << std::endl;


	// After finding median
	std::cout << std::endl << "The median should be at end of first line" << std::endl;
	std::cout << " of the partially sorted data: " << std::endl;
	displayArray(values, SIZE);

	// After sorting
	std::cout << std::endl << "The fully sorted data is " << std::endl;
	std::sort(values, values + SIZE);
	displayArray(values, SIZE);

	std::cout << std::endl << "Done testing find median " << std::endl << std::endl;

#endif // TEST_MEDIAN

#if defined TEST_DEPTH_FIRST || defined TEST_BREADTH_FIRST

	std::cout << "Displaying tree for min traversals" << std::endl << std::endl;
	Graph tree;

	tree.addNode('A');
	tree.addNode('C');
	tree.addNode('T');
	tree.addNode('Z');
	tree.addNode('X');
	tree.addNode('K');
	tree.addNode('Q');
	tree.addNode('J');
	tree.addNode('M');
	tree.addNode('U');

	std::cout << "The nodes are (in order added): " << std::endl << tree.listNodes() << std::endl << std::endl;

	tree.addEdge('A', 'C');
	tree.addEdge('A', 'T');
	tree.addEdge('A', 'Z');
	tree.addEdge('X', 'C');
	tree.addEdge('C', 'K');
	tree.addEdge('T', 'Q');
	tree.addEdge('K', 'Q');
	tree.addEdge('Q', 'J');
	tree.addEdge('J', 'M');
	tree.addEdge('Z', 'X');

	std::cout << "The edge list is: " << std::endl << tree.displayEdges() << std::endl << std::endl;

#endif // TEST_DEPT_FIRST OR TEST_BREADTH_FIRST

#ifdef TEST_DEPTH_FIRST

	std::cout << "Min tree from depth first traversal starting at Q" << std::endl;
	std::cout << "Should be:  Q-J J-M Q-K K-C C-X X-Z Z-A A-T" << std::endl;
	std::cout << " and it is: ";
	std::cout << tree.depthFirst('Q') << std::endl;

#endif // TEST_DEPTH_FIRST

#ifdef TEST_BREADTH_FIRST

	std::cout << "Min tree from breadth first traversal starting at Q" << std::endl;
	std::cout << "Should be:  Q-J Q-K Q-T J-M K-C T-A C-X A-Z" << std::endl;
	std::cout << " and it is: ";
	std::cout << tree.breadthFirst('Q') << std::endl;

#endif // TEST_BREAD_FIRST


	return 0;
}

// generic display method
void displayArray(int theArray[], int length)
{
	const int LINE_LEN = 10;
	const int NUM_WID = 5;

	for (int i = 0; i < length; i++)
	{
		std::cout << std::setw(NUM_WID) << theArray[i];
		if ((i + 1) % LINE_LEN == 0)
			std::cout << std::endl;
	}
	std::cout << std::endl;
}


// load array with random numbers
void fillArray(int theArray[], int length)
{
	const int MAX = 100;
	const int MIN = 1;

	for (int i = 0; i < length; i++)
		theArray[i] = rand() % MAX + MIN;
}
