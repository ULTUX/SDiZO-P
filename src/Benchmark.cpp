//
// Created by Wladyslaw Nowak on 15.04.2021.
//

#include "../include/Benchmark.h"
#include "IO/CSVWriter.h"

Benchmark::Benchmark(StructureType type, bool writeToFile, int initialSize, int step, float multiplier, int testNumber,
                     int maxSize)
        : type(type), isWriteToFile(writeToFile), initialSize(initialSize),
          step(step), multiplier(multiplier), testNumber(testNumber), maxSize(maxSize) {
    cout << "Starting benchmark:" << endl;
    cout<<"\ttype: "<<type<<endl;
    cout<<"\twrite to file: "<<writeToFile<<endl;
    cout<<"\tinitial size: "<<initialSize<<endl;
    cout<<"\tstep: "<<step<<endl;
    cout<<"\tmultiplier: "<<multiplier<<endl;
    cout<<"\ttest number: "<<testNumber<<endl;
    cout<<"\tmax size: "<<maxSize<<endl;

    performanceCounter = new LARGE_INTEGER;
    random_device rd;
    mt19937 mt(rd());
    uniform_int_distribution<int> dist(-10000000, 10000000);
    randNumGen = mt;
    calcIterationNumber();
    switch (type) {
        case BST_T: {
            testBST();
            break;
        }
        case DoublyLinkedList_T: {
            testDoublyLinkedList();
            break;
        }
        case DynamicArray_T: {
            testDynamicArray();
            break;
        }
        case Heap_T: {
            testHeap();
            break;
        }
        case RBTree_T: {
            testRBTree();
            break;
        }
    }
}


