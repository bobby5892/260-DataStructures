#include "ArrayInt.h"
#include <stdexcept>
#include <iostream>
#include <ostream>
#include <string>
//#define DEBUG
ArrayInt::ArrayInt()
{
    //ctor
    this->sizeOfData=10;
    this->data = new int[this->sizeOfData];
    this->index = 0;

}

ArrayInt::~ArrayInt()
{
    //dtor
    delete [] this->data;
}

ArrayInt::ArrayInt(int arraySize){
    if(arraySize < 1){
        arraySize = 10;
    }
    this->sizeOfData = arraySize;
    this->data = new int[this->sizeOfData];
    this->index=0;

}

int ArrayInt::getAt(int index){
    // get size at spot
    if((index < 0) || (index > this->sizeOfData-1)){
         throw std::out_of_range( index + " index is out of range of array");
    }
    return this->data[index];
}

void ArrayInt::setSize(int newSize){
    // resize the array if smaller - do nothing
    if(newSize > this->sizeOfData){
        // Pointer to old data
        int* temp = this->data;
        int tempSize = this->sizeOfData;

        // create the new array
        this->sizeOfData = newSize;
        this->data = new int[this->sizeOfData];

        // move the old data over
        for(int i=0;i<tempSize;i++){
            this->data[i] = temp[i];
        }
        // cleanup
        delete [] temp;
        #ifdef DEBUG
        this->displayData();
        #endif
    }
}

void ArrayInt::append(int value){

    // Adds to end of array
    if( this->index > (this->sizeOfData-1)){
         // if it needs to be bigger
        this->setSize(this->sizeOfData*2);
        std::cout << "doubling size of array";
    }

    this->data[this->index] = value;
    this->index++;

    #ifdef DEBUG
    std::cout << "appended " << value << std::endl;
    this->displayData();
    #endif // debug
}


void ArrayInt::setAt(int index, int value){
//

    if((index > this->sizeOfData) || (index < 0)){
        throw std::out_of_range( index + " index is out of range of array");

    }
    //Put the value in

    if(index > this->index){
        this->index = index+1;
    }
    this->data[index] = value;

    #ifdef DEBUG
        std::cout << "Setting " << index << " to " << value << std::endl;
        this->displayData();
    #endif // DEBUG

}

int ArrayInt::removeAt(int index){
// return the value then shift values
// exception if out_of_range
    // grab it - shift over the top
    std::cout << "attempting to remove at: " << index << std::endl;
    if((index > this->sizeOfData) || (index < 0)  || (this->index <= 1)   ){
        std::cout << "Throwing" << std::endl;
        throw std::out_of_range( "failed remove: index is out of range of array");
        std::cout << " AFTER THROW " << std::endl;
    }
    std::cout << "this never happens last";
    int temp = this->data[index];


    for(int i=index;  i<this->sizeOfData;   i++){
         this->data[i] = this->data[i+1];


    }
    this->index--;

    return temp;

}
void ArrayInt::insertAt(int index, int value){
    // Determine if array can hold it
    if((this->index+1) > this->sizeOfData){
        this->setSize(this->sizeOfData*2);
    }
    //from bottom shift
    for(int i=this->sizeOfData;i > index;i--){
        this->data[i] = this->data[i-1];
    }
    // put it in
    this->data[index] = value;
    // update index
    if(index > this->index){
        this->index = index;
    }
}
void ArrayInt::displayData(){
    // display data
    std::cout << "Data Debug" << std::endl;

    for(int i=0; i<this->index;i++){
        std::cout << i << " : " << this->data[i] << std::endl;
    }
}


