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
    int get(int index);
    /**
     * Replace value at index position with new value passed by a parameter.
     * @param index Index to be replaced.
     * @param val Replacement value.
     */
    void set(int index, int val);

    /**
     * Print contents of array from start to end to stdout .
     */
    void printFromBeginning();

    /**
     * Print contents of this array from end to start to stdout.
     */
    void printFromEnd();

    /**
     * Swap two array elements with each other.
     * @param i1 First element.
     * @param i2 Second element.
     */
    void swap(int i1, int i2);

    /**
     * Unallocate all space taken up by this object.
     */
    ~DynamicArray();

    /**
     * Check if this array contains given element.
     * @param val Element to be checked for existence.
     * @return True - element exists, false - doesn't exist
     */
    bool contains(int val);

    /**
     * Get index of given value.
     * @param val Value to be found.
     * @return Index of this value. If multiple equal values exist, return first one. If value doesn't exit, return -1;
     */
    int indexOf(int val);

};


#endif //SDIZO1_DYNAMICARRAY_H
