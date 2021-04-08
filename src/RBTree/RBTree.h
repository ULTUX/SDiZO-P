//
// Created by Władysław Nowak on 08/04/2021.
//

#ifndef SDIZO1_RBTREE_H
#define SDIZO1_RBTREE_H


#include "RBNode.h"

class RBTree {
private:
    /**
     * Node representing root of this tree.
     */
    RBNode *root;

    /**
     * Perform left rotation on this node.
     * @param node Node to rotate.
     */
    void rotateLeft(RBNode *node);

    /**
     * Perform right rotation on this node.
     * @param node Node to rotate.
     */
    void rotateRight(RBNode *node);

    /**
     * Insert node according to BST insert algorithm.
     * This function just inerts new node to the tree but does NOT fix RB tree.
     * @param node Node to be inserted.
     */
    void insertNode(RBNode* node);

    /**
     * Fix tree starting with given node.
     * @param startNode Node to start fixing from.
     */
    void fixTree(RBNode* startNode);

    /**
     * Find and return parent's sibling.
     * @param node Starting node;
     * @return Node being starting node's uncle. Return nullptr if uncle does not exist.
     */
    RBNode* getUncle(RBNode* node);

    /**
     * Check whether this node is right child of its parent.
     * @param node Node to be checked.
     * @return True is node is right child and false if it is not.
     */
    bool isRightChild(RBNode* node);

public:

    RBNode *getRoot() const;

    /**
     * Constructor to create new RBTree with initial value as root.
     * @param value Initial int value.
     */
    explicit RBTree(int value);

    /**
     * Create new instance of this class with initial node as root.
     * @param node A node to be used as a root.
     */
    explicit RBTree(RBNode* node);

    /**
     * Insert new element to this tree AND perform tree recoloring.
     * @param value Value to be inserted.
     */
    void add(int value);

    /**
     * Remove node with specified value from this tree.
     * @param value Value to be removed.
     */
    void remove(int value);

    /**
     * Search and return instance of node that is carrying specified value.
     * @param value Value to look for.
     * @return Instance of a node that is carrying this value.
     */
    RBNode* search(int value);
};


#endif //SDIZO1_RBTREE_H
