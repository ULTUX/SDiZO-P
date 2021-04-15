//
// Created by Wladyslaw Nowak on 15.04.2021.
//

#include "Benchmark.h"
#include "IO/CSVWriter.h"

Benchmark::Benchmark(BenchmarkType type, bool writeToFile,int initialSize, int step, int multiplier, int testNumber, int maxSize)
                     : type(type), isWriteToFile(writeToFile), initialSize(initialSize),
                       step(step), multiplier(multiplier), testNumber(testNumber), maxSize(maxSize){
    cout<<"Starting benchmark..."<<endl;
    performanceCounter = new LARGE_INTEGER;
    random_device rd;
    mt19937 mt(rd());
    uniform_int_distribution<int> dist(-10000000, 10000000);
    numberDistribution = dist;
    randNumGen = mt;
    calcIterationNumber();
    switch (type) {
        case BST_T: testBST();
        case DoublyLinkedList_T: testDoublyLinkedList();
        case DynamicArray_T: testDynamicArray();
        case Heap_T: testHeap();
        case RBTree_T: testRBTree();
    }
}


void Benchmark::testDoublyLinkedList() {

}

void Benchmark::testDynamicArray() {

}

void Benchmark::testHeap() {

}

void Benchmark::testRBTree() {
    cout<<"Testing RBTree element insertion (max size: "<<maxSize<<", iterations: "<<iterationNumber<<", step: "<<step
        <<", multiplier: "<<multiplier<<", starting size: "<<initialSize<<endl;
    Sleep(2000);
    //Test adding
    int sizeArray[iterationNumber];
    double resultsArray[iterationNumber];
    //Adding benchmark
    int size = initialSize;
    for (int i = 0; i < iterationNumber; i++){
        rbTree = new RBTree();
        //Sizes
        double avg = 0;
        for (int j = 0; j < testNumber; j++){
            int randomSet[size];
            generatePopulation(randomSet, size);
            startTimer();
            for (int k = 0; k < size; k++){
                rbTree->add(randomSet[k]);
            }
            avg += stopTimer();
        }
        avg /= testNumber;
        sizeArray[i] = size;
        resultsArray[i] = avg;
        size *= multiplier;
        size += step;
        delete rbTree;
        cout<<"RB tree insertion: Done "<<i<<" out of "<<iterationNumber<<" size: "<<size<<" took "<<resultsArray[i]<<"ms."<<endl;
    }
    if (isWriteToFile){
        writeToFile("RB_TREE_ADD", resultsArray, sizeArray);
    }


    //removing
    sizeArray[iterationNumber];
    resultsArray[iterationNumber];
    //Adding benchmark
    size = initialSize;
    for (int i = 0; i < iterationNumber; i++){
        rbTree = new RBTree();
        //Sizes
        double avg = 0;
        for (int j = 0; j < testNumber; j++){
            int randomSet[size];
            generatePopulation(randomSet, size);
            for (int k = 0; k < size; k++){
                rbTree->add(randomSet[k]);
            }
            shuffle(randomSet, &randomSet[size-1], std::mt19937(std::random_device()()));
            startTimer();
            for (int k = 0; k < size; k++){
                rbTree->remove(randomSet[k]);
            }
            avg += stopTimer();
        }
        avg /= testNumber;
        sizeArray[i] = size;
        resultsArray[i] = avg;
        size *= multiplier;
        size += step;
        delete rbTree;
        cout<<"RB tree insertion: Done "<<i<<" out of "<<iterationNumber<<" size: "<<size<<" took "<<resultsArray[i]<<"ms."<<endl;
    }
    if (isWriteToFile){
        writeToFile("RB_TREE_ADD", resultsArray, sizeArray);
    }
}



