#pragma once
#pragma once
#pragma once

#include <string>
#include <sstream>
#include <ostream>
#include <stack>
#include <queue>
#include <list>
#include <iterator>
class WGraph
{
public:

	struct Node {
		char value;
		Node* next;
		bool visited;
		
		struct Edge {
			Edge* next; // for list of edges
			Node* to;
			Node* from;
			int weight;
		}*edges;
	};
	struct Link {
		Node* value;
		Link* next;
	};


	WGraph() {
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
	void addWEdge(char value, char goesToValue, int weight=0) {
		// Find the Pointer to the Node that matches the value
		Node* from = findNode(value);
		Node* to = findNode(goesToValue);

		Node::Edge* toTempEdge = to->edges;

		// Lets Create The new ege
		Node::Edge* newEdge = new Node::Edge;

		

		newEdge->from = from;
		newEdge->to = to;
		newEdge->next = toTempEdge;
		newEdge->weight = weight;
		// Put it in
		from->edges = newEdge;
		// If its not a directed graph - add reciprocal links
		if (!directed) {
			Node::Edge* temp = from->edges;
			Node::Edge* newEdge = new Node::Edge;
			
			newEdge->from = to;
			newEdge->to = from;
			newEdge->weight = weight;
			newEdge->next = temp;

			to->edges = newEdge;
		}
	}
	/// Get back the address to last edge
	Node::Edge* getLastEdge(Node* node) {
		Node::Edge* edge = node->edges;
		if (edge != nullptr) {
			while (edge->next != nullptr) {

				edge = edge->next;
			}
		}
		return edge;
	}
	///Lookup Nodes in the LLinked List
	Node* findNode(char value) {
		Link* temp = this->list;
		while (temp != nullptr) {
			if (temp->value->value == value) {
				break;
			}
			temp = temp->next;
		}
		return temp->value;

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
		Link* temp = this->list;
		while (temp != nullptr) {
			ss << temp->value->value << " -> ";
			Node::Edge* innerTemp = temp->value->edges;
			while (innerTemp != nullptr) {
				ss << "From: " << innerTemp->from->value <<" To: " << innerTemp->to->value << "(Wt:" << innerTemp->weight << ") ";
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
				if (innertemp->to->visited == false) {
					/// push other End
					//ss << "" << innertemp->node->value;
					stack.push(innertemp->to);
					/// process other end
					innertemp->to->visited = true;
					ss << temp->value << "-";
					ss << recDepthFirst(innertemp->to);

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
	std::string minCostTree(char value) {
		std::stringstream ss;
		//start at some node
		Node* start = findStart(value);
		//add all edges from that node to PQ
		Node::Edge* innerTemp = start->edges;
		while (innerTemp != nullptr) {
			listEdge.push_front(innerTemp);
			innerTemp = innerTemp->next;
		}
		//mark it as visited
		start->visited = true;
		// Vars to use
		Node* tempNode;
		Node::Edge* tempEdge;
		//while PQ not empty
		while (!listEdge.empty()) {
			//get smallest edge
			tempEdge = clearLowest();
			
			//mark end node of that edge as visited
			tempEdge->to->visited = true;
			//output the edge
			ss << tempEdge->from->value << "-" << tempEdge->to->value << " ";
			
			//add all edges from end node to unvisited neigbors to
			Node::Edge* innerTemp = tempEdge->to->edges;
			while (innerTemp != nullptr && innerTemp->to->visited == false) {
				listEdge.push_front(innerTemp);
				innerTemp = innerTemp->next;
			}
		}
		return ss.str();
	}
	/*std::string minCostTree(char value) {
		std::stringstream ss;
		ss << "start (" << value << ")";
		ss << recMinCostTreeNode(findStart(value));
		return ss.str();
	}*/
	std::string recMinCostTreeNode(Node* temp) {
		// Since we are starting with a character - there could be multiple edges at this level So we start with a node
		std::stringstream ss;
		Node::Edge* innerTemp = temp->edges;
		while (innerTemp != nullptr) {
			ss <<"ByNode " << recMinCostTree(innerTemp);
			innerTemp = innerTemp->next;
		}
		return ss.str();
	}
	std::string recMinCostTree(Node::Edge* edge) {
	
		std::stringstream ss;
		/*As described in Moodle and the textbook, a min - cost spanning tree is created with a
		breadth first search that uses a priority queue of edges instead of a FIFO of nodes.
		When you add a new edge to the priority queue, check the queue for another edge

		with the same ending node and only leave the edge with the lowest cost.Since you
		are going to be searching the priority queue, you should implement your own based
		off of an array. (Note that the edge structure will also need to have beginning and
			ending nodes, rather than only ending as in the provided Graph class.)

		Remove the lowest cost edge in the priority queue, add the edge to your tree, mark
		the ending node as visited, and add any edges from it to unvisited nodes to the
		priority queue.*/		if (edge != nullptr) {
			ss << edge->to->value;
			// If the node is not visisted lets push it and then move toit
			if (!edge->to->visited) {
				edge->to->visited = true;
				// Push to Front of list

				listEdge.push_front(edge);
				ss << " To (" << edge->to->value << ") " <<   recMinCostTree(edge->next);
			}
			// At this point the list is full
			if (!listEdge.empty()) {
				//ss << "clear:" << clearLowest(edge->to->value) << recMinCostTree(edge->next);
			}
			else if (listEdge.empty()) {
				// These can end
				
			}
			else {
			//	ss << recMinCostTree(edge);
			}



			// If no push then lets pop/search/whatever

		}
		return ss.str();
	
	}
	Node::Edge* clearLowest() {
		std::stringstream ss;
		std::list <Node::Edge*> ::iterator it;
		Node::Edge* lowest = nullptr;
		// Search the edges in the queue for the lowest
		for (it = listEdge.begin(); it != listEdge.end(); ++it) {
			// If not nullptr
			if ((*it) != nullptr) {
				// Then see if the value matches
				//if ((*it)->to->value == value) {
					// if lowest is not nullptr
					if (lowest != nullptr) {
						if (lowest->weight > (*it)->weight) {
							lowest = (*it);
						}
					}
					else {
						lowest = (*it);
					}
				//}
			}
		}
		// If it found a lowest
		if (lowest != nullptr) {
			//Node::Edge* temp = lowest;
			// Remove it from queue
			listEdge.remove(lowest);
			//ss << "From: " << temp->from->value << " To: " << temp->to->value << " Wt: " << temp->weight;
		}
		
		return lowest;
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
				if (edgeTemp->to->visited == false) {
					if (nonVerbosePrint) {
						ss << edgeTemp->to->value << " ";
					}
					else {
						ss << temp->value << "-" << edgeTemp->to->value << " ";
					}
					edgeTemp->to->visited = true;
					queue.push(edgeTemp->to);
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
	std::string showlist(std::list <Node::Edge*> g)
	{
		std::stringstream ss;
		std::list <Node::Edge*> ::iterator it;
		for (it = g.begin(); it != g.end(); ++it)
			ss << '\t' << *it;
		ss << '\n';
		return ss.str();
	}
	void clearVisited() {
		Node* temp = this->list->value;
		while (temp != nullptr) {
			temp->visited = false;
			temp = temp->next;
		}
	}
	~WGraph() {

	}
private:
	// Graph
	Node * root;
	bool directed = false;
	std::stack<Node*> stack;
	std::queue<Node*> queue;
	std::list<Node::Edge*> listEdge;
	bool nonVerbosePrint = true;

	// Used a Link List
	Link* list;
};


