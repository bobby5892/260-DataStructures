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

int ArrayInt::removeAt(int index){
    if( (index > this->sizeOfData) || (index < 0)  || (this->index <= 1)   ){
        std::cout << " About to throw" << std::endl;
        throw std::out_of_range("Out of Range");
    }
    int temp = this->data[index];
    for(int i=index;  i < this->sizeOfData;   i++){
         this->data[i] = this->data[i+1];
    }
    this->index--;
    return temp;
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

          throw std::out_of_range("Out of Range");
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

}


void ArrayInt::setAt(int index, int value){
//

    if((index > this->sizeOfData) || (index < 0)){

        throw std::out_of_range( "index is out of range of array");

    }
    else{
       std::cout << "Did not throw index:" << index << " vs" << this->sizeOfData << std::endl;
    }
    //Put the value in

    if(index > this->index){
        this->index = index+1;
    }
    this->data[index] = value;



}

void ArrayInt::insertAt(int index, int value){
    if((index >= this->sizeOfData) || (index < 0)){
        throw std::out_of_range( "index is out of range of array");
    }
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


    for(int i=0; i<this->index;i++){
        std::cout << i << " : " << this->data[i] << std::endl;
    }
}


