//
// Created by Władysław Nowak on 08/04/2021.
//


#include "../../include/RBTree.h"
#include <iostream>
RBTree::RBTree(int value) {
    this->root = new RBNode(value, BLACK);
}

RBTree::RBTree(RBNode *node) {
    this->root = node;
}

void RBTree::add(int value) {
    auto* newNode = new RBNode(value, RED);
    if (root == nullptr){
        root = newNode;
        root->setColor(BLACK);
        return;
    }
    BSTInsert(newNode, root);
    // Now node is inserted into the tree.

    //Node is not root node
    fixTree(newNode);

}

void RBTree::remove(int value) {
    remove(search(value));
}

void RBTree::remove(RBNode *node) {
    if (node->getColor() == BLACK) restoreDelete(node);
    if (node->getLeft() == nullptr && node->getRight() == nullptr){
        if (node == root) root = nullptr;
        else if (isRightChild(node)) node->getParent()->setRight(nullptr);
        else if (node->getParent() != nullptr) node->getParent()->setLeft(nullptr);
        delete node;
    }
    else if (node->getLeft() == nullptr && node->getRight() != nullptr){
        if (isRightChild(node)) node->getParent()->setRight(node->getRight());
        else {
            if (node == root) root = node->getRight();
            else node->getParent()->setLeft(node->getRight());
        }
        node->getRight()->setParent(node->getParent());
        delete node;
    }
    else if (node->getLeft() != nullptr && node->getRight() == nullptr){
        if (isRightChild(node)) node->getParent()->setRight(node->getLeft());
        else{
            if (node == root) root = node->getLeft();
            else node->getParent()->setLeft(node->getLeft());
        }
        node->getLeft()->setParent(node->getParent());
        delete node;
    }
    else {
        RBNode* successor = getNext(node);
        if (successor != nullptr){
            node->setData(successor->getData());
            remove(successor);
        }
    }
}


RBNode *RBTree::search(int value) {
    RBNode* node = root;

    while (node != nullptr && node->getData() != value){
        if (node->getData() > value){
            node = node->getLeft();
        }
        else {
            node = node->getRight();
        }
    }

    if (node == nullptr) return nullptr;
    if (node->getData() == value) return node;
    return nullptr;
}

