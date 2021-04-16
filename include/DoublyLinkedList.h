//
// Created by Władysław Nowak on 29/03/2021.
//

#ifndef SDIZO1_DOUBLYLINKEDLIST_H
#define SDIZO1_DOUBLYLINKEDLIST_H

#include <iostream>
#include "../src/DataStructures/helper-classes/DoublyLinkedNode.h"

using namespace std;

class DoublyLinkedList {
public:
    /**
     * Find an element in this list, return -1 if element does not exist.
     * @param element Element to look for.
     * @return Index of this element, -1 if element is not present.
     */
    int indexOf(int element);

    /**
     * Add element at the front of the list.
     * @param val value to be added.
     * @return Instance of this list.
     */
    DoublyLinkedList* addFront(int val);

    /**
     * Add new element at the back of the list.
     * @param val Value to be added.
     * @return Instance of this list.
     */
    DoublyLinkedList* addBack(int val);

    /**
     * Add new element to list at index passed as parameter.
     * It causes all following elements to shift by one by index
     * to give space for this element.
     * @param index
     * @param val
     * @return Instance of this list.
     */
    DoublyLinkedList* addAtIndex(int index, int val);

    /**
     * Remove first occurrence of an element from the list.
     * @param val Element to get rid of.
     * @return Instance of this list.
     */
    DoublyLinkedList* removeElement(int val);

    /**
     * Get element located at given index.
     * @param index Index of this element.
     * @return Value located at this index, return nullptr if index is not correct.
     */
    int get(int index);

    /**
     * Get size of this list.
     * @return The size in integer.
     */
    int getSize();

    /**
     * Unallocate all space taken up by this object.
     */
    ~DoublyLinkedList();

private:
    /**
     * First element of this list.
     */
    DoublyLinkedNode* head = nullptr;
    /**
     * Get last element in the list.
     * @return The element.
     */
     DoublyLinkedNode* getLastElement();

     /**
      * Get address of a node located at index.
      * @param i Index of this node.
      * @return The node located at this index.
      */
     DoublyLinkedNode* getNodeAt(int i);

     /**
      * Delete all nodes starting from this one.
      * @param node Node to start deletion from.
      */
     void hardDelete(DoublyLinkedNode* node);

};


#endif //SDIZO1_DOUBLYLINKEDLIST_H
