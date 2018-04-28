#pragma once
#include <string>
#include <sstream>
template <typename T> class Node {
/// Class Variables
private:
	T value;
	Node<T>* left;
	Node<T>* right;
public:
	/// Default Constructor
	Node() {
		this->right = this->left = nullptr;
	}
	/// Overloaded Constructor
	Node(Node<T>* left, Node<T>* right, T value) {
		this->left = left;
		this->right = right;
		this->value = value;
	}
	/// Getter Methods
	Node<T>* getLeft() { return this->left; }
	Node<T>* getRight() { return this->right; }
	T  getValue() { return this->value; }
	/// Setter Methods
	void setLeft(Node<T>* ptr) { this->left = ptr; }
	void setRight(Node<T>* ptr) { this->right = ptr; }
	void setValue(T value) { this->value = value; }
};
template <typename T> class Tree
{

public:
	Tree() {
		// Plant a root
		this->root = nullptr;
	}
	bool isPresent(T n) {
		Node<T>*ptr = recFindHome( n, this->root);
		if (ptr != nullptr) { return true; }
		return false;
	}
	void insertItem(T n) {
		if(this->root == nullptr)
			root = new Node<T>(nullptr, nullptr, n);
		else {

			Node<T>* ptr = recInsert(n, this->root);
			ptr = new Node<T>(nullptr, nullptr, n);
		}
		
		
		
	}
	// For Testing
	Node<T>* recFindHome(T n) {
		// For testing - it adds in the home
		return recFindHome(n, this->root);
	}
	Node<T>* recInsert(T n, Node<T>* ptr) {
		// If the node we are looking at is empty - the number obviously goes there
		if (ptr == nullptr) {
			//ptr = new Node(nullptr, nullptr, T n);
			return ptr;
		}
		// We are in a node that has a value
		else {
			if (ptr->getValue() >  n) {
				Node<T>*possible = recInsert( n, ptr->getLeft());
				if (ptr->getLeft() == nullptr) {
					Node<T>* newPtr = new Node<T>(nullptr, nullptr, n);
					ptr->setLeft(newPtr);
				}
			}
			else {
				Node<T>*possible = recInsert( n, ptr->getRight());
				if (ptr->getRight() == nullptr) {
					Node<T>* newPtr = new Node<T>(nullptr, nullptr, n);
					ptr->setRight(newPtr);

				}
			}
		}
	}
	Node<T>* recFindHome(T n, Node<T>* ptr) {
		// If the node we are looking at is empty - the number obviously goes there
		if (ptr == nullptr) {
			//ptr = new Node(nullptr, nullptr, T n);
			return ptr;
		}
		// We are in a node that has a value
		else {
			if (ptr->getValue() >  n) {
				recFindHome(n, ptr->getLeft());
			}
			else if (ptr->getValue() == n) {
				return ptr;
			}
			else {
				recFindHome(n, ptr->getRight());
			}
		}
	}


	T removeItem(T n) {
		// ToDo
		
		return  n;
	}
	std::string preOrder() {
		std::string output = recPrefixTraversal(this->root);
		return output;
	}
	std::string inOrder() {
		std::string output = recInfixTraversal(this->root);
		return output;
	}
	std::string postOrder() {
		std::string output = recPostfixTraversal(this->root);
		return output;
	}
	std::string recPostfixTraversal(Node<T>* tempRoot) {
		std::stringstream output;
		if (tempRoot == nullptr) {
			return "NULL";
		}
		if (tempRoot->getLeft() != nullptr) {
			output << recPostfixTraversal(tempRoot->getLeft()) << " ";
		}
		if (tempRoot->getRight() != nullptr) {
			output << recPostfixTraversal(tempRoot->getRight()) << " ";
		}
		
		if( (std::to_string(tempRoot->getValue())) != ""){
			output << tempRoot->getValue() << " ";
			//return output.str();
		}
		return output.str();

		//(c) Postorder (Left, Right, Root) : 4 5 2 3 1
	}
	std::string recPrefixTraversal(Node<T>* tempRoot) {
		std::stringstream output;
		if (tempRoot == nullptr) {
			return "NULL";
		}
		if ((std::to_string(tempRoot->getValue())) != "") {
			output << tempRoot->getValue() << " ";
			//return output.str();
		}
		if (tempRoot->getLeft() != nullptr) {
			output << recPrefixTraversal(tempRoot->getLeft()) ;
		}
		if (tempRoot->getRight() != nullptr) {
			output << recPrefixTraversal(tempRoot->getRight());
		}

		//(b)Preorder(Root, Left, Right) : 1 2 4 5 3
		return output.str();
	}
	std::string recInfixTraversal(Node<T>* tempRoot) {
		//(a) Inorder (Left, Root, Right) : 4 2 5 1 3
		
		std::stringstream output;
		if (tempRoot == nullptr) {
			return "NULL";
		}
		if (tempRoot->getLeft() != nullptr) {
			output << recPrefixTraversal(tempRoot->getLeft());
		}

		if ((std::to_string(tempRoot->getValue())) != "") {
			output << tempRoot->getValue() << " ";
			//return output.str();
		}
		if (tempRoot->getRight() != nullptr) {
			output << recPrefixTraversal(tempRoot->getRight());
		}

		
		return output.str();
	}
	~Tree() {

	}
private:
	Node<T>* root;
	
};

