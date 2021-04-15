//
// Created by bulio on 15.04.2021.
//

#include "../../include/BST.h"

void BST::add(int val) {
    if (root == nullptr){
        this->root = new BSTNode(val);
        return;
    }
    this->root->add(val);

}

void BST::remove(int val) {
    if (this->root == nullptr) return;
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
