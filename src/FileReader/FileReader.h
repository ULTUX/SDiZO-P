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

class FileReader {
private:
    std::string fileName;
    ifstream input;
    int structureSize = 0;
public:
    explicit FileReader(std::string fileName);
    void readToBST(BST* dest);
    void readToDoublyLinkedList(DoublyLinkedList* dest);
    void readToDynamicArray(DynamicArray* dest);
    void readToHeap(Heap* dest);

    int getStructureSize() const;

    void readToRBTree(RBTree* dest);
    int readNextVal();

};


#endif //SDIZO1_FILEREADER_H
