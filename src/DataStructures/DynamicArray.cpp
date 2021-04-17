//
// Created by Władysław Nowak on 27/03/2021.
//

#include <iostream>
#include "../../include/DynamicArray.h"

void DynamicArray::addFront(int element) {
    if (size == 0) {
        //If array length is 0 create new array with size of 1
        initArray(element);
        return;
    }
    //Create replacement array for array pointed by arrayPointer with size+1
    int* replacement = new int[size+1];
    //Add new element at the start of this array
    replacement[0] = element;
    //Copy elements from old array to a new one
    for (int i = 1; i < size; i++){
        replacement[i] = this->arrayPointer[i-1];
    }
    //Free up space taken by old array
    delete[] this->arrayPointer;
    this->arrayPointer = replacement;
    size++;
}

int DynamicArray::remove(int index) {
    //Return -1 if wrong index was passed
    if (index >= size) return -1;
    //Create replacement array for array pointed by arrayPointer with size-1
    int* replacement = new int[size-1];
    int j = 0;
    //Copy elements from old array to a new one
    for (int i = 0; i < size; i++) {
        //If current iteration points to element specified by index, skip it
        if (i == index) continue;
        replacement[j++] = this->arrayPointer[i];
    }
    //Free up space taken by old array
    delete[] this->arrayPointer;
    this->arrayPointer = replacement;
    size--;
    return size;

}

void DynamicArray::addBack(int element) {
    //If array size is 0, then create a new array with a size of 1
    if (size == 0) {
        initArray(element);
        return;
    }
    //Create replacement array for array pointed by arrayPointer with size+1
    int* replacement = new int[size+1];
    //Copy elements from old array to a new one
    for (int i = 0; i < size; i++){
        replacement[i] = this->arrayPointer[i];
    }
    //Assign last element at the end of this array
    replacement[size] = element;
    //Free up space taken by old array
    delete[] this->arrayPointer;
    this->arrayPointer = replacement;
    size++;
}

void DynamicArray::addAtIndex(int element, int index) {
    //If array is empty and index == 0, then create new array with element
    if (index == 0 && size == 0) {
        initArray(element);
        return;
    }
    if (index > size) return;
    if (index == size) {
        addBack(element);
        return;
    }
    if (element == 0 && size > 0){
        addFront(element);
        return;
    }
    int* replacement = new int[size+1];
    int j = 0;
    //Start copying elements from old array
    for (int i = 0; i < size+1; i++){
        //If i == passed parameter, then put element at this index
        if (i == index) {
            replacement[i] = element;
            continue;
        }
        replacement[i] = this->arrayPointer[j++];
    }
    size++;
    delete[] this->arrayPointer;
    this->arrayPointer = replacement;
}

void DynamicArray::initArray(int element) {
     this->arrayPointer = new int[0];
     *arrayPointer = element;
     size = 1;
}

int DynamicArray::getSize() const {
    return this->size;
}

int DynamicArray::get(int index) {
    if (index >= size || index < 0) return -1;
    return arrayPointer[index];
}

void DynamicArray::set(int index, int val) {
    if (index < size) arrayPointer[index] = val;
}

void DynamicArray::printFromBeginning() {
    for (int i = 0; i < size; i++){
        std::cout<<arrayPointer[i]<<" ";
    }
    std::cout<<std::endl;
}

void DynamicArray::swap(int i1, int i2) {
    int temp = get(i1);
    set(i1, get(i2));
    set(i2, temp);
}

DynamicArray::~DynamicArray() {
    delete[] arrayPointer;
}

void DynamicArray::printFromEnd() {
    for (int i = size-1; i >= 0; i--){
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