#pragma once
#include "stdafx.h"

#include <stdexcept>
#include <ostream>
#include <sstream>

//#define DEBUG


template<typename  T>  class LinkList{
public:
	struct Link {
		T value;
		Link* next;
		Link* prev;
	};
private:
	Link<T>* head;
	// Tail of Linked List
	Link<T>* tail;

	/* iterator*/
	Link<T>* iter;

	bool const SHOW_ITER_IN_DISPLAY = false;
public:


	LinkList()
	{
		this->head = nullptr;
		this->tail = nullptr;
	}

	/// Insert	a	link	containing	val	at	the	head	of	the	list
	void insertHead(T val) {
		// Create a Link
		Link<T>* newLink = new Link;
		newLink->value = val;

		// Is Head Null
		if (this->head == nullptr) {
			newLink->next = nullptr;
			newLink->prev = nullptr;

			this->head = newLink;
			this->tail = newLink;
		}
		else { // Not an empty list
				// grab current head previous always nullptr
			Link<T>*temp = this->head;

			// now lets set the new link to head
			this->head = newLink;

			// this new heads previous is the old head
			this->head->prev = nullptr;

			// this heads next = null ptr
			this->head->next = temp;

			this->head->next->prev = this->head;


		}
		#ifdef DEBUG
		this->displayList();
	#endif
	}

	/// Insert	a	link	containing	val	at	the	end	of	the	list
	void insertTail(T val) {
		// Create a Link
		Link<T>* newLink = new Link;
		newLink->value = val;
		// Is Tail Null
		if (tail == nullptr) {
			newLink->next = nullptr;
			newLink->prev = nullptr;
			this->head = newLink;
			this->tail = newLink;
		}
		else {
			Link<T>*temp = this->tail;
			// now lets set the new link to head
			this->tail = newLink;
			// this new tail previous is the old head
			this->tail->next = nullptr;
			// this heads next = null ptr
			this->tail->prev = temp;
			this->tail->prev->next = this->tail;
		}
		#ifdef DEBUG
		this->displayList();
		#endif
	}

	/* Delete	first	link	and	return	its	value.Throw	exception	on
	an	empty	list.	(If	it	is	pointed	to	by	iter, set	to	nullptr.)*/
	T deleteHead() {
		if (this->head == nullptr) {
			throw std::underflow_error("Empty List");
		}

		Link<T>* temp = this->head;
		T value = temp->value;

		// Change locations
		this->head = temp->next;

		if (this->head == nullptr) {
			// We are empty
			this->tail = nullptr;
		}
		else {
			this->head->prev = temp->next->prev;
		}

		delete temp;
		#ifdef DEBUG
		this->displayList();
		#endif
		return value;
	}

	/*Delete	last	link	and	return	its	value.Throw	exception	on
	an	empty	list.		(If	it	is	pointed	to	by	iter, set	to	nullptr.)*/
	T deleteTail() {
		if (this->tail == nullptr) {
			throw std::underflow_error("Empty List");
		}
		Link<T>* temp = this->tail;
		T value = temp->value;
		// Change locations
		this->tail = temp->prev;
		if (this->tail == nullptr) {
			// We are empty
			this->head = nullptr;
		}
		else {
			this->tail->next = temp->next;
		}
		delete temp;
		#ifdef DEBUG
		this->displayList();
		#endif
		return value;

	}
	/*  Return	true if	a	link	exists	containing	key.If	you	find	a
	link	containing	the	key, set	a	class	variable	iter	pointing
	to	it	for	later	use. If	the	key	is	not found	in	the	list,
	return	false.*/
	bool findKey(T key) {
		bool found = false;
		Link<T>* temp = this->head;
		if (this->iter != nullptr) {
			temp = this->iter->next;
		}

		// Look from current iter position
		while (temp != nullptr) {
			if (temp->value == key) {
				this->iter = temp;
				found = true;
				return found;
			}
			temp = temp->next;
		}

		// Look from beginning
		if (!found) {
			temp = this->head;
			while (temp != nullptr) {
				if (temp->value == key) {
					this->iter = temp;
					found = true;
					return found;
				}
				temp = temp->next;
			}
			this->iter = nullptr;
		}

		return found;
	}

	/* Return	true	if	list	is	empty, false	otherwise.
	boolean	 findKey char	key Return	true	if	a	link	exists	containing	key.If	you	find	a
	link	containing	the	key, set	a	class	variable	iter	pointing
	to	it	for	later	use.If	the	key	is	not found	in	the	list,
	return	false.*/
	bool isEmpty() {
		return (this->head == nullptr);
	}


	/* Using	the iter	variable	set	in	findKey, create	a	link
	containing	the	value	and	insert	in	the	list	just	before	the
	link	pointed	to	by	iter. Return	true	if	insert	succeeds.
	If	iter has	not been	set	it	should	have	a	value	of	nullptr
	and	you	should	return	false.*/
	bool insertKey(T	value) {
		if (this->iter != nullptr) {
			// left insert
			Link<T>*newLink = new Link;
			newLink->value = value;
			newLink->next = iter; // 4
			newLink->prev = iter->prev; // 1

			Link<T>* temp = this->iter;
			temp->prev->next = newLink; // 2
			temp->prev = newLink; // 3 
		}


		return false;
	}

	/* If	the	variable(iter) set	by	findKey	is	not nullptr, delete
	the	link	it	points	to	and	set	iter	to	nullptr.Return	true
	on	success, false	if	iter	was	nullptr.*/
	bool deleteIter() {
		if (this->iter != nullptr) {
			this->deleteLink(this->iter);
			this->iter = nullptr;
			return true;
		}
		return false;
	}

	/* Delete	the	first	link	you	find	that	contains	key.Return
	true on	success, false	on	failure.	(If	that	link	happened	to
	be	pointed	to	by	iter, set	iter	to	nullptr).*/
	bool deleteKey(T	key) {
		if (this->head != nullptr) {
			Link<T> *temp = this->head;
			while (temp != nullptr) {

				if (temp->value == key) {
					if (temp == this->iter) {
						this->iter = nullptr;
					}
					this->deleteLink(temp);

					return true;
				}
				temp = temp->next;
			}

		}
		return false;
	}

	void deleteLink(Link<T>* link) {
		link->prev->next = link->next;
		link->next->prev = link->prev;
		delete link;
	}
	

	~LinkList()
	{
	}

};