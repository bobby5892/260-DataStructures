#pragma once
template <typename T> class OpenHash
{
public:
	OpenHash(){
		this->theSize = DEFAULT_SIZE;
		this->data = new T[this->theSize];
		this->initSetEmpty();
	}
	OpenHash(int size) {
		this->theSize = size;
		this->data = new T[this->theSize];
		this->initSetEmpty();
	}
	void addValue(T value) {
		int location = hashValue(value,this->theSize);
		// check if empty first
		if ((this->data[location] == DELETED) || (this->data[location] == EMPTY)){
			this->data[location] = value;
		}
		else {
			while (true) {
				// Grow Array
				if (location >= this->theSize) {
					this->resizeArray(this->theSize * 2);
				}
				if ((this->data[location] == DELETED) || (this->data[location] == EMPTY)) {
					this->data[location] = value;
					break;
				}
				++location;
			}
		}

	}
	bool removeValue(T value) {
		
		// bool
		int location = this->hashValue(value,this->theSize);
		while (true) {
			if ((this->data[location] == EMPTY) || (this->data[location] == DELETED)) {
				return false;
			}
			else if (location >= this->theSize) {
				return false;
			}
			else {
				if (this->data[location] == value) {
					T temp = data[location];
					this->data[location] = DELETED;
					return true;
				}
			}
			location++;
		}
		return false;
		
	}
	T RemoveAt(int index) {
		T temp = this->data[index];
		this->data[index] = DELETED;
	}
	T Pop() {
		for (int i = theSize; i > 0; i--) {
			if ((this->data[i] != DELETED) && (this->data[i] != EMPTY)) {
				T temp = this->data[i];
				this->data[i] = DELETED;
				return temp;
			}
		}
		throw std::out_of_range("Exception: Cannot Remove on Empty Array");
		return EMPTY;
	}
	bool findValue(T value) {
		int location = this->hashValue(value,this->theSize);
		while (true) {
			if ((this->data[location] == EMPTY) || (this->data[location] == DELETED)) {
				break;
			}
			else if (location >= this->theSize) {
				return false;
			}
			else {
				if (this->data[location] == value) { 
					return true; 
				}
			}
			location++;
		}
		return false;
	}
	std::string displayTable() {
		std::stringstream output;
		for (int i = 0; i < this->theSize; i++) {
			if ((this->data[i] != EMPTY) && (this->data[i] != DELETED)) {
				output << this->data[i] << ",";
			}
			else if (this->data[i] == DELETED) {
				output << "deleted,";
			}
			
		}
	
		return output.str();
	}
	~OpenHash() {

	}
private:
	// Returns an index location for the value
	int hashValue(T value, int size) {
		

		int asciiValue = 0;
		std::string temp = this->ToString(value);
		// get ascii value
		for (int i = 0; i < temp.length(); i++) {
			// Multiply by 10 ^ i
			asciiValue += pow(10, i)*(int)(temp[i]);
		}
		int hashedIndex = asciiValue % size;
		return hashedIndex;
	}
	void resizeArray(int newSize) {
		int oldSize = this->theSize;
		T* temp = this->data;
		this->data = new T[newSize];
		this->theSize = newSize;
		this->initSetEmpty();
		this->reHashAll(temp, this->data, newSize,  oldSize);

		
	}
	// ReHash all the values
	void reHashAll(T* data, T* newData, int newSize, int oldSize) {
		for (int i = 0; i < oldSize; i++) {
			if ((data[i] != this->EMPTY) && (data[i] != this->DELETED)) {
				newData[hashValue(data[i], newSize)] = data[i];
			}
		}
	}
	std::string ToString(T value) {
		// If its a string or char 
		std::istringstream iss(value);
		if (iss.str().length() == 0) {
			// Might be a number
			std::stringstream string;

			string << value;
			return string.str();
		}
		else {
			return iss.str();
		}
	}
	void initSetEmpty(){
		// Choose Defaults for differenttypes 
		
		if (type_name() == "int") {  this->EMPTY = (T) -1; 	this->DELETED = (T) -2;	}
		else if (this->type_name() == "char") {  this->EMPTY = (T) ' ';  this->DELETED = (T) '|'; }
		else if (this->type_name() == "string") {  this->EMPTY = (T) "x";  this->DELETED = (T) "xx"; }
		else if (type_name() == "float") {  this->EMPTY = (T) -1.00000;  this->DELETED = (T)-2.00000; }
		else if (type_name() == "double") {  this->EMPTY = (T)-1.00;  this->DELETED = (T) -2.00; }
		else if (type_name() == "long") {  this->EMPTY = (T) -1.000000000;  this->DELETED = (T) -2.000000000; }
		else if (type_name() == "short") {  this->EMPTY = (T) -1.000;  this->DELETED = (T)-2.000; }
		else {
			// for debug point
			//typeid(T);
			throw std::invalid_argument("Invalid data type, only allows int, char, string,float,double,long, short");
		}

		for (int i = 0; i < theSize; i++) {
			this->data[i] = this->EMPTY;
		}
	}
	// The character for an empty slot
	T EMPTY;
	T DELETED;
	T * data;
	// Current Size
	int theSize;
	// Default Size
	int DEFAULT_SIZE = 10;

	std::string type_name()
	{
		// Hm so typeid is relative to compiler
		if (typeid(int).name() == typeid(T).name()  ) { return "int";  }
		else if (typeid( std::string).name() == typeid(T).name()) { return "string";  }
		else if (typeid( double).name() == typeid(T).name()) { return "double"; }
		else if (typeid( float).name() == typeid(T).name()) { return "float"; }
		else if (typeid( long).name() == typeid(T).name()) { return "long"; }
		else if (typeid( short).name() == typeid(T).name()) { return "short"; }
		else if (typeid( char).name() == typeid(T).name()) { return "char"; }


		return "BADTYPE";
	}
};

