#include "RBTree/RBTree.h"

using namespace std;

int main() {
    RBTree tree(5);

    tree.add(0);
    tree.add(1);
    tree.add(2);
    tree.add(3);
    tree.add(4);

    tree.remove(2);

    return 0;
}
