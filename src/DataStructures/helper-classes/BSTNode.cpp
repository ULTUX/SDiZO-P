//
// Created by Władysław Nowak on 06/04/2021.
//

#include <iostream>
#include "BSTNode.h"


void BSTNode::add(int val) {
    if (this->value > val){
        if (this->left != nullptr) this->left->add(val);
        else this->left = new BSTNode(val);
    }
    else {
        if (this->right != nullptr) this->right->add(val);
        else this->right = new BSTNode(val);
    }
}

BSTNode::BSTNode(int val): value(val), left(nullptr), right(nullptr){};

void BSTNode::remove(int val) {
    if (this->value > val){
        if (this->left != nullptr) {
            if (this->left->value == val && this->left->left == nullptr && this->left->right == nullptr){
                delete this->left;
                this->left = nullptr;
            }
            else this->left->remove(val);
        }
    }
    else if (this->value < val) {
        if (this->right != nullptr) {
            if (this->right->value == val && this->right->left == nullptr && this->right->right == nullptr){
                delete this->right;
                this->right = nullptr;
            }
            else this->right->remove(val);
        }
    }
    else {
        if (this->right == nullptr){
            BSTNode* oldNode = this->left;
            this->value = oldNode->value;
            this->right = oldNode->right;
            this->left = oldNode->left;
            delete oldNode;
            return;
        }
        else if (this->left == nullptr){
            BSTNode* oldNode = this->right;
            this->value = oldNode->value;
            this->left = oldNode->left;
            this->right = oldNode->right;
            delete oldNode;
            return;
        }
        else {
            BSTNode* nextNode = getNext();
            if (nextNode != nullptr){
                this->value = nextNode->value;
                this->right->remove(nextNode->value);
            }
        }
    }
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

