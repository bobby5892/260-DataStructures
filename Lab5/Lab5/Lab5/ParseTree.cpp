#include "stdafx.h"
#include "ParseTree.h"
#include <stack>
#include <cctype>
#include <iostream>
#include <string>
/* Robert Moore 5/4/2018 Parse Tree - Pushing nodes on stack and popping off for sorting*/

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
ParseNode* ParseTree::doParse(std::string exp)
{
	if (exp.length() == 0) {
		throw std::out_of_range("Empty String");
	}
	//stack::push
	//stack::empty
	//stack::top
	//stack::pop
	
	//create a stack of pointer to node(you can either use your own code for stack or use std::stack)
	std::stack<ParseNode*> nodes;
	
	//for reach character in the string
	for (int i = 0; i < exp.length(); i++) {
		//if the character is an operand(letter or number) create a node containing it and push the node on the stack
		if (exp[i] == '(') {
			ParseNode* newNode = new ParseNode;
			newNode->value = exp[i];
			newNode->left = nullptr;
			newNode->right = nullptr;
			nodes.push(newNode);
		}
		//if the character is an operator ( +, -, *, / ) create a node containing it.
		//pop the top item off the stack and attach as a right child,
		//pop the top item off the stack and attach as a left child,
		//push the operator node (root of this new subtree) on the stack
		else if ((exp[i] == '+') || (exp[i] == '-') || (exp[i] == '*') || (exp[i] == '/'))  {
			ParseNode* newNode = new ParseNode;
			newNode->value = exp[i];
			newNode->left = nullptr;
			newNode->right = nullptr;
			if (!nodes.empty()) {
				ParseNode* fromStackRight = nodes.top();
				nodes.pop();
				// Attaching it to the right
				newNode->right = fromStackRight;
			}
			if (!nodes.empty()) {
				ParseNode* fromStackLeft = nodes.top();
				nodes.pop();
				newNode->left = fromStackLeft;
				nodes.push(newNode);
			}
		}
		else {
			ParseNode* newNode = new ParseNode;
			newNode->value = exp[i];
			newNode->left = nullptr;
			newNode->right = nullptr;
			nodes.push(newNode);
		}
		//if it is anything else, ignore it
	}
	//when the expression is fully processed, there should be one item on the stack.Pop it and return it.
	if (!nodes.empty()) {
		ParseNode* temp = nodes.top();
		nodes.pop();
		return temp;
	}
	
	return nullptr;
}

// recursive helper methods
void ParseTree::recDestruct(ParseNode * ptr)
{
	if (ptr->left != nullptr ) { recDestruct(ptr->left); }
	if (ptr->right != nullptr) { recDestruct(ptr->right); }
	delete(ptr);
}
std::string ParseTree::recInOrder(ParseNode * ptr)
{
	std::string output = "";
	if (ptr->left != nullptr) { output += recInOrder(ptr->left); }
	output += ptr->value;
	if (ptr->right != nullptr) { output += recInOrder(ptr->right); }
	return output;
}
std::string ParseTree::recPostOrder(ParseNode * ptr)
{
	std::string output = "";
	if (ptr->left != nullptr)  { output += recInOrder(ptr->left); }
	if (ptr->right != nullptr) { output += recInOrder(ptr->right); }
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
