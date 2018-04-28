#pragma once
#include <iostream>
#include <string>

/*
  LINK    
[=====]
|value|
[=====]
|*prev|
[=====]
|*next|
[=====]
*/

	struct Link {
		char value;
		Link* next;
		Link* prev;
	};
	class TextClass
	{
	public:
		TextClass();
		~TextClass();

		/* Insert	a	link	containing	val	at	the	head	of	the	list*/
		void insertHead(char val);
		
		
		// Grab the head
		Link* getHead() { return this->head;  }
		/* Insert	a	link	containing	val	at	the	end	of	the	list*/
		void insertTail(char val);

		// Grab Tail
		Link* getTail() { return this->tail; }

		/* Delete	first	link	and	return	its	value.Throw	exception	on
		an	empty	list.	(If	it	is	pointed	to	by	iter, set	to	nullptr.)*/
		char deleteHead();

		/*Delete	last	link	and	return	its	value.Throw	exception	on
		an	empty	list.		(If	it	is	pointed	to	by	iter, set	to	nullptr.)*/
		char deleteTail();

		/* Return	true	if	list	is	empty, false	otherwise. */
		bool isEmpty();

		/*  Return	true	if	a	link	exists	containing	key.If	you	find	a
		link	containing	the	key, set	a	class	variable	iter	pointing
		to	it	for	later	use.If	the	key	is	not found	in	the	list,
		return	false.*/
		bool  findKey (char key);

		/* Using	the iter	variable	set	in	findKey, create	a	link
		containing	the	value	and	insert	in	the	list	just	before	the
		link	pointed	to	by	iter. Return	true	if	insert	succeeds.
		If	iter has	not been	set	it	should	have	a	value	of	nullptr
		and	you	should	return	false.*/
		bool insertKey(char	value);
		// For Testing - Get a key that was foud if there is one
		Link* getFoundKey(){ 
			if (this->iter != nullptr) {
				return this->iter;
			}
		}
		/* If	the	variable(iter) set	by	findKey	is	not nullptr, delete
		the	link	it	points	to	and	set	iter	to	nullptr.Return	true
		on	success, false	if	iter	was	nullptr.*/
		bool deleteIter();

		/* Delete	the	first	link	you	find	that	contains	key.Return
		true on	success, false	on	failure.	(If	that	link	happened	to
			be	pointed	to	by	iter, set	iter	to	nullptr).*/
		bool deleteKey(char	key);

		/*Return	a	string	containing	the	values	in	the	list	starting
		at	the	head	and	ending	at	the	tail.*/
		std::string displayList();

		
		// Returns a bare string of the list - no modifiers
		std::string getList();
	

		/* text  Class	&	list2 Append	the	elements	of	list2	to	the	end	of	this	list*/
		void appendList (TextClass* list);

		//Clear iter
		void clearIter() {
			this->iter = nullptr;
		}

	private:
		// Head of Linked List
		Link* head;
		// Tail of Linked List
		Link* tail;

		/* iterator*/
		Link* iter;

		void deleteLink(Link* link);

		bool const SHOW_ITER_IN_DISPLAY = false;


	};