void Benchmark::testDoublyLinkedList() {
    cout << "Testing doubly linked list (max size: " << maxSize << ", iterations: " << iterationNumber << ", step: " << step
         << ", multiplier: " << multiplier << ", starting size: " << initialSize << endl;
    Sleep(2000);
    //Test adding back
    int sizeArray[iterationNumber];
    double resultsArray[iterationNumber];
    //Adding benchmark
    int size = initialSize;
    for (int i = 0; i < iterationNumber; i++) {
        double avg = 0;
        int* randomSet = new int[size+1];
        for (int j = 0; j < testNumber; j++) {
            DoublyLinkedList* doublyLinkedList = new DoublyLinkedList();
            generatePopulation(randomSet, size+1, numberDistribution);
            for (int k = 0; k < size; k++) {
                doublyLinkedList->addBack(randomSet[k]);
            }
            startTimer();
            doublyLinkedList->addBack(randomSet[size]);
            avg += stopTimer();
            delete doublyLinkedList;
        }
        delete[] randomSet;
        avg /= testNumber;
        sizeArray[i] = size;
        resultsArray[i] = avg;
        cout << "Doubly linked list back insertion: Done " << i+1 << " out of " << iterationNumber << " size: " << size << " took "
             << resultsArray[i] << "us." << endl;
        size *= multiplier;
        size += step;
    }
    if (isWriteToFile) {
        writeToFile("DOUBLY_LINKED_LIST_INSERT_BACK", resultsArray, sizeArray);
    }

    //Insert front
    size = initialSize;
    for (int i = 0; i < iterationNumber; i++) {
        double avg = 0;
        int* randomSet = new int[size+1];
        for (int j = 0; j < testNumber; j++) {
            DoublyLinkedList* doublyLinkedList = new DoublyLinkedList();
            generatePopulation(randomSet, size+1, numberDistribution);
            for (int k = 0; k < size; k++) {
                doublyLinkedList->addFront(randomSet[k]);
            }
            startTimer();
            doublyLinkedList->addFront(randomSet[size]);
            avg += stopTimer();
            delete doublyLinkedList;
        }
        delete[] randomSet;
        avg /= testNumber;
        sizeArray[i] = size;
        resultsArray[i] = avg;
        cout << "Doubly linked list front insertion: Done " << i+1 << " out of " << iterationNumber << " size: " << size << " took "
             << resultsArray[i] << "us." << endl;
        size *= multiplier;
        size += step;
    }
    if (isWriteToFile) {
        writeToFile("DOUBLY_LINKED_LIST_INSERT_FRONT", resultsArray, sizeArray);
    }

    //Insert at index
    size = initialSize;
    for (int i = 0; i < iterationNumber; i++) {
        double avg = 0;
        int* randomSet = new int[size+1];
        for (int j = 0; j < testNumber; j++) {
            DoublyLinkedList* doublyLinkedList = new DoublyLinkedList();
            generatePopulation(randomSet, size+1, numberDistribution);
            for (int k = 0; k < size; k++) {
                doublyLinkedList->addAtIndex(k, randomSet[k]);
            }
            startTimer();
            doublyLinkedList->addAtIndex(size, randomSet[size]);
            avg += stopTimer();
            delete doublyLinkedList;
        }
        delete[] randomSet;
        avg /= testNumber;
        sizeArray[i] = size;
        resultsArray[i] = avg;
        cout << "Doubly linked list at index insertion: Done " << i+1 << " out of " << iterationNumber << " size: " << size << " took "
             << resultsArray[i] << "us." << endl;
        size *= multiplier;
        size += step;
    }
    if (isWriteToFile) {
        writeToFile("DOUBLY_LINKED_LIST_INSERT_INDEX", resultsArray, sizeArray);
    }

    //remove
    size = initialSize;
    for (int i = 0; i < iterationNumber; i++) {
        double avg = 0;
        int* randomSet = new int[size];
        for (int j = 0; j < testNumber; j++) {
            DoublyLinkedList* doublyLinkedList = new DoublyLinkedList();
            generatePopulation(randomSet, size, numberDistribution);
            for (int k = 0; k < size; k++){
                doublyLinkedList->addBack(randomSet[k]);
            }
            shuffle(randomSet, &randomSet[size-1], std::mt19937(std::random_device()()));
            startTimer();
            doublyLinkedList->removeElement(randomSet[size-1]);
            avg += stopTimer();
            delete doublyLinkedList;
        }
        delete[] randomSet;
        avg /= testNumber;
        sizeArray[i] = size;
        resultsArray[i] = avg;
        cout << "Doubly linked list removal: Done " << i+1 << " out of " << iterationNumber << " size: " << size << " took "
             << resultsArray[i] << "us." << endl;
        size *= multiplier;
        size += step;
    }
    if (isWriteToFile) {
        writeToFile("DOUBLY_LINKED_LIST_REMOVE", resultsArray, sizeArray);
    }

    //Search
    size = initialSize;
    for (int i = 0; i < iterationNumber; i++) {
        //Sizes
        double avg = 0;
        int* randomSet = new int[size];
        for (int j = 0; j < testNumber; j++) {
            DoublyLinkedList* doublyLinkedList = new DoublyLinkedList();
            generatePopulation(randomSet, size, numberDistribution);
            for (int k = 0; k < size; k++){
                doublyLinkedList->addBack(randomSet[k]);
            }
            shuffle(randomSet, &randomSet[size-1], std::mt19937(std::random_device()()));
            startTimer();
            doublyLinkedList->indexOf(randomSet[size-1]);
            avg += stopTimer();
            delete doublyLinkedList;
        }
        delete[] randomSet;
        avg /= testNumber;
        sizeArray[i] = size;
        resultsArray[i] = avg;
        cout << "Doubly linked list at index retrieval: Done " << i+1 << " out of " << iterationNumber << " size: " << size << " took "
             << resultsArray[i] << "us." << endl;
        size *= multiplier;
        size += step;
    }
    if (isWriteToFile) {
        writeToFile("DOUBLY_LINKED_LIST_SEARCH", resultsArray, sizeArray);
    }
}

