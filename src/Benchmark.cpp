//
// Created by Wladyslaw Nowak on 15.04.2021.
//

#include "Benchmark.h"

Benchmark::Benchmark(BenchmarkType type, bool writeToFile,int initialSize, int step, int multiplier)
                     :type(type),writeToFile(writeToFile),initialSize(initialSize),step(step),multiplier(multiplier){
    cout<<"Starting benchmark..."<<endl;
    performanceCounter = new LARGE_INTEGER;
    switch (type) {
        case BST_T: testBST();
        case DoublyLinkedList_T: testDoublyLinkedList();
        case DynamicArray_T: testDynamicArray();
        case Heap_T: testHeap();
        case RBTree_T: testRBTree();
    }
}

void Benchmark::testBST() {
    this->bst = new BST();
    startTimer();
    Sleep(1000);
    cout<<stopTimer()<<endl;

}

void Benchmark::testDoublyLinkedList() {

}

void Benchmark::testDynamicArray() {

}

void Benchmark::testHeap() {

}

void Benchmark::testRBTree() {

}

void Benchmark::startTimer() {
    LARGE_INTEGER count;
    QueryPerformanceCounter(&count);
    *performanceCounter = count;
}

double Benchmark::stopTimer() {
    LARGE_INTEGER count;
    QueryPerformanceCounter(&count);
    LARGE_INTEGER freq;
    QueryPerformanceFrequency(&freq);
    uint64_t elapsed = count.QuadPart - (*performanceCounter).QuadPart;
    double timeInMs = (1000.0*elapsed)/freq.QuadPart;
    return timeInMs;

}
