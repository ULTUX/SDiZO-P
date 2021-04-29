//
// Created by Władysław Nowak on 29/03/2021.
//

#ifndef SDIZO1_HEAP_H
#define SDIZO1_HEAP_H
#include "DynamicArray.h"

/**
 * Max-heap built using dynamic array.
 */
class Heap {
public:
    /**
     * Add new element to the heap and fixes the heap going up.
     * @param val Element to be added.
     */
    void add(int val);

    /**
     * Remove heap's root and return it. This function fixes the heap going down from the root.
     * @return Removed element.
     * @throws length_error When heap is already empty.
     */
    int remove();

    /**
     * Get current size of the heap.
     * @return The size as integer number.
     */
    int getSize();

    /**
     * Nicely printFromBeginning the heap.
     */
    void print();

    Heap();

    /**
     * Unallocate all space taken up by this object.
     */
    ~Heap();

    /**
     * Search of an element.
     * @param val Element to be searched.
     * @return Whether this heap contains given element.
     */
    bool search(int val);
private:
    /**
     * Instance of array which stores all heap data.
     */
    DynamicArray * array;

    /**
     * Fix the heap going up from given index.
     * @param index Index of first element to be fixed.
     */
    void heapifyUp(int index);

    /**
     * Fix the heap going down from given index.
     * @param index Index to start fixing the heap from.
     */
    void heapifyDown(int index);

    /**
     * Try to find element at this index's subtree. This function could be used recursively.
     * @param val Value to be found.
     * @param index Index to start search from.
     * @return Whether this element is in this subtree.
     */
    bool findElement(int val, int index);

};


#endif //SDIZO1_HEAP_H
