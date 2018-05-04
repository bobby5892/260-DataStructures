#pragma once
class ParseTree
{
// should be private after unit testing
private:
	void init();
	// String Prior to Edit
	std::string baseString;
	// Post Polish String
	std::string postString;
public:
	// STACK RELATED
	struct stackLink {
		char value;
		stackLink* next;
	};
	// Head for Stack
	stackLink* stackHead;
	// Stack Add
	void stackAdd(char character);
	// Stack Remove
	char stackPop();
	// Stack Peak
	char stackPeek();
	// Stack Empty
	bool stackEmpty(){ 
		if (!this->stackHead) { return true; }
		return false;
	}
	// Parsing Related
	int getPrecedence(char character);
	// Private Parse Method
	void recParseAdd(std::string equation,int position=0);

	// Get PolishString
	std::string getPostString() { return this->getPostString(); }

	
//public:
	// Default Constructor
	ParseTree();
	// Overloaded constructor with string of equation passed to it
	ParseTree(std::string equation);
	
	~ParseTree();
};

