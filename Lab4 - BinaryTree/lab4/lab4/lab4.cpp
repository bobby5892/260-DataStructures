//
//  main.cpp
//  binary_search_tree
//
//  Created by Jim Bailey on 11/1/17.
//  Copyright © 2017 jim. All rights reserved.
//
#include "stdafx.h"
#include <iostream>
#include "Tree.h"

using namespace std;

#define TEST_INTEGER
#define TEST_CHAR
#define TEST_STRING

// this is optional
//#define TEST_DISPLAY

int main()
{

#ifdef TEST_INTEGER
	Tree<int> fir;
	int int_values[] = { 20, 30, 25, 35, 10, 15, 5, 2, 7, 12, 22, 27, 32, 37, 17 };
	const int NUM_INTS = 15;

	cout << endl << "Testing Tree for integers " << endl;

	// build a nice noble fir that is balanced
	cout << " First add 15 integer values " << endl;
	for (int i = 0; i < NUM_INTS; i++)
		fir.insertItem(int_values[i]);

	// check find
	cout << endl << " Testing find, should find 5 and 25, not find 21 or 0: " << endl;
	cout << "Looking for 5 " << (fir.isPresent(5) ? "found" : "not found") << endl;
	cout << "Looking for 25 " << (fir.isPresent(25) ? "found" : "not found") << endl;
	cout << "Looking for 21 " << (fir.isPresent(21) ? "found" : "not found") << endl;
	cout << "Looking for 0 " << (fir.isPresent(0) ? "found" : "not found") << endl;

	// traversals
	cout << endl << "Pre-order traversal" << endl << " Should be:  20   10    5    2    7   15   12   17   30   25   22   27   35   32   37" << endl;
	cout << " and is:  " << fir.preOrder() << endl;
	cout << endl << "In-order traversal" << endl << " Should be:   2    5    7   10   12   15   17   20   22   25   27   30   32   35   37" << endl;
	cout << " and is:  " << fir.inOrder() << endl;
	cout << endl << "Post-order traversal" << endl << " Should be:   2    7    5   12   17   15   10   22   27   25   32   37   35   30   20" << endl;
	cout << " and is:  " << fir.postOrder() << endl;

	// delete 10 and see if still there
	cout << endl << " Now testing delete, 10 should be there and then gone" << endl;
	cout << "Looking for 10 " << (fir.isPresent(10) ? "found" : "not found") << endl;
	fir.removeItem(10);
	cout << "Looking for 10 " << (fir.isPresent(10) ? "found" : "not found") << endl;

	// Now add 10 back
	cout << endl << " Now seeing if adding 10 back works" << endl;
	fir.insertItem(10);
	cout << "Looking for 10 " << (fir.isPresent(10) ? "found" : "not found") << endl;

	cout << endl << endl << "Done with integer tests" << endl << endl;

#endif // TEST_INTEGER

#ifdef TEST_CHAR
	Tree<char> apple;
	char char_values[] = { 'M','G','T','D','J','Q','X','B','F','I','K','O','S','W','Y' };
	const int NUM_CHARS = 15;

	cout << endl << "Testing Tree for characters " << endl;

	// build a nice apple fir that is balanced
	cout << " First add 15 character values " << endl;
	for (int i = 0; i < NUM_CHARS; i++)
		apple.insertItem(char_values[i]);

	// check find
	cout << endl << " Testing find, should find T and M, not find R or A: " << endl;
	cout << "Looking for T " << (apple.isPresent('T') ? "found" : "not found") << endl;
	cout << "Looking for M " << (apple.isPresent('M') ? "found" : "not found") << endl;
	cout << "Looking for R " << (apple.isPresent('R') ? "found" : "not found") << endl;
	cout << "Looking for A " << (apple.isPresent('A') ? "found" : "not found") << endl;

	// traversals
	cout << endl << "Pre-order traversal" << endl << " Should be:   M    G    D    B    F    J    I    K    T    Q    O    S    X    W    Y" << endl;
	cout << " and is:  " << apple.preOrder() << endl;
	cout << endl << "In-order traversal" << endl << " Should be:   B    D    F    G    I    J    K    M    O    Q    S    T    W    X    Y" << endl;
	cout << " and is:  " << apple.inOrder() << endl;
	cout << endl << "Post-order traversal" << endl << " Should be:   B    F    D    I    K    J    G    O    S    Q    W    Y    X    T    M" << endl;
	cout << " and is:  " << apple.postOrder() << endl;

	// delete 10 and see if still there
	cout << endl << " Now testing delete, J should be there and then gone" << endl;
	cout << "Looking for J " << (apple.isPresent('J') ? "found" : "not found") << endl;
	apple.removeItem('J');
	cout << "Looking for J " << (apple.isPresent('J') ? "found" : "not found") << endl;

	// Now add 10 back
	cout << endl << " Now seeing if adding J back works" << endl;
	apple.insertItem('J');
	cout << "Looking for J " << (apple.isPresent('J') ? "found" : "not found") << endl;

	cout << endl << endl << "Done with character tests" << endl << endl;

#endif // TEST_CHAR

#ifdef TEST_STRING
	Tree<string> oak;
	string string_values[] = { "Oak", "Fir", "Ash", "Lime", "Pear", "Pine",  "Yew" };
	const int NUM_STRINGS = 7;

	cout << endl << "Testing Tree for strings " << endl;

	// build a nice oak fir that is balanced
	cout << " First add 7 tree names " << endl;
	for (int i = 0; i < NUM_STRINGS; i++)
		oak.insertItem(string_values[i]);

	// check find
	cout << endl << " Testing find, should find Oak and Pine, not find Spruce or Maple: " << endl;
	cout << "Looking for Oak " << (oak.isPresent("Oak") ? "found" : "not found") << endl;
	cout << "Looking for Pine " << (oak.isPresent("Pine") ? "found" : "not found") << endl;
	cout << "Looking for Spruce " << (oak.isPresent("Spruce") ? "found" : "not found") << endl;
	cout << "Looking for Maple " << (oak.isPresent("Maple") ? "found" : "not found") << endl;

	// traversals
	cout << endl << "Pre-order traversal" << endl << " Should be: Oak  Fir  Ash Lime Pear Pine  Yew" << endl;
	cout << " and is:  " << oak.preOrder() << endl;
	cout << endl << "In-order traversal" << endl << " Should be: Ash  Fir Lime  Oak Pear Pine  Yew" << endl;
	cout << " and is:  " << oak.inOrder() << endl;
	cout << endl << "Post-order traversal" << endl << " Should be: Ash Lime  Fir  Yew Pine Pear  Oak" << endl;
	cout << " and is:  " << oak.postOrder() << endl;

	// delete 10 and see if still there
	cout << endl << " Now testing delete, Fir should be there and then gone" << endl;
	cout << "Looking for Fir " << (oak.isPresent("Fir") ? "found" : "not found") << endl;
	oak.removeItem("Fir");
	cout << "Looking for Fir " << (oak.isPresent("Fir") ? "found" : "not found") << endl;

	// Now add 10 back
	cout << endl << " Now seeing if adding Fir back works" << endl;
	oak.insertItem("Fir");
	cout << "Looking for Fir " << (oak.isPresent("Fir") ? "found" : "not found") << endl;

	cout << endl << endl << "Done with string tests" << endl << endl;

#ifdef TEST_DISPLAY
	cout << endl << oak.displayTree() << endl;
#endif // TEST_DISPLAY

#endif // TEST_STRING

	return 0;
}