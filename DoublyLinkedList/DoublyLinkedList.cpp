//
// Created by Władysław Nowak on 29/03/2021.
//

#include "DoublyLinkedList.h"


DoublyLinkedList *DoublyLinkedList::removeElement(int val) {
    DoublyLinkedNode* curr = head;

    if (head->getVal() == val){
        head->getNext()->setPrev(nullptr);
        head = head->getNext();
        delete curr;
    }
    else {
        while (curr->getVal() != val && curr->getNext() != nullptr){
            curr = curr->getNext();
        }
        if (curr->getNext() != nullptr){
            curr->getPrev()->setNext(curr->getNext());
            curr->getNext()->setPrev(curr->getPrev());
            delete curr;
        }
    }
    return this;
}

DoublyLinkedList *DoublyLinkedList::addFront(int val) {

    auto* element = new DoublyLinkedNode(val);
    if (head == nullptr){
        head = element;
    }
    else {
        head->setPrev(element);
        element->setNext(head);
        head = element;
    }
    return this;
}

DoublyLinkedList *DoublyLinkedList::addBack(int val) {
    auto* element = new DoublyLinkedNode(val);
    if (head == nullptr) {
        head = element;
    }
    else {
        DoublyLinkedNode* tail = getLastElement();
        tail->setNext(element);
        element->setPrev(tail);
    }
    return this;
}

int DoublyLinkedList::indexOf(int element) {
    if (head == nullptr) return -1;
    else {
        DoublyLinkedNode* nextPointer = head;
        int i = 0;
        while (nextPointer->getVal() != element){
            nextPointer = nextPointer->getNext();
            i++;
        }
        return i;
    }
}

DoublyLinkedNode *DoublyLinkedList::getLastElement() {
    DoublyLinkedNode* node = head;
    while (node->getNext() != nullptr){
        node = node->getNext();
    }
    return node;
}

//To fix
int DoublyLinkedList::get(int index){
    DoublyLinkedNode* node = getNodeAt(index);
    return node->getVal();
}

int DoublyLinkedList::getSize() {
    if (head == nullptr) return 0;
    DoublyLinkedNode* node = head;
    int i = 1;
    while (node->getNext() != nullptr){
        node = node->getNext();
        i++;
    }
    return i;
}

DoublyLinkedList *DoublyLinkedList::addAtIndex(int index, int val) {
    auto* newElement = new DoublyLinkedNode(val);
    DoublyLinkedNode* nodeAtIndex = getNodeAt(index);
    if (nodeAtIndex == head) {
        newElement->setNext(head->getNext());
        head->setPrev(newElement);
        head = newElement;
        return this;
    }
    cout<<nodeAtIndex->getVal()<<endl;
    newElement->setPrev(nodeAtIndex->getPrev());
    newElement->setNext(nodeAtIndex);
    nodeAtIndex->getPrev()->setNext(newElement);
    nodeAtIndex->setPrev(newElement);
    return this;
}

DoublyLinkedNode *DoublyLinkedList::getNodeAt(int i) {
    DoublyLinkedNode* node = head;
    int in = 0;
    while (node->getNext() != nullptr && in != i){
        node = node->getNext();
        in++;
    }
    if (in == i){
        return node;
    }
    return nullptr;
}
