//
// Created by Władysław Nowak on 29/03/2021.
//

#ifndef SDIZO1_DOUBLYLINKEDNODE_H
#define SDIZO1_DOUBLYLINKEDNODE_H

/**
 * This is a class representing single element that's in DoublyLinkedList.
 */
class DoublyLinkedNode {
    public:
        DoublyLinkedNode(int val);
        void setNext(DoublyLinkedNode* elementDk);
        void setPrev(DoublyLinkedNode* elementDk);
        DoublyLinkedNode* getNext();
        DoublyLinkedNode* getPrev();
        int getVal();
    private:
        DoublyLinkedNode* next = nullptr;
        DoublyLinkedNode* prev = nullptr;
        int value;
};


#endif //SDIZO1_DOUBLYLINKEDNODE_H