void Benchmark::testBST() {
    cout<<"Testing BST element insertion (max size: "<<maxSize<<", iterations: "<<iterationNumber<<", step: "<<step
    <<", multiplier: "<<multiplier<<", starting size: "<<initialSize<<endl;
    Sleep(2000);
    //Test adding
    int sizeArray[iterationNumber];
    double resultsArray[iterationNumber];
    //Adding benchmark
    int size = initialSize;
    for (int i = 0; i < iterationNumber; i++){
        bst = new BST();
        //Sizes
        double avg = 0;
        for (int j = 0; j < testNumber; j++){
            int randomSet[size];
            generatePopulation(randomSet, size);
            startTimer();
            for (int k = 0; k < size; k++){
                bst->add(randomSet[k]);
            }
            avg += stopTimer();
        }
        avg /= testNumber;
        sizeArray[i] = size;
        resultsArray[i] = avg;
        size *= multiplier;
        size += step;
        delete bst;
        cout<<"BST insertion: Done "<<i<<" out of "<<iterationNumber<<" size: "<<size<<" took "<<resultsArray[i]<<"ms."<<endl;
    }
    if (isWriteToFile){
        writeToFile("BST_ADD", resultsArray, sizeArray);
    }

    //Removing
    cout<<"Testing BST element deletion"<<endl;
    size = initialSize;
    for (int i = 0; i < iterationNumber; i++){
        bst = new BST();
        //Sizes
        double avg = 0;
        for (int j = 0; j < testNumber; j++){
            int randomSet[size];
            generatePopulation(randomSet, size);
            //Fill BSt with random data
            for (int k = 0; k < size; k++){
                bst->add(randomSet[k]);
            }
            shuffle(randomSet, &randomSet[size-1], std::mt19937(std::random_device()()));
            startTimer();
            for (int k = 0; k < size; k++){
                bst->remove(randomSet[k]);
            }
            avg += stopTimer();
        }
        avg /= testNumber;
        sizeArray[i] = size;
        resultsArray[i] = avg;
        size *= multiplier;
        size += step;
        delete bst;
        cout<<"BST deletion: Done "<<i<<" out of "<<iterationNumber<<" size: "<<size<<" took "<<resultsArray[i]<<"ms."<<endl;
    }
    if (isWriteToFile){
        writeToFile("BST_REMOVE", resultsArray, sizeArray);
    }

    //Searching
    cout<<"Testing BST element searching"<<endl;
    size = initialSize;
    for (int i = 0; i < iterationNumber; i++){
        bst = new BST();
        //Sizes
        double avg = 0;
        for (int j = 0; j < testNumber; j++){
            int randomSet[size];
            generatePopulation(randomSet, size);
            //Fill BSt with random data
            for (int k = 0; k < size; k++){
                bst->add(randomSet[k]);
            }
            startTimer();
            for (int k = 0; k < size; k++){
                bst->search(randomSet[k]);
            }
            avg += stopTimer();
        }
        avg /= testNumber;
        sizeArray[i] = size;
        resultsArray[i] = avg;
        size *= multiplier;
        size += step;
        delete bst;
        cout<<"BST search: Done "<<i<<" out of "<<iterationNumber<<" size: "<<size<<" took "<<resultsArray[i]<<"ms."<<endl;
    }
    if (isWriteToFile){
        writeToFile("BST_SEARCH", resultsArray, sizeArray);
    }
    //DSW Fix
    cout<<"Testing BST DSW fixing"<<endl;
    size = initialSize;
    for (int i = 0; i < iterationNumber; i++){
        bst = new BST();
        //Sizes
        double avg = 0;
        for (int j = 0; j < testNumber; j++){
            int randomSet[size];
            generatePopulation(randomSet, size);
            //Fill BSt with random data
            for (int k = 0; k < size; k++){
                bst->add(randomSet[k]);
            }
            startTimer();
            bst->fixDSW();
            avg += stopTimer();
        }
        avg /= testNumber;
        sizeArray[i] = size;
        resultsArray[i] = avg;
        size *= multiplier;
        size += step;
        delete bst;
        cout<<"BST fix DSW: Done "<<i<<" out of "<<iterationNumber<<" size: "<<size<<" took "<<resultsArray[i]<<"ms."<<endl;
    }
    if (isWriteToFile){
        writeToFile("BST_SEARCH", resultsArray, sizeArray);
    }
}



void Benchmark::calcIterationNumber() {
    int size = initialSize;

    int itNumber = 0;

    while (size < maxSize){
        size *= multiplier;
        size += step;
        itNumber++;
    }
    if (size > maxSize) itNumber--;
    this->iterationNumber = itNumber;
}

void Benchmark::writeToFile(string testName, double *data, int *size) {
    auto** toWrite = new double*[2];
    toWrite[0] = new double[iterationNumber];
    toWrite[1] = new double[iterationNumber];

    for (int i = 0; i < iterationNumber; i++){
        toWrite[0][i] = size[i];
        toWrite[1][i] = data[i];
    }
    string headers[2];
    headers[0] =  "Struc size";
    headers[1] =  "Time [ms]";
    CSVWriter writer(testName.append(".csv"), iterationNumber, 2, headers, toWrite);

}

int Benchmark::getNextRandom() {
    return numberDistribution(randNumGen);
}

void Benchmark::generatePopulation(int *dataSet, int size) {
    for (int i = 0; i < size; i++){
        dataSet[i] = getNextRandom();
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
    double timeInMs = (1000.0*elapsed)/freq.QuadPart;
    return timeInMs;

}

