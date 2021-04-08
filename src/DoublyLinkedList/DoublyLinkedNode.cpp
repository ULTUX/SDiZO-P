//
// Created by Władysław Nowak on 29/03/2021.
//

#include "DoublyLinkedNode.h"

DoublyLinkedNode::DoublyLinkedNode(int val) {
    value=val;
}

void DoublyLinkedNode::setNext(DoublyLinkedNode *elementDk) {
    next = elementDk;
}

void DoublyLinkedNode::setPrev(DoublyLinkedNode *elementDk) {
    prev = elementDk;
}

DoublyLinkedNode *DoublyLinkedNode::getNext() {
    return next;
}

DoublyLinkedNode *DoublyLinkedNode::getPrev() {
    return prev;
}

int DoublyLinkedNode::getVal() {
    return value;
}
