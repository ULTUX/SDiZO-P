//
// Created by Wladyslaw Nowak on 11/04/2021.
//

#include "../include/FileReader.h"

void FileReader::readToBST(BST *dest) {
    for (int i = 0; i < structureSize; i++){
        dest->add(readNextVal());
    }
}

void FileReader::readToDoublyLinkedList(DoublyLinkedList *dest, PushType type) {
    if (type == BACK){
        for (int i = 0; i < structureSize; i++){
            dest->addBack(readNextVal());
        }
    }
    else if (type == FRONT){
        for (int i = 0; i < structureSize; i++){
            dest->addFront(readNextVal());
        }
    }
}

void FileReader::readToDynamicArray(DynamicArray *dest, PushType type) {
    if (type == BACK){
        for (int i = 0; i < structureSize; i++){
            dest->addBack(readNextVal());
        }
    }
    else if (type == FRONT){
        for (int i = 0; i < structureSize; i++){
            dest->addFront(readNextVal());
        }
    }
}

void FileReader::readToHeap(Heap *dest) {
    for (int i = 0; i < structureSize; i++){
        dest->add(readNextVal());
    }
}

void FileReader::readToRBTree(RBTree *dest) {
    for (int i = 0; i < structureSize; i++){
        dest->add(readNextVal());
    }
}

int FileReader::readNextVal() {
    int nextVal;
    if (input.is_open()){
        input>>nextVal;
        if (input.fail()) {
            cerr<<"File error - stopping program"<<endl;
            exit(-1);
        }
        if (input.eof()) {
            input.close();
        }
        return nextVal;
    }
    cout<<"File not opened - maybe it was already closed?"<<endl;
    return 0;
}

FileReader::FileReader(std::string fileName):fileName(fileName), input(fileName){
    input>>structureSize;
    if (!input.is_open()){
        cerr<<"Could not open the file.";
        exit(-200);
    }
    cout<<"Structure size is: "<<structureSize<<endl;
}

int FileReader::getStructureSize() const {
    return structureSize;
}
