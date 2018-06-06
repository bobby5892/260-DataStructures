#pragma once
#pragma once

#include <string>
#include <sstream>
#include <ostream>
#include <stack>
#include <queue>
class DGraph
{
public:

	struct Node {
		char value;
		Node* next;
		bool visited;
		
		struct Edge {
			Edge* next;
			Node* node;
		}*edges;
	};
	struct Link {
		Node* value;
		Link* next;
	};


	DGraph() {
		this->root = nullptr;
		this->list = nullptr;
	}
	std::string connectTable() {
		std::stringstream output;
		Link* temp = this->list;
		while (temp != nullptr) {
			output << temp->value->value << ":";
			clearVisited();
			output << recBreadthFirst(temp->value) << " ";
			temp = temp->next;
			output << std::endl;
		}
		return output.str();
	}
	void addNode(char value) {
		Node* newNode = new Node;
		newNode->value = value;
		newNode->edges = nullptr;
		newNode->visited = false;
		newNode->next = this->root;

		if (this->root == nullptr) {
			this->root = newNode;
		}
		else {
			Node* temp = this->root;
			while (temp != nullptr) {
				temp = temp->next;
			}
			this->root = newNode;
		}

		// For Linked List Object
		Link* temp = this->list;
		this->list = new Link;
		this->list->value = this->root;
		this->list->next = temp;
	}
	void addEdge(char value, char goesToValue) {
		// Find the Pointer to the Node that matches the value
		Node* temp = this->root;
		while (temp != nullptr) {
			if (temp->value == value) {
				break;
			}
			temp = temp->next;
		}
		// So now its in temp->edges
		Node* innerTemp = this->root;
		// Lets find where it goes
		while (innerTemp != nullptr) {
			if (innerTemp->value == goesToValue) {
				break;
			}
			innerTemp = innerTemp->next;
		}
		// So now Value needs an edge that links to goesToValue
		// Lets add the edge
		Node::Edge* newEdge = new Node::Edge;
		newEdge->next = temp->edges;
		newEdge->node = innerTemp;

		Node::Edge* tempEdge = temp->edges;
		newEdge->next = tempEdge;
		temp->edges = newEdge;

		// If its not a directed graph - add reciprocal links
		if (!directed) {
			Node::Edge* newEdge = new Node::Edge;
			newEdge->next = innerTemp->edges;
			newEdge->node = temp;

			Node::Edge* tempEdge = innerTemp->edges;
			newEdge->next = tempEdge;
			innerTemp->edges = newEdge;
		}
	}
	std::string listNodes() {
		std::stringstream ss;
		Node* temp = this->root;
		while (temp != nullptr) {
			ss << temp->value << " ";
			temp = temp->next;
		}
		return ss.str();
	}
	std::string displayEdges() {
		std::stringstream ss;
		Node* temp = this->root;
		while (temp != nullptr) {
			ss << temp->value << " -> ";
			Node::Edge* innerTemp = temp->edges;
			while (innerTemp != nullptr) {
				ss << innerTemp->node->value << " ";
				innerTemp = innerTemp->next;
			}
			ss << std::endl;


			temp = temp->next;
		}
		return ss.str();

	}
	Node* findStart(char value) {

		// Find the Starting spot
		Node* temp = this->root;
		while (temp != nullptr) {
			if (temp->value == value) {
				break;
			}
			temp = temp->next;

		}
		// If we didn't find it - we're done
		if (temp == nullptr) { return nullptr; }
		return temp;

	}
	std::string depthFirst(char value) {
		std::stringstream ss;
		Node* temp = findStart(value);

		/*
		Q-J J-M Q-K K-C C-X X-Z Z-A A-T
		foreach edge starting at current
		if edge->otherEnd is non-visited
		push current
		push otherEnd
		process otherEnd (depending on algorithm)
		mark otherEnd as visited
		break

		ss << temp->value << " ";
		temp->visited = true;
		*/
		ss << recDepthFirst(temp);

		// 
		this->clearVisited();
		// Stack
		return ss.str();
	}
	std::string recDepthFirst(Node* temp) {
		std::stringstream ss;

		//  if edge->otherEnd is non - visited
		if (temp != nullptr) {
			/// push current
			ss << temp->value << " ";
			temp->visited = true;
			stack.push(temp);

			Node::Edge* innertemp = temp->edges;
			while (innertemp != nullptr) {
				if (innertemp->node->visited == false) {
					/// push other End
					//ss << "" << innertemp->node->value;
					stack.push(innertemp->node);
					/// process other end
					innertemp->node->visited = true;
					ss << temp->value << "-";
					ss << recDepthFirst(innertemp->node);

					/// mark other end as visited
					//innertemp->node->visited = true;
				}
				innertemp = innertemp->next;
			}
		}
		else {
			if (!stack.empty()) {
				Node* temp = stack.top();
				stack.pop();
				ss << recDepthFirst(temp);
			}
		}
		return ss.str();
		//	push current
		//	push otherEnd
		//	process otherEnd(depending on algorithm)
		//	mark otherEnd as visited*/
	}
	std::string breadthFirst(char value) {

		std::stringstream ss;

		ss << recBreadthFirst(findStart(value));
		return ss.str();
	}
	std::string recBreadthFirst(Node* temp) {
		/*
		while FIFO not empty
		current = FIFO head
		remove FIFO head

		foreach edge starting at current
		if edge->otherEnd is non-visited
		add otherEnd to FIFO
		process otherEnd (depending on algorithm)
		mark otherEnd as visited
		*/
		std::stringstream ss;
		if (temp != nullptr) {
			temp->visited = true;
			Node::Edge* edgeTemp = temp->edges;
			while (edgeTemp != nullptr) {
				if (edgeTemp->node->visited == false) {
					if (nonVerbosePrint) {
						ss << edgeTemp->node->value << " ";
					}
					else {
						ss << temp->value << "-" << edgeTemp->node->value << " ";
					}
					edgeTemp->node->visited = true;
					queue.push(edgeTemp->node);
				}
				edgeTemp = edgeTemp->next;
			}
		}
		if (!queue.empty()) {
			Node*atemp = queue.front();
			queue.pop();
			ss << recBreadthFirst(atemp);
		}
		return ss.str();
	}
	void clearVisited() {
		Node* temp = this->list->value;
		while (temp != nullptr) {
			temp->visited = false;
			temp = temp->next;
		}
	}
	~DGraph() {

	}
private:
	// Graph
	Node * root;
	bool directed = true;
	std::stack<Node*> stack;
	std::queue<Node*> queue;
	bool nonVerbosePrint = true;

	// Used a Link List
	Link* list;
};


