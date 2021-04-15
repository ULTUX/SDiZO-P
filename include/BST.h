//
// Created by Wladyslaw Nowak on 15.04.2021.
//

#ifndef SDIZO1_BST_H
#define SDIZO1_BST_H


#include "../src/DataStructures/helper-classes/BSTNode.h"

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

    /**
     * This tree's size.
     */
    int size = 0;



public:
    /**
     * Perform left rotation on this node.
     * @param node Node to rotate.
     */
    void rotateLeft(BSTNode *node);

    /**
     * Perform right rotation on this node.
     * @param node Node to rotate.
     */
    void rotateRight(BSTNode *node);

    /**
     * Create BST with initial root's value.
     * @param val Initial value.
     */
    BST(int val);
    /**
     * Initialize BST without any initial values.
     */
    BST(){};
    /**
     * Push new value to the tree.
     * It calls add method on BSTNode being root of this tree.
     * @param val Value to be added.
     */
    void add(int val);

    /**
     * Remove node with given value from this node's subtree.
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

    /**
     * Get root of this BST.
     * @return Node being root.
     */
    BSTNode *getRoot() const;

    /**
     * Fix tree with DSW algorithm.
     */
    void fixDSW();

    void remove(int val, BSTNode *node);
};


#endif //SDIZO1_BST_H
