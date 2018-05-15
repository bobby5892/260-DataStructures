
template <typename T> class Merge
{
public:
	Merge() {
		this->data = nullptr;
	}
	Merge(T* data, bool smallestToLargest) {
		int i = 0;
		while (true) {
			// Check if at end of data
			if ((this->data[i] == -1) || (this->data[i] == "-1")) {
				break;
			}
			this->data[i] = data[i];
			this->size = i;
			i++;

		}
	}

	T* recSort(T* data, int size) {
		if (int size > 0) {

		}
		else {
			return nullptr;
		}
	}
	Merge & operator=() {

	};
	~Merge() {

	}

private:
	T * data;
	int size;

};

