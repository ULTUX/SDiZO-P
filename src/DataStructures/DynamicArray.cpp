//
// Created by Władysław Nowak on 27/03/2021.
//

#include <iostream>
#include "../../include/DynamicArray.h"

void DynamicArray::addFront(int element) {
    //Create replacement array for array pointed by arrayPointer with size+1
    if (numElements >= size) extend();
    //Add new element at the start of this array
    //Copy elements from old array to a new one
    for (int i = numElements; i >= 1; i--){
        arrayPointer[i] = arrayPointer[i-1];
    }
    arrayPointer[0] = element;
    //Free up space taken by old array
    numElements++;
}

int DynamicArray::remove(int index) {
    //Return -1 if wrong index was passed
    if (index >= size) return -1;
    //Create replacement array for array pointed by arrayPointer with size-1
    int j = 0;
    //Copy elements from old array to a new one
    for (int i = 0; i < size; i++) {
        //If current iteration points to element specified by index, skip it
        if (i == index) continue;
        arrayPointer[j++] = arrayPointer[i];
    }
    arrayPointer[numElements - 1] = 0;
    numElements--;
    if (numElements < size/2) collapse();
    //Free up space taken by old array
    return numElements;

}

void DynamicArray::addBack(int element) {
    //If array size is 0, then create a new array with a size of 1
    if (numElements >= size) extend();

    arrayPointer[numElements] = element;
    numElements++;
}

void DynamicArray::addAtIndex(int element, int index) {
    //If array is empty and index == 0, then create new array with element
    if (index > numElements || index < 0) {
        throw std::invalid_argument("Wrong index passed.");
    }
    if (index == numElements) {
        addBack(element);
        return;
    }
    if (index == 0 && numElements > 0){
        addFront(element);
        return;
    }
    if (numElements >= size) extend();
    int j = 0;
    //Start copying elements from old array
    for (int i = numElements; i > index; i--){
        //If i == passed parameter, then put element at this index
        arrayPointer[i] = arrayPointer[i-1];
    }
    arrayPointer[index] = element;
    numElements++;
}

void DynamicArray::initArray() {
    this->arrayPointer = new int[1];
    size = 1;
    numElements = 0;
}

int DynamicArray::getSize() const {
    return this->numElements;
}

int DynamicArray::get(int index) {
    if (index >= size || index < 0) return -1;
    return arrayPointer[index];
}

void DynamicArray::set(int index, int val) {
    if (index < size) arrayPointer[index] = val;
}


void DynamicArray::swap(int i1, int i2) {
    int temp = get(i1);
    set(i1, get(i2));
    set(i2, temp);
}

DynamicArray::~DynamicArray() {
    delete[] arrayPointer;
}

void DynamicArray::extend() {
    size *= 2;
    int * temp = new int[size];

    for (int i = 0; i < numElements; i++){
        temp[i] = arrayPointer[i];
    }
    delete[] arrayPointer;

    arrayPointer = temp;

}

void DynamicArray::collapse() {
    if (numElements < size/2){
        size /= 2;
        int *temp = new int[size];

        for (int i = 0; i < numElements; i++){
            temp[i] = arrayPointer[i];
        }
    }
}

DynamicArray::DynamicArray() {
    initArray();
}

void DynamicArray::printFromBeginning() {
    if (this->size == 0) return;
    for (int i = 0; i < numElements; i++){
        std::cout<<arrayPointer[i]<<" ";
    }
    std::cout<<std::endl;
}

void DynamicArray::printFromEnd() {
    if (size == 0) return;
    for (int i = numElements-1; i >= 0; i--){
        std::cout<<arrayPointer[i]<<" ";
    }
    std::cout<<std::endl;
}

bool DynamicArray::contains(int val) {
    for (int i = 0; i < size; i++){
        if (arrayPointer[i] == val) return true;
    }
    return false;
}
int DynamicArray::indexOf(int val) {
    for (int i = 0; i < size; i++){
        if (arrayPointer[i] == val) return i;
    }
    return -1;
}