void Benchmark::testDynamicArray() {
    cout << "Testing dynamic array (max size: " << maxSize << ", iterations: " << iterationNumber << ", step: " << step
         << ", multiplier: " << multiplier << ", starting size: " << initialSize << endl;
    Sleep(2000);

    int sizeArray[iterationNumber];
    double resultsArray[iterationNumber];
    //Adding benchmark
    int size = initialSize;
    for (int i = 0; i < iterationNumber; i++) {
        double avg = 0;
        int* randomSet = new int[size+1];
        for (int j = 0; j < testNumber; j++) {
            DynamicArray* dynamicArray = new DynamicArray();
            generatePopulation(randomSet, size+1, numberDistribution);
            for (int k = 0; k < size; k++) {
                dynamicArray->addBack(randomSet[k]);
            }
            startTimer();
            dynamicArray->addBack(randomSet[size]);
            avg += stopTimer();
            delete dynamicArray;
        }
        delete[] randomSet;
        avg /= testNumber;
        sizeArray[i] = size;
        resultsArray[i] = avg;
        cout << "Dynamic array back insertion: Done " << i+1 << " out of " << iterationNumber << " size: " << size << " took "
             << resultsArray[i] << "us." << endl;
        size *= multiplier;
        size += step;
    }
    if (isWriteToFile) {
        writeToFile("DYNAMIC_ARRAY_INSERT_BACK", resultsArray, sizeArray);
    }

    //Test adding front
    size = initialSize;
    for (int i = 0; i < iterationNumber; i++) {
        double avg = 0;
        int* randomSet = new int[size+1];
        for (int j = 0; j < testNumber; j++) {
            DynamicArray* dynamicArray = new DynamicArray();
            generatePopulation(randomSet, size+1, numberDistribution);
            for (int k = 0; k < size; k++) {
                dynamicArray->addFront(randomSet[k]);
            }
            startTimer();
            dynamicArray->addFront(randomSet[size]);
            avg += stopTimer();
            delete dynamicArray;
        }
        delete[] randomSet;
        avg /= testNumber;
        sizeArray[i] = size;
        resultsArray[i] = avg;
        cout << "Dynamic array front insertion: Done " << i+1 << " out of " << iterationNumber << " size: " << size << " took "
             << resultsArray[i] << "us." << endl;
        size *= multiplier;
        size += step;
    }
    if (isWriteToFile) {
        writeToFile("DYNAMIC_ARRAY_INSERT_FRONT", resultsArray, sizeArray);
    }


    //Test adding at index
    size = initialSize;
    for (int i = 0; i < iterationNumber; i++) {
        double avg = 0;
        int* randomSet = new int[size+1];
        for (int j = 0; j < testNumber; j++) {
            DynamicArray* dynamicArray = new DynamicArray();
            generatePopulation(randomSet, size+1, numberDistribution);
            for (int k = 0; k < size; k++) {
                dynamicArray->addAtIndex(randomSet[k], k);
            }
            startTimer();
            dynamicArray->addAtIndex(randomSet[size], size);
            avg += stopTimer();
            delete dynamicArray;
        }
        delete[] randomSet;
        avg /= testNumber;
        resultsArray[i] = avg;
        sizeArray[i] = size;
        cout << "Dynamic array at index insertion: Done " << i+1 << " out of " << iterationNumber << " size: " << size << " took "
             << resultsArray[i] << "us." << endl;
        size *= multiplier;
        size += step;
    }
    if (isWriteToFile) {
        writeToFile("DYNAMIC_ARRAY_INSERT_INDEX", resultsArray, sizeArray);
    }
    //Removing
    size = initialSize;
    for (int i = 0; i < iterationNumber; i++) {
        double avg = 0;
        int* randomSet = new int[size];
        for (int j = 0; j < testNumber; j++) {
            DynamicArray* dynamicArray = new DynamicArray();
            generatePopulation(randomSet, size, numberDistribution);
            for (int k = 0; k < size; k++){
                dynamicArray->addBack(randomSet[k]);
            }
            shuffle(randomSet, &randomSet[size-1], std::mt19937(std::random_device()()));
            startTimer();
            dynamicArray->remove(randomSet[size-1]);
            avg += stopTimer();
            delete dynamicArray;
        }
        delete[] randomSet;
        avg /= testNumber;
        sizeArray[i] = size;
        resultsArray[i] = avg;
        cout << "Dynamic array removal: Done " << i+1 << " out of " << iterationNumber << " size: " << size << " took "
             << resultsArray[i] << "us." << endl;
        size *= multiplier;
        size += step;
    }
    if (isWriteToFile) {
        writeToFile("DYNAMIC_ARRAY_REMOVE", resultsArray, sizeArray);
    }
}

