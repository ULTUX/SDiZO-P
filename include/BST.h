//
// Created by bulio on 15.04.2021.
//

#ifndef SDIZO1_BST_H
#define SDIZO1_BST_H

#include "../DataStructures/helper-classes/BSTNode.h"

/**
 * Facade class built over BSTNode class.
 * This class should be used for creating BST structures.
 */
class BST {
private:
    /**
     * Instance of BSTNode being root of this tree.
     */
    BSTNode* root = nullptr;
public:
    /**
     * Push new value to the tree.
     * It calls add method on BSTNode being root of this tree.
     * @param val Value to be added.
     */
    void add(int val);
    /**
     * Remove value from the tree.
     * It calls remove method on BSTNode being root of this tree.
     * @param val Value to be removed.
     */
    void remove(int val);

    /**
     * Search fo value in the tree.
     * It calls search method on the root of this tree.
     * @param val Value to be found.
     * @return Instance of BSTNode storing this value, nullptr if value does not exist.
     */
    BSTNode* search(int val);

    /**
     * Calls printInOrder on the root.
     */
    void printInOrder();

};


#endif //SDIZO1_BST_H
