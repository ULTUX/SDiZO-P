#include "IO/FileReader.h"
#include "IO/CSVWriter.h"
#include "Benchmark.h"
int main() {
    Benchmark bench(DynamicArray_T, true, 2, 50000, 1.0, 1, 1000000);
//    Benchmark bench2(RBTree_T, true, 2500, 2500, 1.0, 5, 1000000);
//    Benchmark bench3(BST_T, true, 1, 100000, 1.0, 1, 3000000);
//    Benchmark bench4(Heap_T, true, 2, 50, 1.0, 1, 10000);
//    Benchmark bench5(DoublyLinkedList_T, true, 2, 50, 1.0, 1, 10000);
    return 0;
}
