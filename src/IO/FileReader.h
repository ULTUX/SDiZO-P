//
// Created by Wladyslaw Nowak on 11/04/2021.
//

#ifndef SDIZO1_FILEREADER_H
#define SDIZO1_FILEREADER_H

#include "../../include/BST.h"
#include "../../include/DoublyLinkedList.h"
#include "../../include/DynamicArray.h"
#include "../../include/Heap.h"
#include "../../include/RBTree.h"
#include <fstream>
#include <iostream>
#include <cstdlib>

enum PushType {
    FRONT,
    BACK
};

/**
 * This class helps reading int data from files and pushing this data into data structures. \n
 * Data should be delimited with spaces or other white characters. \n
 * First value in this file should be representing amount of values stored in this file. \n
 * Supported file structures:
 * - BST
 * - DoublyLinkedList
 * - DynamicArray
 * - Heap
 * - RBTree
 */
class FileReader {
private:
    /**
     * Name of input file.
     */
    std::string fileName;

    /**
     * File input stream.
     */
    ifstream input;

    /**
     * Amount of data to be read.
     * This value is automatically set during object initialization.
     */
    int structureSize = 0;

    /**
     * Get next value from file and return it.
     * @return Value read from the file.
     */
    int readNextVal();

public:
    /**
     * Create new instance of this class with name of file to read from.
     * This class also performs first read from file - it reads and stores first value representing amount of data in this file.
     * @param fileName Name of file to read from.
     */
    explicit FileReader(const std::string& fileName);

    /**
     * Read data stored in this file into BST tree.
     * @param dest Tree to write to.
     */
    void readToBST(BST* dest);

    /**
     * Read data stored in this file into DoublyLinkedList.
     * @param dest Pointer to destination list.
     */
    void readToDoublyLinkedList(DoublyLinkedList* dest, PushType type);

    /**
     * Read data stored in this file into DynamicArray.
     * @param dest Pointer to destination array.
     */
    void readToDynamicArray(DynamicArray* dest, PushType type);

    /**
     * Read data stored in this file into Heap.
     * @param dest Pointer to destination heap.
     */
    void readToHeap(Heap* dest);

    /**
     * Read data stored in this file into RBTree.
     * @param dest Pointer to destination tree.
     */
    void readToRBTree(RBTree* dest);

    /**
     * Get amount of items stored in input file.
     * @return Value equal to amount of int values stored in input file.
     */
    int getStructureSize() const;


};


#endif //SDIZO1_FILEREADER_H
