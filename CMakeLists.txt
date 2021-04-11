cmake_minimum_required(VERSION 3.17)
project(SDiZO1)

set(CMAKE_CXX_STANDARD 14)

add_executable(SDiZO1 src/main.cpp src/DataStructures/DynamicArray.cpp include/DynamicArray.h src/DataStructures/DoublyLinkedList.cpp include/DoublyLinkedList.h src/DataStructures/helper-classes/DoublyLinkedNode.cpp src/DataStructures/helper-classes/DoublyLinkedNode.h src/DataStructures/Heap.cpp include/Heap.h src/DataStructures/BST.cpp include/BST.h src/DataStructures/helper-classes/RBNode.cpp src/DataStructures/helper-classes/RBNode.h src/DataStructures/RBTree.cpp include/RBTree.h src/FileReader/FileReader.cpp src/FileReader/FileReader.h)