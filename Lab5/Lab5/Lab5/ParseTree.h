#ifndef PARSETREE_H
#define PARSETREE_H
#include <string>

struct ParseNode {
	char value;
	ParseNode * left;
	ParseNode * right;
};

class ParseTree
{
public:
	ParseTree(std::string exp = "");
	virtual ~ParseTree();
	std::string inOrder();
	std::string postOrder();
	std::string preOrder();
private:
	ParseNode * root;

	void doParse(std::string exp);
	ParseNode* recDoParse(std::string exp, ParseNode* ptr);
	void recDestruct(ParseNode * ptr);
	std::string recInOrder(ParseNode * ptr);
	std::string recPostOrder(ParseNode * ptr);
	std::string recPreOrder(ParseNode * ptr);
	bool isOperator(char value);
	bool isOperand(char value);
};

#endif // PARSETREE_H
