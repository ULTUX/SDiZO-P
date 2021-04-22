//
// Created by Władysław Nowak on 06/04/2021.
//

#include <iostream>
#include "BSTNode.h"


void BSTNode::add(int val) {
    if (this->value > val){
        if (this->left != nullptr) this->left->add(val);
        else {
            this->left = new BSTNode(val);
            this->left->setParent(this);
        }
    }
    else {
        if (this->right != nullptr) this->right->add(val);
        else {
            this->right = new BSTNode(val);
            this->right->setParent(this);
        }
    }
}

BSTNode::BSTNode(int val): value(val), left(nullptr), right(nullptr){};


int BSTNode::getValue() const {
    return value;
}

BSTNode *BSTNode::search(int val) {
    if (this->value == val) return this;
    if (this->value > val){
        return this->left->search(val);
    }
    return this->right->search(val);
}

BSTNode *BSTNode::getNext() {
    if (this->right != nullptr){
        return this->right->getMin();
    }
    else return nullptr;
}

BSTNode *BSTNode::getMin() {
    if (this->left == nullptr) return this;
    return this->left->getMin();
}

void BSTNode::printInOrder() {
    if (this->left != nullptr) this->left->printInOrder();
    std::cout<<this->value<<" ";
    if (this->right != nullptr) this->right->printInOrder();
}

BSTNode *BSTNode::getParent() const {
    return parent;
}

void BSTNode::setParent(BSTNode *parent) {
    this->parent = parent;
}


BSTNode *BSTNode::getLeft() const {
    return left;
}

BSTNode *BSTNode::getRight() const {
    return right;
}

void BSTNode::setLeft(BSTNode *left) {
    BSTNode::left = left;
}

void BSTNode::setRight(BSTNode *right) {
    BSTNode::right = right;
}

void BSTNode::setValue(int value) {
    BSTNode::value = value;
}

bool BSTNode::isRightChild() {
    if (this->getParent() == nullptr) return false;
    if (this->getParent()->getLeft() == this) return false;
    return true;
}


