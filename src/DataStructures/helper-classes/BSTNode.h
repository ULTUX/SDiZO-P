//
// Created by Wladyslaw Nowak on 06/04/2021.
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
    BSTNode* left = nullptr;

    /**
     * Right son of this node.
     */
    BSTNode* right = nullptr;

    /**
     * This node's parent.
     */
    BSTNode* parent = nullptr;

    /**
     * Get node with min value in this node's subtree.
     * @return Pointer to this node.
     */
    BSTNode* getMin();

public:

    /**
     * Get this node's parent.
     * @return Node being parent of this node.
     */
    BSTNode *getParent() const;

    /**
     * Set parent of this node.
     * @param parent New parent of this node.
     */
    void setParent(BSTNode *parent);

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
     * Search and return node with given value.
     * @param val Value to be searched.
     * @return Node that represents this value.
     */
    BSTNode* search(int val);

    /**
     * Print this root's subtree in-order (non descending).
     */
    void printInOrder();

    /**
     * Get this node's left son.
     * @return Node being left son.
     */
    BSTNode *getLeft() const;

    /**
     * Get this node's right son.
     * @return Node being right son.
     */
    BSTNode *getRight() const;

    /**
     * Set this node's left son.
     * @param left Node to become this node's left son.
     */
    void setLeft(BSTNode *left);

    /**
     * Set this node's right son.
     * @param left Node to become this node's right son.
     */
    void setRight(BSTNode *right);

    int getValue() const;

    void setValue(int value);

    bool isRightChild();

/**
 * Get lowest value higher than root.
 * @return Pointer to this node.
 */
BSTNode* getNext();
};


#endif //SDIZO1_BSTNODE_H
