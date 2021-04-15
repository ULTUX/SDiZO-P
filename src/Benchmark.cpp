//
// Created by Wladyslaw Nowak on 15.04.2021.
//

#include "Benchmark.h"

Benchmark::Benchmark(BenchmarkType type, bool writeToFile):type(type),writeToFile(writeToFile){
    cout<<"Starting benchmark..."<<endl;
    switch (type) {
        case BST_T: testBST();
        case DoublyLinkedList_T: testDoublyLinkedList();
        case DynamicArray_T: testDynamicArray();
        case Heap_T: testHeap();
        case RBTree_T: testRBTree();
    }
}

void Benchmark::testBST() {

}

void Benchmark::testDoublyLinkedList() {

}

void Benchmark::testDynamicArray() {

}

void Benchmark::testHeap() {

}

void Benchmark::testRBTree() {

}
