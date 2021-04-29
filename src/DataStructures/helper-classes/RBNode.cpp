//
// Created by Władysław Nowak on 08/04/2021.
//

#include "RBNode.h"


Color RBNode::getColor() const {
    return color;
}

void RBNode::setColor(Color color) {
    RBNode::color = color;
}

RBNode *RBNode::getRight() const {
    return right;
}

void RBNode::setRight(RBNode *right) {
    RBNode::right = right;
}

RBNode *RBNode::getLeft() const {
    return left;
}

void RBNode::setLeft(RBNode *left) {
    RBNode::left = left;
}

RBNode *RBNode::getParent() const {
    return parent;
}

void RBNode::setParent(RBNode *parent) {
    RBNode::parent = parent;
}

int RBNode::getData() const {
    return data;
}

void RBNode::setData(int data) {
    RBNode::data = data;
}

void RBNode::printInOrder() {
    if (this->left != nullptr) this->left->printInOrder();
    std::cout<<this->toString()+" ";
    if (this->right != nullptr) this->right->printInOrder();
}

std::string RBNode::toString() {
    std::string charColor;
    switch (color){
        case BLACK: {
            charColor = "B";
            break;
        }
        case RED: {
            charColor = "R";
            break;
        }
    }
    std::string val = std::to_string(this->data)+"("+charColor+")";
    return val;
}
