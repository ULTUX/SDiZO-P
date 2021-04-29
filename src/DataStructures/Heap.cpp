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
    if (array->getSize() > 0){
        int toReturn = array->get(0);
        array->set(0, array->get(array->getSize()-1));
        array->remove(array->getSize()-1);
        heapifyDown(0);
        return toReturn;
    }
    else throw std::length_error("Heap is empty.");
}

int Heap::getSize() {
    return array->getSize();
}

//Based on: https://stackoverflow.com/a/64023669
void Heap::print() {
    if (array->getSize() == 0) return;
    int height = (int) log2(array->getSize());
    for (int i = 0; i <= height; i++) {
        for (int j = 0; j < pow(2, i) && j + pow(2, i) <= array->getSize(); j++) {
            std::cout<<array->get(j + (int) pow(2, i) - 1)<< " ";
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

bool Heap::search(int val) {
    return findElement(val, 0);
}

bool Heap::findElement(int val, int index) {
    if (val == array->get(index)) return true;
    bool res = false;
    bool res2 = false;
    if (array->getSize() > 2*index + 1 && val <= array->get(2*index + 1)) {
        res = findElement(val, 2*index+1);
    }
    if (array->getSize() > 2*index + 2 && val <= array->get(2*index + 2)){
        res2 = findElement(val, 2*index+2);
    }
    return res || res2;
}
