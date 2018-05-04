#include "stdafx.h"
#include <string>
#include <exception>
#include "ParseTree.h"

/// Common init
void ParseTree::init() {
	// Setup our stack
	this->stackHead = nullptr;
	// initialize strings
	this->baseString = this->postString = "";
}
/// Default Constructor
ParseTree::ParseTree()
{
	// Common Init
	this->init();
}
///Over Loaded Constructor
ParseTree::ParseTree(std::string equation) {
	// Common Init
	this->init();
	// Save base - for later - might not be needed but cool.
	this->baseString = equation;
	// Make sure there is something in the string
	if (equation.length() == 0) {
		throw std::out_of_range("String is empty");
	}
	// Lets Sort it
	this->recParseAdd(equation);


}

// Parse Method
void ParseTree::recParseAdd(std::string equation, int position) {
	// If we are at the end - POP the rest off
	if (position+1 == equation.length()) {
		while (this->stackHead != nullptr) {
			this->postString += this->stackPop();
		}
	}
	// If your not at the beginning
	if (position == 0) {
		this->postString += equation[position];
	}
	else{
		// if its an operand just add it
		if (getPrecedence(equation[position]) == -1) {
			this->postString += equation[position];
		}
		else {
			// Lets see if we have any operands on the stack
			if (this->stackHead == nullptr) {
				// Add it to the stack
				this->stackAdd(equation[position]);
			}
			else {
				// Now we need to check precedence 
				if (getPrecedence(equation[position]) > getPrecedence(this->stackPeek())) {
					// The operator we are comparing to whats on the stack is higher - we need to pop
					while (
							(getPrecedence(equation[position]) > getPrecedence(this->stackPeek()) )
							&& (this->stackHead != nullptr)
						) {
						// pop
						this->postString += this->stackPop();

					}
				}
			}
		}
	}
	
	//PEMDOS
	
	

	// Lets do it again
	if (position != equation.length()-1) {
		recParseAdd(equation, position++);
	}
}
//
// Stack Add
void ParseTree::stackAdd(char character) {
	stackLink* newLink = new stackLink;
	newLink->value = character;
	newLink->next = this->stackHead;
	this->stackHead = newLink;
}
// Stack Remove
char ParseTree::stackPop() {
	stackLink* temp = this->stackHead;
	char tempValue = temp->value;
	this->stackHead = this->stackHead->next;
	delete temp;
	return tempValue;

}
// Stack Peek
char ParseTree::stackPeek() {
	return this->stackHead->value;
}
int ParseTree::getPrecedence(char character) {
	switch (character) {
		case ')':
			return 1;
			break;
		case '(':
			return 2;
			break;
		case '^': // exponent
			return 3;
			break;
		case '*':
			return 4;
			break;
		case '/':
			return 5;
			break;
		case '+':
			return 6;
			break;
		case '-':
			return 7;
			break;
		default:
			return -1;
			break;
	}
}
ParseTree::~ParseTree()
{
}
