#include "Dequeue.h"

#include <string>
#include <sstream>
#include <iostream>
#include <ostream>
#include <iomanip>

//#define DEBUG
Dequeue::Dequeue()
{
    // Create initial data
    this->init(100);
    this->tailIndex = 0;
    this->headIndex = -1;
}
Dequeue::Dequeue(int specialSize){
    // Create Initial Data
    if(specialSize > 1){
        this->init(specialSize);
    }
    else{
        this->init(100);
    }
    this->tailIndex = 0;
    this->headIndex =-1;
}
void Dequeue::init(int howBig){
    // Used to build the queue
    this->dataSize = howBig;
    this->data = new int[this->dataSize];

}
int Dequeue::Count(){
    return (this->tailIndex%this->dataSize) - (this->headIndex%this->dataSize);
}

void Dequeue::insertRight(int entry){
    if(this->headIndex % this->dataSize > this->dataSize){
         this->resizeArray(this->dataSize*2);
    }
    this->data[this->headIndex-- % this->dataSize] = entry;
#ifdef DEBUG
   std::cout << this->displayQueue();
#endif // DEBUG // Show the part that has stuff in it

}
void Dequeue::insertLeft(int entry){
    // check for room
    if(this->tailIndex+1 > this->dataSize ){
         this->resizeArray(this->dataSize*2);
    }

    // Save data
    //this->data[ this->tailIndex++] = entry;


    this->data[ this->tailIndex++ % this->dataSize ] = entry;
#ifdef DEBUG
   std::cout << this->displayQueue();
#endif // DEBUG // Show the part that has stuff in it
}

int Dequeue::removeLeft(){
    if(this->isEmpty()){
        throw std::range_error("Empty Array");
    }
#ifdef DEBUG
   std::cout << this->displayQueue();
#endif // DEBUG // Show the part that has stuff in it
    return this->data[--this->tailIndex % this->dataSize];
}
int Dequeue::removeRight(){
    if(this->isEmpty()){
        throw std::range_error("Empty Array");
    }
#ifdef DEBUG
   std::cout << this->displayQueue();
#endif // DEBUG // Show the part that has stuff in it

    return this->data[++this->headIndex % this->dataSize];
}


void Dequeue::resizeArray(int newSize){
    int* oldData = this->data;
    int oldSize = this->dataSize;

    // Create new data
    this->init(newSize);
    this->dataSize = newSize;

    // move data over
    for(int i=0; i < oldSize;i++ ){
        this->data[i] = oldData[i];
    }
    // cleanup
    delete [] oldData;

}

void Dequeue::displayArray(){
        std:: cout << " head: " << this->headIndex << std::endl;
        for(int i=0; i<this->dataSize;i++){
            std::cout << "value:" <<  i << ":" << this->data[i] <<  std::endl;
        }
        std:: cout << " tail: " << this->tailIndex << std::endl;

    // Show the entire array
}
std::string Dequeue::displayQueue(){

    if(!this->isEmpty()){
            std::stringstream output;
            // Start at the first head index and while the iterator is less than the tail - look at it
            for(int i=((this->headIndex+1)%this->dataSize); i < (this->tailIndex%this->dataSize) ; i++){

                output << std::setw(5)<<  "|[";
                if (i < 10){
                   output << "0";
                }
                output << i << "] " << this->data[i] ;
            }
            output  << std::endl<< std::endl;
            std::string outputStr = output.str();

            //Remove Trailing coma
           return outputStr.substr(0, outputStr.length() - 1);
    }
    return "Queue is empty";
}
bool Dequeue::isEmpty(){
    if((this->tailIndex-1) == this->headIndex){
        return true;
    }
    return false;
}
Dequeue::~Dequeue()
{
    //dtor
     //delete [] this->data;
}
