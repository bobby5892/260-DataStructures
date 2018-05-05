#include "stdafx.h"
#include "ParseTree.h"
#include <stack>
#include <cctype>
#include <iostream>


// constructor, build tree from expression
ParseTree::ParseTree(std::string expression)
{
	root = doParse(expression);
}

// desctructor, delete nodes in tree
ParseTree::~ParseTree()
{
	recDestruct(this->root);
}

// inorder traversal
std::string ParseTree::inOrder()
{
	return recInOrder(this->root);
}

// postorder traversal
std::string ParseTree::postOrder()
{
	return recPostOrder(this->root);
}

// preorder traversal
std::string ParseTree::preOrder()
{
	return recPreOrder(this->root);
}

// helper function for doParse, true if valueis operator(+ - * /)
bool ParseTree::isOperator(char value)
{
	switch (value) {
		case '+':
			return true;
			break;
		case '-':
			return true;
			break;
		case '*':
			return true;
			break;
		case '/':
			return true;
			break;
	}
	return false;
}

// helper function for doParse, true if value is letter or digit
bool ParseTree::isOperand(char value)
{
	return isalnum(value);
}

// helper method to do the parsing and save tree
void ParseTree::doParse(std::string exp)
{
	recDoParse(exp, this->root);
}
ParseNode* ParseTree::recDoParse(std::string exp, ParseNode* ptr) {
	std::string thisOne;
	thisOne = exp.substr(0, 1);
	exp = exp.substr(1, exp.length() - 1);
	/*If the current token is a '(', add a new node as the left child of the current node,
	and descend to the left child.*/
	if (thisOne == "(") {
		ParseNode* newNode = new ParseNode;
		newNode->value = thisOne[0];
		newNode->left = nullptr;
		newNode->right = nullptr;
		// Descend to child
		recDoParse(exp, newNode->left);
	}
	/*If the current token is in the list['+', '-', '/', '*'],
	set the root value of the current node to the operator represented
	by the current token.

	Add a new node as the right child of the current node and descend to the right child.*/
	else if ((thisOne == "+") || (thisOne == "-") || (thisOne == "/") || (thisOne == "*")) {
		ptr->value = thisOne[0];
		ptr->right = new ParseNode;
		recDoParse(exp, ptr->right);
	}
/*
	If the current token is a number, set the root value
	of the current node to the number and return to the parent.
*/
	else if (isalnum(thisOne[0])) {
		ptr->value = thisOne[0];
		return nullptr;
	}
	/*
	If the current token is a ')', go to the parent of the current node.
	*/
	else if (thisOne[0] = ')') {
		return nullptr;
	}
	return nullptr;
}

// recursive helper methods
void ParseTree::recDestruct(ParseNode * ptr)
{
	recDestruct(ptr->left);
	recDestruct(ptr->right);
	delete(ptr);
}
std::string ParseTree::recInOrder(ParseNode * ptr)
{
	std::string output = "";
	output += recInOrder(ptr->left);
	output += ptr->value;
	output += recInOrder(ptr->right);
	return output;
}
std::string ParseTree::recPostOrder(ParseNode * ptr)
{
	std::string output = "";
	output += recInOrder(ptr->left);
	output += recInOrder(ptr->right);
	output += ptr->value;
	return output;
}
std::string ParseTree::recPreOrder(ParseNode * ptr)
{
	std::string output = "";
	output += ptr->value;
	output += recInOrder(ptr->left);
	output += recInOrder(ptr->right);
	return output;

}
