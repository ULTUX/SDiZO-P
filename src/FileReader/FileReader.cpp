//
// Created by Wladyslaw Nowak on 11/04/2021.
//

#include "FileReader.h"

void FileReader::readToBST(BST *dest) {

}

void FileReader::readToDoublyLinkedList(DoublyLinkedList *dest) {

}

void FileReader::readToDynamicArray(DynamicArray *dest) {

}

void FileReader::readToHeap(Heap *dest) {

}

void FileReader::readToRBTree(RBTree *dest) {

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