void RBTree::rotateRight(RBNode *node) {
    if (node != nullptr && node->getLeft() != nullptr){
        RBNode* left = node->getLeft();
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

void RBTree::rotateLeft(RBNode *node) {
    if (node != nullptr && node->getRight() != nullptr){
        RBNode* right = node->getRight();
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

void RBTree::BSTInsert(RBNode *node, RBNode* startingNode) {
    if (startingNode->getData() > node->getData()){
        if (startingNode->getLeft() != nullptr) BSTInsert(node, startingNode->getLeft());
        else {
            startingNode->setLeft(node);
            node->setParent(startingNode);
        }
    }
    else {
        if (startingNode->getRight() != nullptr) BSTInsert(node, startingNode->getRight());
        else {
            startingNode->setRight(node);
            node->setParent(startingNode);
        }
    }
}

void RBTree::fixTree(RBNode *startNode) {
    auto currentNode = startNode;
    if (startNode == root) {
        startNode->setColor(BLACK);
        return;
    }
//    currentNode->setColor(RED);

    while (currentNode != root && currentNode->getColor() != BLACK && currentNode->getParent()->getColor() == RED){
        RBNode* parent = currentNode->getParent();
        RBNode* gParent = parent->getParent();
        if (!isRightChild(parent)){
            RBNode* uncle = getUncle(currentNode);

            if (uncle != nullptr && uncle->getColor() == RED){
                gParent->setColor(RED);
                parent->setColor(BLACK);
                uncle->setColor(BLACK);
                currentNode = gParent;
            }
            else {
                if (isRightChild(currentNode)){
                    rotateLeft(parent);
                    currentNode = parent;
                    parent = currentNode->getParent();
                }
                rotateRight(gParent);
                Color color = parent->getColor();
                parent->setColor(gParent->getColor());
                gParent->setColor(color);
                currentNode = parent;
            }
        }
        else {
            RBNode* uncle = getUncle(currentNode);
            if (uncle != nullptr && uncle->getColor() == RED){
                gParent->setColor(RED);
                parent->setColor(BLACK);
                uncle->setColor(BLACK);
                currentNode = gParent;
            }
            else {
                if (!isRightChild(currentNode)){
                    rotateRight(parent);
                    currentNode = parent;
                    parent = currentNode->getParent();
                }
                rotateLeft(gParent);
                Color color = parent->getColor();
                parent->setColor(gParent->getColor());
                gParent->setColor(color);
            }
        }
        root->setColor(BLACK);
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
    if (node->getParent() == nullptr) return false;
    if (node->getParent()->getLeft() == node) return false;
    return true;
}

RBNode *RBTree::getRoot() const {
    return root;
}

RBNode *RBTree::getNext(RBNode *node) {
    if (node->getRight() != nullptr){
        RBNode* minNode = node->getRight();
        while (minNode->getLeft() != nullptr){
            minNode = minNode->getLeft();
        }
        return minNode;
    }
    return nullptr;
}

void RBTree::restoreDelete(RBNode *node) {
    RBNode* onlyChild = nullptr;
    if (node->getLeft() != nullptr) onlyChild = node->getLeft();
    else if (node->getRight() != nullptr) onlyChild = node->getRight();
    if (onlyChild != nullptr){
        if (node->getColor() == RED || onlyChild->getColor() == RED) {
            onlyChild->setColor(BLACK);
            return;
        }
    }
    if (node->getColor() == BLACK && (onlyChild == nullptr || onlyChild->getColor() == BLACK)){
        fixDoubleBlack(node);
    }
}

RBNode *RBTree::getSibling(RBNode *node) {
    if (isRightChild(node)) return node->getParent()->getLeft();
    return node->getParent()->getRight();
}

void RBTree::fixDoubleBlack(RBNode *node) {
    if (node == root) return;
    RBNode* sibling = getSibling(node);
    RBNode* parent = node->getParent();
    if (sibling == nullptr) fixDoubleBlack(node->getParent());
    else if (sibling->getColor() == BLACK){
        RBNode* rightChildSib = sibling->getRight();
        RBNode* leftChildSib = sibling->getLeft();
        if ((rightChildSib != nullptr && rightChildSib->getColor() == RED)
            || (leftChildSib != nullptr && leftChildSib->getColor() == RED)) {
            //One of sibling's children is RED
            RBNode* redChild = nullptr;
            bool bothRed = (rightChildSib != nullptr && rightChildSib->getColor() == RED)
                            && (leftChildSib != nullptr && leftChildSib->getColor() == RED);
            if (rightChildSib != nullptr && rightChildSib->getColor() == RED) redChild = rightChildSib;
            else redChild = leftChildSib;
            if (!isRightChild(sibling)){
                //Left - x case
                if (redChild == leftChildSib || bothRed){
                    //Left Left case
                    leftChildSib->setColor(sibling->getColor());
                    rotateRight(node->getParent());
                }
                else if (redChild == rightChildSib){
                    //Left Right case
                    rightChildSib->setColor(parent->getColor());
                    rotateLeft(sibling);
                    rotateRight(node->getParent());
                }
            }
            else {
                // Right - x case
                if (redChild == rightChildSib || bothRed){
                    //Right Right case
                    rightChildSib->setColor(sibling->getColor());
                    rotateLeft(node->getParent());
                    sibling->setColor(parent->getColor());
                }
                else if (redChild == leftChildSib) {
                    //Right Left case
                    leftChildSib->setColor(parent->getColor());
                    rotateRight(sibling);
                    rotateLeft(node->getParent());
                }
            }
        }
        else {
            //BOTH children are BLACK
            sibling->setColor(RED);
            if (node->getParent()->getColor() == BLACK) fixDoubleBlack(node->getParent());
            else node->getParent()->setColor(BLACK);
        }
    }
    else if (sibling != nullptr && sibling->getColor() == RED) {
        if (!isRightChild(sibling)){
            //left case
            sibling->getParent()->setColor(RED);
            rotateRight(sibling->getParent());
            sibling->setColor(BLACK);
            fixDoubleBlack(node);
        }
        else {
            //right case
            sibling->getParent()->setColor(RED);
            rotateLeft(sibling->getParent());
            sibling->setColor(BLACK);
            fixDoubleBlack(node);
        }
    }
}

RBTree::~RBTree() {
    hardDelete(root);
}

void RBTree::hardDelete(RBNode *node) {
    if (node == nullptr) return;
    hardDelete(node->getLeft());
    hardDelete(node->getRight());
    delete node;
}
