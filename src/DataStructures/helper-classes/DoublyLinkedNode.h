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
        /**
         * Create new DoublyLinkedNode with initial value.
         * @param val Value to be carried by this node.
         */
        DoublyLinkedNode(int val);

        /**
         * Set next node pointed by this node.
         * @param elementDk Node to be set as next.
         */
        void setNext(DoublyLinkedNode* elementDk);

        /**
         * Set previous node pointed by this node.
         * @param elementDk Node to be set as previous.
         */
        void setPrev(DoublyLinkedNode* elementDk);

        /**
         * Get next node.
         * @return Next node.
         */
        DoublyLinkedNode* getNext();

        /**
         * Get previous node.
         * @return Previous node.
         */
        DoublyLinkedNode* getPrev();

        /**
         * Get value carried by this node.
         * @return This node's value.
         */
        int getVal();
    private:
        /**
         * Pointer to next node.
         */
        DoublyLinkedNode* next = nullptr;

        /**
         * Pointer to prevoius node.
         */
        DoublyLinkedNode* prev = nullptr;

        /**
         * Value carried by this node.
         */
        int value;
};


#endif //SDIZO1_DOUBLYLINKEDNODE_H
