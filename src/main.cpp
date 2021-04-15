#include "IO/FileReader.h"
#include "IO/CSVWriter.h"
using namespace std;

int main() {
    BST bst(5);
    for (int i = 0; i < 10; i++){
        bst.add(i);
    }
    bst.rotateRight(bst.getRoot());

    bst.fixDSW();
    return 0;
}
