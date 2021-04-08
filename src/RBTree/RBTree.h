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

public:
    /**
     * Constructor to create new RBTree with initial value as root.
     * @param value Initial int value.
     */
    RBTree(int value);

    /**
     *
     * @param node
     */
    RBTree(RBNode* node);
    void add(int value);
    void remove(int value);
    RBNode* search(int value);
};


#endif //SDIZO1_RBTREE_H
