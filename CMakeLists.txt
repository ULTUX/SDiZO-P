cmake_minimum_required(VERSION 3.17)
project(SDiZO1)

set(CMAKE_CXX_STANDARD 14)

add_executable(SDiZO1 src/main.cpp src/DynamicArray/DynamicArray.cpp src/DynamicArray/DynamicArray.h src/DoublyLinkedList/DoublyLinkedList.cpp src/DoublyLinkedList/DoublyLinkedList.h src/DoublyLinkedList/DoublyLinkedNode.cpp src/DoublyLinkedList/DoublyLinkedNode.h src/Heap/Heap.cpp src/Heap/Heap.h src/BST/BST.cpp src/BST/BST.h src/RBTree/RBNode.cpp src/RBTree/RBNode.h src/RBTree/RBTree.cpp src/RBTree/RBTree.h)