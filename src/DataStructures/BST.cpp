//
// Created by Wladyslaw Nowak on 15.04.2021.
//

#include <cmath>
#include "../../include/BST.h"

void BST::add(int val) {
    if (root == nullptr){
        this->root = new BSTNode(val);
        size++;
        return;
    }
    this->root->add(val);
    size++;

}

void BST::remove(int val) {
    if (this->root == nullptr) return;
    size--;
    this->root->remove(val);
}

BSTNode *BST::search(int val) {
    if (this->root == nullptr) return nullptr;
    return this->root->search(val);
}

void BST::printInOrder() {
    if (this->root == nullptr) return;
    this->root->printInOrder();
}

void BST::rotateRight(BSTNode *node) {
    if (node != nullptr && node->getLeft() != nullptr){
        BSTNode* left = node->getLeft();
        if (node->getParent() != nullptr){
            if (node->getParent()->getLeft() == node) node->getParent()->setLeft(left);
            else node->getParent()->setRight(left);
        }
        node->setLeft(left->getRight());
        left->setRight(node);
        left->setParent(node->getParent());
        if (node == root) {
            root = left;
        }
        node->setParent(left);
    }
}

void BST::rotateLeft(BSTNode *node) {
    if (node != nullptr && node->getRight() != nullptr){
        BSTNode* right = node->getRight();
        if (node->getParent() != nullptr) {
            if (node->getParent()->getLeft() == node) node->getParent()->setLeft(right);
            else node->getParent()->setRight(right);
        }
        node->setRight(right->getLeft());
        right->setParent(node->getParent());
        right->setLeft(node);
        if (node == root) {
            root = right;
        }
        node->setParent(right);

    }
}

BST::BST(int val) {
    add(val);
}

BSTNode *BST::getRoot() const {
    return root;
}

void BST::fixDSW() {
    BSTNode* tmp = root;
    while (tmp != nullptr){
        if (tmp->getLeft() != nullptr){
            rotateRight(tmp);
            tmp = tmp->getParent();
        }
        else {
            tmp = tmp->getRight();
        }
    }

    int size = pow(2, (int)log2(this->size+1)) - 1;
    tmp = root;
    for (int i = 0; i < this->size-size; i++){
        rotateLeft(tmp);
        tmp = tmp->getParent()->getRight();
    }
    while (size > 1) {
        tmp = root;
        size = (int)size/2;
        for (int i = 0; i < size; i++){
            rotateLeft(tmp);
            tmp = tmp->getParent()->getRight();
        }
    }
}
