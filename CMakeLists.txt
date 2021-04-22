cmake_minimum_required(VERSION 3.17)
project(SDiZO1)

set(CMAKE_CXX_STANDARD 14)

add_executable(SDiZO1 src/main.cpp src/DataStructures/DynamicArray.cpp include/DynamicArray.h src/DataStructures/DoublyLinkedList.cpp include/DoublyLinkedList.h src/DataStructures/helper-classes/DoublyLinkedNode.cpp src/DataStructures/helper-classes/DoublyLinkedNode.h src/DataStructures/Heap.cpp include/Heap.h src/DataStructures/helper-classes/BSTNode.cpp src/DataStructures/helper-classes/BSTNode.h src/DataStructures/helper-classes/RBNode.cpp src/DataStructures/helper-classes/RBNode.h src/DataStructures/RBTree.cpp include/RBTree.h src/IO/FileReader.cpp src/IO/FileReader.h src/DataStructures/BST.cpp include/BST.h src/Benchmark.cpp include/Benchmark.h src/IO/CSVWriter.cpp src/IO/CSVWriter.h src/Menu.cpp src/Menu.h include/StructureType.h)