void Benchmark::testHeap() {
    cout << "Testing Heap (max size: " << maxSize << ", iterations: " << iterationNumber << ", step: " << step
         << ", multiplier: " << multiplier << ", starting size: " << initialSize << endl;
    Sleep(2000);
    //Test adding
    int sizeArray[iterationNumber];
    double resultsArray[iterationNumber];
    //Adding benchmark
    int size = initialSize;
    for (int i = 0; i < iterationNumber; i++) {
        double avg = 0;
        int* randomSet = new int[size+1];
        for (int j = 0; j < testNumber; j++) {
            Heap* heap = new Heap();
            generatePopulation(randomSet, size+1, numberDistribution);
            for (int k = 0; k < size; k++) {
                heap->add(randomSet[k]);
            }
            startTimer();
            heap->add(randomSet[size]);
            avg += stopTimer();
            delete heap;
        }
        delete[] randomSet;
        avg /= testNumber;
        sizeArray[i] = size;
        resultsArray[i] = avg;
        cout << "Heap insertion: Done " << i+1 << " out of " << iterationNumber << " size: " << size << " took "
             << resultsArray[i] << "us." << endl;
        size *= multiplier;
        size += step;
    }
    if (isWriteToFile) {
        writeToFile("HEAP_ADD", resultsArray, sizeArray);
    }

//    remove
    size = initialSize;
    for (int i = 0; i < iterationNumber; i++) {
        double avg = 0;
        int* randomSet = new int[size+1];
        for (int j = 0; j < testNumber; j++) {
            Heap* heap = new Heap();
            generatePopulation(randomSet, size+1, numberDistribution);
            for (int k = 0; k < size; k++){
                heap->add(randomSet[k]);
            }
            startTimer();
            heap->remove();
            avg += stopTimer();
            delete heap;
        }
        delete[] randomSet;
        avg /= testNumber;
        sizeArray[i] = size;
        resultsArray[i] = avg;
        cout << "Heap removal: Done " << i+1 << " out of " << iterationNumber << " size: " << size << " took "
             << resultsArray[i] << "us." << endl;
        size *= multiplier;
        size += step;
    }
    if (isWriteToFile) {
        writeToFile("HEAP_REMOVE", resultsArray, sizeArray);
    }
}

