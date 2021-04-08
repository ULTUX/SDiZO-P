//
// Created by Władysław Nowak on 08/04/2021.
//

#include "RBTree.h"

RBTree::RBTree(int value) {
    this->root = new RBNode(value, BLACK);
}

RBTree::RBTree(RBNode *node) {
    this->root = node;
}

void RBTree::add(int value) {
    auto* newNode = new RBNode(value, RED);
    insertNode(newNode);
    // Now node is inserted into the tree.
    if (newNode == root){
        newNode->setColor(BLACK);
        return;
    }
    //Node is not root node
    fixTree(newNode);

}

void RBTree::remove(int value) {

}

RBNode *RBTree::search(int value) {
    return nullptr;
}

void RBTree::rotateRight(RBNode *node) {
    if (node->getLeft() != nullptr){
        RBNode* left = node->getLeft();
        node->setLeft(left->getRight());
        left->setRight(node);
        left->setParent(node->getParent());
        node->setParent(left);
    }
}

void RBTree::rotateLeft(RBNode *node) {
    if (node->getRight() != nullptr){
        RBNode* right = node->getRight();
        node->setRight(right->getLeft());
        right->setParent(node->getParent());
        right->setLeft(node);
        node->setParent(right);
    }
}

void RBTree::insertNode(RBNode *node) {
    RBNode *currNode = root;
    RBNode* lastNode = root;
    if (root == nullptr) {
        this->root = node;
        return;
    }
    // Loop until given node does not have corresponding child
    while (lastNode != nullptr){
        currNode = lastNode;
        if (node->getData() < currNode->getData()) {
            lastNode = currNode->getLeft();
        }
        else {
            lastNode = currNode->getRight();
        }
    }
    if (node->getData() < currNode->getData()){
        currNode->setLeft(node);
        node->setParent(currNode);
    }
    else {
        currNode->setRight(node);
        node->setParent(currNode);
    }
}

void RBTree::fixTree(RBNode *startNode) {
    auto currentNode = startNode;
    if (startNode == root) {
        startNode->setColor(BLACK);
        return;
    }
    startNode->setColor(RED);
    while (currentNode->getParent()->getColor() != BLACK){
        RBNode* uncle = getUncle(currentNode);
        if (uncle->getColor() == RED){
            //Node color is red
            currentNode->getParent()->setColor(RED);
            uncle->setColor(RED);
            currentNode = currentNode->getParent()->getParent();
            currentNode->setColor(RED);
        }
        else if (isRightChild(currentNode)){
            //Node color is black and is right child
            currentNode = currentNode->getParent();
            rotateLeft(currentNode);

        }
        //Node color is black and is left child
        currentNode->getParent()->setColor(BLACK);
        currentNode->getParent()->getParent()->setColor(RED);
        rotateRight(currentNode->getParent()->getParent());
    }
}

RBNode *RBTree::getUncle(RBNode *node) {
    if (node == root) return nullptr;
    if (node->getParent() == nullptr) return nullptr;
    if (node->getParent()->getParent() == nullptr) return nullptr;
    if (node->getParent()->getParent()->getLeft() == node->getParent() &&
        node->getParent()->getParent()->getRight() != nullptr) return node->getParent()->getParent()->getRight();
    if (node->getParent()->getParent()->getRight() == node->getParent() &&
        node->getParent()->getParent()->getLeft() != nullptr) return node->getParent()->getParent()->getLeft();
    return nullptr;
}

bool RBTree::isRightChild(RBNode *node) {
    if (node == root) return false;
    if (node->getParent()->getLeft() == node) return false;
    return true;
}
