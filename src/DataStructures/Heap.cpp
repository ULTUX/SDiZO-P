//
// Created by Władysław Nowak on 29/03/2021.
//

#include <iostream>
#include "cmath"
#include "../../include/Heap.h"

void Heap::add(int val) {
    array->addBack(val);
    heapifyUp(array->getSize() - 1);
}

void Heap::heapifyUp(int index) {
    if (index == 0) return;
    if (array->get(index) > array->get((index - 1) / 2)) {
        array->swap(index, (index - 1) / 2);
        heapifyUp((index - 1) / 2);
    }
}

void Heap::heapifyDown(int index) {
    int maxIndex = index;
    for (int i = 1; i <= 2; i++){
        if (2*index+i < array->getSize() && array->get(2*index+i) > array->get(maxIndex)) maxIndex = 2*index+i;
    }
    if (maxIndex != index) {
        array->swap(index, maxIndex);
        heapifyDown(maxIndex);
    }
}

int Heap::remove() {
    int toReturn = array->get(0);
    array->set(0, array->get(array->getSize()-1));
    array->remove(array->getSize()-1);
    heapifyDown(0);
    return toReturn;
}

int Heap::getSize() {
    return array->getSize();
}

void Heap::printHeap() {
    for (int i = 0; i < array->getSize(); i++){
        for (int j = 0; j <pow(2, i) &&j+pow(2, i)< 10; j++){
            std::cout<<array->get(j+(int)pow(2, i)-1)<<" ";
        }
        std::cout<<std::endl;
    }
}

Heap::~Heap() {
    delete array;
}

Heap::Heap() {
    array = new DynamicArray();
}
