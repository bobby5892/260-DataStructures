#ifndef ARRAYINT_H
#define ARRAYINT_H


class ArrayInt
{
    public:
        ArrayInt();
        virtual ~ArrayInt();
         // create an array of 10 integers
        ArrayInt(int arraySize);
        // get value at spot
        int getAt(int index);
        // return the size
        int getSize(){ return this->sizeOfData;}
        // resize the array if smaller - do nothing
        void setSize(int newSize);
         // Adds to end of array
        void append(int value);

        // adds value to that index spot - and shifts all spots lower
        // Exception for out_of_range
        void setAt(int index, int value);
        void insertAt(int index, int value);
        // return the value then shift values
        // exception if out_of_range
        int removeAt(int index);

        void displayData();

    protected:

    private:
        // Total number of items in array
        int sizeOfData;
        // Container for data
        int* data;

        // Index
        int index;

};

#endif // ARRAYINT_H
