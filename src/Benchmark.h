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
#include <windows.h>
#include <functional>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <random>

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
    BenchmarkType type;
    LARGE_INTEGER* performanceCounter;
    mt19937 randNumGen;
    uniform_int_distribution<int> numberDistribution;

    /**
     * Amount of times the tests should be run - then the values are averaged.
     */
    int testNumber;

    /**
     * Initial size to start tests from.
     */
    int initialSize;

    /**
     * Step to increment size by every iteration.
     */
    int step;

    /**
     * Multiplier to multiply size by every iteration.
     */
    int multiplier;

    /**
     * Max size to be reached.
     */
     int maxSize;

     /**
      * Expected iteration number.
      */
     int iterationNumber{};

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

    void generatePopulation(int* dataSet, int size, uniform_int_distribution<int> dist);

    /**
     * Should produce output to csv file.
     */
    bool isWriteToFile;

    void startTimer();

    double stopTimer();

    void calcIterationNumber();

    void writeToFile(string testName, double *data, int *size) const;

    int getNextRandom(uniform_int_distribution<int>& dist);

    uniform_int_distribution<int> getRandomInRange(int a, int b);

public:
    /**
     * Begin benchmarking. Perform all possible tests depending on specified data structure type.
     * @param type Which data structure should be tested.
     * @param writeToFile Should benchmark produce output to csv file.
     */
    explicit Benchmark(BenchmarkType type, bool writeToFile,
                       int initialSize, int step, int multiplier, int testNumber, int maxSize);

};


#endif //SDIZO1_BENCHMARK_H
