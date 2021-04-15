#include "IO/FileReader.h"
#include "IO/CSVWriter.h"
#include "Benchmark.h"

int main() {
    Benchmark bench(RBTree_T, true, 2, 50, 1.0, 1, 10000);
    return 0;
}