void Benchmark::testRBTree() {
    cout << "Testing RBTree (max size: " << maxSize << ", iterations: " << iterationNumber << ", step: " << step
         << ", multiplier: " << multiplier << ", starting size: " << initialSize << endl;
    Sleep(2000);

    int sizeArray[iterationNumber];
    double resultsArray[iterationNumber];
    //Adding benchmark
    int size = initialSize;
    for (int i = 0; i < iterationNumber; i++) {
        double avg = 0;
        int* randomSet = new int[size+1];
        for (int j = 0; j < testNumber; j++) {
            RBTree* rbTree = new RBTree();
            generatePopulation(randomSet, size+1, numberDistribution);
            for (int k = 0; k < size; k++) {
                rbTree->add(randomSet[k]);
            }
            startTimer();
            rbTree->add(randomSet[size]);
            avg += stopTimer();
            delete rbTree;
        }
        delete[] randomSet;
        avg /= testNumber;
        sizeArray[i] = size;
        resultsArray[i] = avg;
        cout << "RB tree insertion: Done " << i+1 << " out of " << iterationNumber << " size: " << size << " took "
             << resultsArray[i] << "us." << endl;
        size *= multiplier;
        size += step;
    }
    if (isWriteToFile) {
        writeToFile("RB_TREE_ADD", resultsArray, sizeArray);
    }


    //removing
    size = initialSize;
    for (int i = 0; i < iterationNumber; i++) {
        //Sizes
        double avg = 0;
        int* randomSet = new int[size];
        for (int j = 0; j < testNumber; j++) {
            RBTree* rbTree = new RBTree();
            generatePopulation(randomSet, size, numberDistribution);
            for (int k = 0; k < size; k++) {
                rbTree->add(randomSet[k]);
            }
            shuffle(randomSet, &randomSet[size-1], std::mt19937(std::random_device()()));
            startTimer();
            rbTree->remove(randomSet[size-1]);
            avg += stopTimer();
            delete rbTree;
        }
        delete[] randomSet;
        avg /= testNumber;
        sizeArray[i] = size;
        resultsArray[i] = avg;
        cout << "RB tree deletion: Done " << i+1 << " out of " << iterationNumber << " size: " << size << " took "
             << resultsArray[i] << "us." << endl;
        size *= multiplier;
        size += step;
    }
    if (isWriteToFile) {
        writeToFile("RB_TREE_REMOVE", resultsArray, sizeArray);
    }

    //searching
    size = initialSize;
    for (int i = 0; i < iterationNumber; i++) {
        //Sizes
        double avg = 0;
        int* randomSet = new int[size];
        for (int j = 0; j < testNumber; j++) {
            RBTree* rbTree = new RBTree();
            generatePopulation(randomSet, size, numberDistribution);
            for (int k = 0; k < size; k++) {
                rbTree->add(randomSet[k]);
            }
            shuffle(randomSet, &randomSet[size-1], std::mt19937(std::random_device()()));
            startTimer();
            rbTree->search(randomSet[size-1]);
            avg += stopTimer();
            delete rbTree;
        }
        delete[] randomSet;
        avg /= testNumber;
        sizeArray[i] = size;
        resultsArray[i] = avg;
        cout << "RB tree search: Done " << i+1 << " out of " << iterationNumber << " size: " << size << " took "
             << resultsArray[i] << "us." << endl;
        size *= multiplier;
        size += step;
    }
    if (isWriteToFile) {
        writeToFile("RB_TREE_SEARCH", resultsArray, sizeArray);
    }
}


void Benchmark::testBST() {
    cout << "Testing BST (max size: " << maxSize << ", iterations: " << iterationNumber << ", step: " << step
         << ", multiplier: " << multiplier << ", starting size: " << initialSize << endl;
    Sleep(2000);
    //Test adding
    int sizeArray[iterationNumber];
    double resultsArray[iterationNumber];
    //Adding benchmark
    int size = initialSize;
    for (int i = 0; i < iterationNumber; i++) {
        //Sizes
        double avg = 0;
        int *randomSet = new int[size+1];
        for (int j = 0; j < testNumber; j++) {
            BST* bst = new BST();
            generatePopulation(randomSet, size+1, numberDistribution);
            for (int k = 0; k < size; k++) {
                bst->add(randomSet[k]);
            }
            startTimer();
            bst->add(randomSet[size]);
            avg += stopTimer();
            delete bst;
        }
        delete[] randomSet;
        avg /= testNumber;
        sizeArray[i] = size;
        resultsArray[i] = avg;
        cout << "BST insertion: Done " << i+1 << " out of " << iterationNumber << " size: " << size << " took "
             << resultsArray[i] << "us." << endl;
        size *= multiplier;
        size += step;
    }
    if (isWriteToFile) {
        writeToFile("BST_ADD", resultsArray, sizeArray);
    }

    //Removing
    cout << "Testing BST element deletion" << endl;
    size = initialSize;
    for (int i = 0;i < iterationNumber; i++) {
        //Sizes
        double avg = 0;
        int * randomSet = new int[size];
        for (int j = 0; j < testNumber; j++) {
            BST* bst = new BST();
            generatePopulation(randomSet, size, numberDistribution);
            //Fill BST with random data
            for (int k = 0; k < size; k++) {
                bst->add(randomSet[k]);
            }
            shuffle(randomSet, &randomSet[size-1], std::mt19937(std::random_device()()));
            startTimer();
            bst->remove(randomSet[size-1]);
            avg += stopTimer();
            delete bst;
        }
        delete[] randomSet;
        avg /= testNumber;
        sizeArray[i] = size;
        resultsArray[i] = avg;
        cout << "BST deletion: Done " << i+1 << " out of " << iterationNumber << " size: " << size << " took "
             << resultsArray[i] << "us." << endl;
        size *= multiplier;
        size += step;
    }
    if (isWriteToFile) {
        writeToFile("BST_REMOVE", resultsArray, sizeArray);
    }

    //Searching
    cout << "Testing BST element searching" << endl;
    size = initialSize;
    for (int i = 0; i < iterationNumber; i++) {
        //Sizes
        double avg = 0;
        int * randomSet = new int[size+1];
        for (int j = 0; j < testNumber; j++) {
            BST* bst = new BST();
            generatePopulation(randomSet, size+1, numberDistribution);
            //Fill BSt with random data
            for (int k = 0; k < size; k++) bst->add(randomSet[k]);
            shuffle(randomSet, &randomSet[size], std::mt19937(std::random_device()()));
            startTimer();
            bst->search(randomSet[size]);
            avg += stopTimer();
            delete bst;

        }
        delete[] randomSet;
        avg /= testNumber;
        sizeArray[i] = size;
        resultsArray[i] = avg;
        cout << "BST search: Done " << i+1 << " out of " << iterationNumber << " size: " << size << " took "
             << resultsArray[i] << "us." << endl;
        size *= multiplier;
        size += step;
    }
    if (isWriteToFile) {
        writeToFile("BST_SEARCH", resultsArray, sizeArray);
    }
    //DSW Fix
    cout << "Testing BST DSW fixing" << endl;
    size = initialSize;
    for (int i = 0; i < iterationNumber; i++) {
        //Sizes
        double avg = 0;
        int * randomSet = new int[size];
        for (int j = 0; j < testNumber; j++) {
            BST* bst = new BST();
            generatePopulation(randomSet, size, numberDistribution);
            //Fill BSt with random data
            for (int k = 0; k < size; k++) {
                bst->add(randomSet[k]);
            }
            startTimer();
            bst->fixDSW();
            avg += stopTimer();
            delete bst;
        }
        delete[] randomSet;
        avg /= testNumber;
        sizeArray[i] = size;
        resultsArray[i] = avg;
        cout << "BST fix DSW: Done " << i+1 << " out of " << iterationNumber << " size: " << size << " took "
             << resultsArray[i] << "us." << endl;
        size *= multiplier;
        size += step;
    }
    if (isWriteToFile) {
        writeToFile("BST_FIX", resultsArray, sizeArray);
    }
}




