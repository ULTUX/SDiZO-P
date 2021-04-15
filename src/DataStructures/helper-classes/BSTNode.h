//
// Created by Władysław Nowak on 06/04/2021.
//

#ifndef SDIZO1_BSTNODE_H
#define SDIZO1_BSTNODE_H

/**
 * Class representing every BSTNode node and the tree (every instance of this class could be a new BSTNode root).
 * This class implements basic BSTNode operations: insertion, deletion and search.
 */
class BSTNode {
private:

    /**
     * Value of this node.
     */
    int value;

    /**
     * Left son of this node.
     */
    BSTNode* left;

    /**
     * Right son of this node.
     */
    BSTNode* right;

    /**
     * Get lowest value higher than root.
     * @return Pointer to this node.
     */
    BSTNode* getNext();

    /**
     * Get node with min value in this node's subtree.
     * @return Pointer to this node.
     */
    BSTNode* getMin();
public:
    /**
     * Create new node, initialize the tree with a value.
     * @param val Value to be added.
     */
    explicit BSTNode(int val);

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
    BSTNode* search(int val);

    /**
     * Print this root's subtree in-order (non descending).
     */
    void printInOrder();

};


#endif //SDIZO1_BSTNODE_H
