//
// Created by Wladyslaw Nowak on 15.04.2021.
//

#ifndef SDIZO1_BENCHMARK_H
#define SDIZO1_BENCHMARK_H


#include "../include/BST.h"
#include "../include/DoublyLinkedList.h"
#include "../include/DynamicArray.h"
#include "../include/Heap.h"
#include "../include/RBTree.h"
enum BenchmarkType {
    BST_T,
    DoublyLinkedList_T,
    DynamicArray_T,
    Heap_T,
    RBTree_T
};
class Benchmark {
private:
    BST* bst;
    DoublyLinkedList* doublyLinkedList;
    DynamicArray* dynamicArray;
    Heap* heap;
    RBTree* rbTree;
    BenchmarkType type;
public:
    explicit Benchmark(BenchmarkType type);

    void testBST();

    void testDoublyLinkedList();

    void testDynamicArray();

    void testHeap();

    void testRBTree();
};


#endif //SDIZO1_BENCHMARK_H
