//
// Created by Władysław Nowak on 29/03/2021.
//


#include "../../include/DoublyLinkedList.h"

DoublyLinkedList *DoublyLinkedList::removeElement(int val) {
    DoublyLinkedNode* curr = head;

    if (head->getVal() == val){
        if (head->getNext() != nullptr) {
            head->getNext()->setPrev(nullptr);
            head = head->getNext();
        }
        else head = nullptr;
        delete curr;
    }
    else {
        while (curr != nullptr){
            if (curr->getVal() == val){
                curr->getPrev()->setNext(curr->getNext());
                if (curr->getNext() != nullptr) curr->getNext()->setPrev(curr->getPrev());
                delete curr;
                return this;
            }
            if (curr->getNext() != nullptr) curr = curr->getNext();
            else throw std::invalid_argument("Element does not exist in this list.");
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
        while (nextPointer != nullptr && nextPointer->getVal() != element){
            nextPointer = nextPointer->getNext();
            i++;
        }
        if (nextPointer == nullptr) return -1;
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
    if (head == nullptr){
        addBack(val);
        return this;
    }
    DoublyLinkedNode* prev = head;
    prev = getNodeAt(index-1);
    if (prev != nullptr) {
        DoublyLinkedNode* nodeAtIndex = prev->getNext();
        if (nodeAtIndex == nullptr) {
            prev->setNext(newElement);
            newElement->setPrev(prev);
            return this;
        }
        else {
            if (nodeAtIndex == head) {
                newElement->setNext(head->getNext());
                head->setPrev(newElement);
                head = newElement;
                return this;
            }
            newElement->setPrev(nodeAtIndex->getPrev());
            newElement->setNext(nodeAtIndex);
            nodeAtIndex->getPrev()->setNext(newElement);
            nodeAtIndex->setPrev(newElement);
            return this;
        }
    }
    return nullptr;
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

DoublyLinkedList::~DoublyLinkedList() {
    hardDelete(head);
}

void DoublyLinkedList::hardDelete(DoublyLinkedNode *node) {
    if (node == nullptr) return;
    DoublyLinkedNode *element = getLastElement();
    while (element != head) {
        element->getPrev()->setNext(nullptr);
        delete element;
        element = getLastElement();
    }
    delete head;
}

void DoublyLinkedList::printFromStart() {
    if (this->head == nullptr) return;
    DoublyLinkedNode * node = head;

    while (node->getNext() != nullptr){
        cout<<node->getVal()<<" ";
        node = node->getNext();
    }
    cout<<node->getVal()<<" ";
    cout<<endl;
}

void DoublyLinkedList::printFromEnd() {
    if (this->head == nullptr) return;
    DoublyLinkedNode * node = getLastElement();

    while (node->getPrev() != nullptr){
        cout<<node->getVal()<<" ";
        node = node->getPrev();
    }
    cout<<node->getVal()<<" ";
    cout<<endl;
}
