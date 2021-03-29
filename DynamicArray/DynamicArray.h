//
// Created by Władysław Nowak on 27/03/2021.
//

#ifndef SDIZO1_DYNAMICARRAY_H
#define SDIZO1_DYNAMICARRAY_H


class DynamicArray {
private:
    /**
     * Pointer to an array.
     */
    int* arrayPointer;
    /**
     * Current size of an array.
     */
    int size = 0;
    /**
     * Initialize new array with an element.
     * @param element Element to be added to new array.
     */
    void initArray(int element);
public:
    /**
     * Add new element to front of dynamic array.
     * @param element Element to be added.
     */
    void addFront(int element);
    /**
     * Add element to back of dynamic array.
     * @param element Element to be added.
     */
    void addBack(int element);
    /**
     * Add element at the specified index.
     * @param element Element to be added.
     * @param index An index of this element.
     */
    void addAtIndex(int element, int index);
    /**
     * Remove element from dynamic array.
     * @param index Index of this element.
     * @return New size of an array.
     */
    int remove(int index);
    /**
     * Get current size of an array.
     * @return The size.
     */
    int getSize() const;
    /**
     * Get element at specified index.
     * @param index An index of this element.
     * @return Element on that index, -1 if index is wrong.
     */
    int getAtIndex(int index);
};


#endif //SDIZO1_DYNAMICARRAY_H
