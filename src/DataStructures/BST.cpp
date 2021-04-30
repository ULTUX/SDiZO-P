//
// Created by Wladyslaw Nowak on 15.04.2021.
//

#include <cmath>
#include <iomanip>
#include <iostream>
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
    if (search(val) == nullptr) throw std::invalid_argument("That value doesn't exist in this tree.");
    if (size == 1) {
        delete root;
        size = 0;
        root = nullptr;
    }
    else {
        size--;
        remove(val, root);
    }

}

void BST::remove(int val, BSTNode* node){
    if (node->getValue() > val){
        if (node->getLeft() != nullptr) {
            remove(val, node->getLeft());
        }
    }
    else if (node->getValue() < val) {
        if (node->getRight() != nullptr) {
            remove(val, node->getRight());
        }
    }
    else {
        if (node->getLeft() == nullptr & node->getRight() == nullptr) {
            if (node->isRightChild()) node->getParent()->setRight(nullptr);
            else node->getParent()->setLeft(nullptr);
            delete node;
            return;
        }
        else if (node->getRight() == nullptr){
            BSTNode* oldNode = node->getLeft();
            if (node == root) root = oldNode;
            oldNode->setParent(nullptr);
            if (node->getParent() != nullptr) {
                oldNode->setParent(node->getParent());
                if (node->isRightChild()) oldNode->getParent()->setRight(oldNode);
                else oldNode->getParent()->setLeft(oldNode);
            }
            delete node;
            return;
        }
        else if (node->getLeft() == nullptr){
            BSTNode* oldNode = node->getRight();
            if (node == root) root = oldNode;
            oldNode->setParent(nullptr);
            if (node->getParent() != nullptr) {
                oldNode->setParent(node->getParent());
                if (node->isRightChild()) oldNode->getParent()->setRight(oldNode);
                else oldNode->getParent()->setLeft(oldNode);
            }
            delete node;
            return;
        }
        else {
            BSTNode* nextNode = node->getNext();
            if (nextNode != nullptr){
                node->setValue(nextNode->getValue());
                remove(nextNode->getValue(), node->getRight());
            }
        }
    }
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
            if (node->getParent()->getLeft() == node) {
                node->getParent()->setLeft(left);
                left->setParent(node->getParent());
            }
            else {
                node->getParent()->setRight(left);
                left->setParent(node->getParent());
            }
        }
        else left->setParent(nullptr);
        node->setLeft(left->getRight());
        if (left->getRight() != nullptr) left->getRight()->setParent(node);
        left->setRight(node);
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
            if (node->getParent()->getLeft() == node) {
                node->getParent()->setLeft(right);
                right->setParent(node->getParent());
            }
            else {
                node->getParent()->setRight(right);
                right->setParent(node->getParent());
            }
        }
        else right->setParent(nullptr);

        node->setRight(right->getLeft());
        if (right->getLeft() != nullptr) right->getLeft()->setParent(node);

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

BST::~BST() {
    hardDelete(root);
}

void BST::hardDelete(BSTNode* node) {
    if (node == nullptr) return;
    hardDelete(node->getLeft());
    hardDelete(node->getRight());
    delete node;
}

//Function created based on: https://stackoverflow.com/a/26699993
void BST::postOrder(BSTNode* node, int indent){
    //DRZEWO DRUKOWANE JEST OD LEWEJ DO PRAWEJ - NIE OD GORY W DOL
    if(node != NULL) {
        if(node->getRight()) {
            postOrder(node->getRight(), indent+4);
        }
        if (indent) {
            std::cout << std::setw(indent) << ' ';
        }
        if (node->getRight()) std::cout<<" /\n" << std::setw(indent) << ' ';
        std::cout<< node->getValue() << "\n ";
        if(node->getLeft()) {
            std::cout << std::setw(indent) << ' ' <<" \\\n";
            postOrder(node->getLeft(), indent+4);
        }
    }
}
