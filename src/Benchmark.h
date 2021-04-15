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

/**
 * Benchmark given data structure and write output to stdout and csv file.
 */
class Benchmark {
private:
    BST* bst;
    DoublyLinkedList* doublyLinkedList;
    DynamicArray* dynamicArray;
    Heap* heap;
    RBTree* rbTree;
    BenchmarkType type;

    /**
     * Perform Red Black Tree benchmark.
     * This method is called automatically by the constructor.
     */
    void testBST();
    /**
     * Perform Red Black Tree benchmark.
     * This method is called automatically by the constructor.
     */
    void testDoublyLinkedList();
    /**
     * Perform Red Black Tree benchmark.
     * This method is called automatically by the constructor.
     */
    void testDynamicArray();
    /**
     * Perform Red Black Tree benchmark.
     * This method is called automatically by the constructor.
     */
    void testHeap();

    /**
     * Perform Red Black Tree benchmark.
     * This method is called automatically by the constructor.
     */
    void testRBTree();

    /**
     * Should produce output to csv file.
     */
    bool writeToFile;

public:
    /**
     * Begin benchmarking. Perform all possible tests depending on specified data structure type.
     * @param type Which data structure should be tested.
     * @param writeToFile Should benchmark produce output to csv file.
     */
    explicit Benchmark(BenchmarkType type, bool writeToFile);

};


#endif //SDIZO1_BENCHMARK_H
