//
// Created by bulio on 17.04.2021.
//

#ifndef SDIZO1_MENU_H
#define SDIZO1_MENU_H


#include "../StructureType.h"
#include "../../include/BST.h"
#include "../../include/DoublyLinkedList.h"
#include "../../include/DynamicArray.h"
#include "../../include/Heap.h"
#include "../../include/RBTree.h"

class Menu {
private:
    StructureType type;
    BST* bst;
    DoublyLinkedList* doublyLinkedList;
    DynamicArray* dynamicArray;
    Heap* heap;
    RBTree* rBTree;

    void backToMainMenu();

    void printMainMenu();
    void printFileLoadMenu();

    void printBSTMenu();
    void printDoublyLinkedListMenu();
    void printDynamicArrayMenu();
    void printHeapMenu();
    void printRBTreeMenu();
    void printBenchmarkMenu();

    void initBST();
    void initDoublyLinkedList();
    void initDynamicArray();
    void initHeap();
    void initRBTree();

public:
    Menu();
};


#endif //SDIZO1_MENU_H
