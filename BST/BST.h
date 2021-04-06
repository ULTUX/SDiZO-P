//
// Created by Władysław Nowak on 06/04/2021.
//

#ifndef SDIZO1_BST_H
#define SDIZO1_BST_H

/**
 * Class representing every BST node and the tree (every instance of this class could be a new BST root).
 * This class implements basic BST operations: insertion, deletion and search.
 */
class BST {
private:

    /**
     * Value of this node.
     */
    int value;

    /**
     * Left son of this node.
     */
    BST* left;

    /**
     * Right son of this node.
     */
    BST* right;

    /**
     * Get lowest value higher than root.
     * @return Pointer to this node.
     */
    BST* getNext();

    /**
     * Get node with min value in this node's subtree.
     * @return Pointer to this node.
     */
    BST* getMin();
public:
    /**
     * Create new node, initialize the tree with a value.
     * @param val Value to be added.
     */
    explicit BST(int val);

    /**
     * Add new element to this node's subtree.
     * @param val Value to be added.
     */
    void add(int val);

    /**
     * Remove node with given value from this node's subtree.
     * @param val Value to be removed.
     */
    void remove(int val);

    /**
     * Search and return node with given value.
     * @param val Value to be searched.
     * @return Node that represents this value.
     */
    BST* search(int val);

    /**
     * Print this root's subtree in-order (non descending).
     */
    void printInOrder();

};


#endif //SDIZO1_BST_H
