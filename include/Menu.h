//
// Created by Wladyslaw Nowak on 17.04.2021.
//

#ifndef SDIZO1_MENU_H
#define SDIZO1_MENU_H


#include "StructureType.h"
#include "BST.h"
#include "DoublyLinkedList.h"
#include "DynamicArray.h"
#include "Heap.h"
#include "RBTree.h"

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

    /**
     * Initialize BST with details provided by user.
     */
    void initBST();

    /**
     * Initialize DoublyLinkedList tree with details provided by user.
     */
    void initDoublyLinkedList();

    /**
     * Initialize DynamicArray tree with details provided by user.
     */
    void initDynamicArray();

    /**
     * Initialize Heap tree with details provided by user.
     */
    void initHeap();

    /**
     * Initialize RB tree with details provided by user.
     */
    void initRBTree();

    /**
     * Prompt user with message to input integer value and return it.
     * @param message Message to be displayed.
     * @param mustPositive If it is required for the value to be positive.
     * @return Value inputted by user.
     */
    static int getIntegerInput(string message, bool mustPositive = false);

    /**
     * Prompt user with message to input float value and return it.
     * @param message Message to be displayed.
     * @param mustPositive If it is required for the value to be positive.
     * @return Value inputted by user.
     */
    static float getFloatInput(string message, bool mustPositive = false);

    /**
     * Nicely print thrown exception on stdout.
     * @param e Exception to be printed.
     */
    static void printException(exception &e);

public:
    Menu();

};


#endif //SDIZO1_MENU_H
