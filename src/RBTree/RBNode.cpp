//
// Created by Władysław Nowak on 08/04/2021.
//

#include "RBNode.h"

Color RBNode::getColor() const {
    return static_cast<Color>(color);
}

void RBNode::setColor(bool color) {
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