void Benchmark::calcIterationNumber() {
    int size = initialSize;

    int itNumber = 0;

    while (size < maxSize) {
        size *= multiplier;
        size += step;
        itNumber++;
    }
    if (size > maxSize) itNumber--;
    this->iterationNumber = itNumber;
}

void Benchmark::writeToFile(string testName, double *data, int *size) const {
    auto **toWrite = new double *[2];
    toWrite[0] = new double[iterationNumber];
    toWrite[1] = new double[iterationNumber];

    for (int i = 0; i < iterationNumber; i++) {
        toWrite[0][i] = size[i];
        toWrite[1][i] = data[i];
    }
    string headers[2];
    headers[0] = "Struc size";
    headers[1] = "Time [us]";
    CSVWriter writer(testName.append(".csv"), iterationNumber, 2, headers, toWrite);

}

int Benchmark::getNextRandom(uniform_int_distribution<int>& dist) {
    return dist(randNumGen);
}

void Benchmark::generatePopulation(int *dataSet, int size, uniform_int_distribution<int> dist) {
    for (int i = 0; i < size; i++) {
        dataSet[i] = getNextRandom(dist);
    }
}

void Benchmark::startTimer() {
    LARGE_INTEGER count;
    QueryPerformanceCounter(&count);
    *performanceCounter = count;
}

double Benchmark::stopTimer() {
    LARGE_INTEGER count;
    QueryPerformanceCounter(&count);
    LARGE_INTEGER freq;
    QueryPerformanceFrequency(&freq);
    uint64_t elapsed = count.QuadPart - (*performanceCounter).QuadPart;
    double timeInNs = (1000000.0 * elapsed) / freq.QuadPart;
    return timeInNs;

}

uniform_int_distribution<int> Benchmark::getRandomInRange(int a, int b) {
    uniform_int_distribution<int> dist(a, b);
    return dist;
}
