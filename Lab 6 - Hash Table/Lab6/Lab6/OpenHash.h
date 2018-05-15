#pragma once
template <typename T> class OpenHash
{
public:
	OpenHash(){
		this->theSize = DEFAULT_SIZE;
		this->data = new T[this->theSize];
		this->initSetEmpty();
	}
	void addValue(T value) {
		int location = this->data[hashValue(value)];
		// check if empty first
		if ((this->data[location] == DELETED) || (this->data[location] == EMPTY)){
			this->data[location] = value;
		}
		else {
			while (true) {
				location++;
				// Grow Array
				if (location > this->theSize) {
					this->resizeArray(this->theSize * 2);
				}
				if ((this->data[location] == DELETED) || (this->data[location] == EMPTY)) {
					this->data[location] = value;
					break;
				}
			}
		}

	}
	bool removeValue(T value) {
		
		// bool
		int location = this->hashValue(value);
		while (true) {
			if ((location == EMPTY) || (location == DELETED)) {
				break;
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
		int location = this->hashValue(value);
		while (true) {
			if ((location == EMPTY) || (location == DELETED)) {
				break;
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
		}
		return output.str();
	}
	~OpenHash() {

	}
private:
	// Returns an index location for the value
	int hashValue(T value, int size = this->theSize) {
		std::istringstream iss(value);

		int asciiValue = 0;
		std::string temp = iss.str();
		// get ascii value
		for (int i = 0; i < temp.length(); i++) {
			// Multiply by 10 ^ i
			asciiValue += pow(10, i)*(int)(temp[i]);
		}
		int hashedIndex = asciiValue % size;
		return hashedIndex;
	}
	void resizeArray(int newSize) {
		T* temp = this->data;
		this->data = new T[newSize];
		this->reHashAll(temp, this->data, newSize);

		this->theSize = newSize;
	}
	// ReHash all the values
	void reHashAll(T* data, T* newData, int newSize) {
		for (int i = 0; i < this->theSize; i++) {
			if ((data[i] != this->EMPTY) && (data[i] != this->DELETED)) {
				newData[hashValue(newData[i], newSize)] = data[i];
			}
		}
	}
	std::string ToString(T value) {
		// If its a string or char 
		std::istringstream iss(this->value);
		if (iss.str().length() == 0) {
			// Might be a number
			std::stringstream string;

			string << this->value;
			return string.str();
		}
		else {
			return iss.str();
		}
	}
	void initSetEmpty(){
		// Choose Defaults for differenttypes 
		// typeid is compiler sensitive - does not work for all compilers [ according to stackoverflow] 
		if (typeid(T) == typeid(int)) { this->EMPTY = -1; this->DELETED = -2; }
		else if (typeid(T) == typeid(char)) { this->EMPTY = ' '; this->DELETED = '\n'; }
		else if (typeid(T) == typeid(std::string)) { this->EMPTY = " "; this->DELETED = "  "; }
		else if (typeid(T) == typeid(float)) { this->EMPTY = -1.00000; this->DELETED = -2.00000; }
		else if (typeid(T) == typeid(double)) { this->EMPTY = -1.00; this->DELETED = -2.00; }
		else if (typeid(T) == typeid(long)) { this->EMPTY = -1.000000000; this->DELETED = -2.000000000; }
		else if (typeid(T) == typeid(short)) { this->EMPTY = -1.000; this->DELETED = -2.000; }
		else {
			throw std::bad_typeid("Invalid Data Type: Only int,char,string,float,double,long,short supported");
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

};

