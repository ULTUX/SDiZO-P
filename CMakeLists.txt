cmake_minimum_required(VERSION 3.17)
project(SDiZO1)

set(CMAKE_CXX_STANDARD 14)

add_executable(SDiZO1 main.cpp DynamicArray/DynamicArray.cpp DynamicArray/DynamicArray.h DoublyLinkedList/DoublyLinkedList.cpp DoublyLinkedList/DoublyLinkedList.h DoublyLinkedList/DoublyLinkedNode.cpp DoublyLinkedList/DoublyLinkedNode.h Heap/Heap.cpp Heap/Heap.h BST/BST.cpp BST/BST.h)