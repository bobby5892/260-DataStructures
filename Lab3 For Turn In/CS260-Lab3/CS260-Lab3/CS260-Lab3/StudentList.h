#pragma once
class Student {
	private:
		std::string name;
		int age;
	public:
		Student() { name = ""; age = 0; }
		Student(std::string n, int a) { name = n; age = a; }
		void setName(std::string n) { name = n; }
		std::string getName() { return name; }
		void setAge(int a) { age = a; }
		int getAge() { return age; }
};

class StudentList
{
	private:
		struct Link {
			Student* value;
			Link* next;
		};
		//ArrayClass <int> theArray2;
		Link* head;
		Link* tail;
	public:
		// Insert a link pointing to s at the head of the list
		void insertHead (Student*s);
		//Insert a link pointing to s at the end of the list
		void insertTail(Student*s);
		//Delete first link and return its value.Throw anexception if the list is empty.
		Student* deleteHead();

		// None Return true if list is empty Return true if a link exists containing a Student with
		bool isEmpty();
		
		
		//String name the name.If the key is not found in the list, return false 
		bool findKey(std::string name);

		// String Name Delete the first link you find that contains a Student 
		//with the name.Return true if success, false if failure.
		bool deleteKey(std::string name);
		
		// show the list
		void displayList();

	StudentList();
	~StudentList();
private:
	//Link *head;
};

