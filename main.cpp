#include <iostream>
#include "DynamicArray/DynamicArray.h"
#include "DoublyLinkedList/DoublyLinkedList.h"
using namespace std;
int main() {
    DoublyLinkedList list;
    list.addBack(20)->addBack(10)->addBack(40)->addBack(100)->addFront(1230);

    list.addAtIndex(0, 20);

    for (int i = 0; i < list.getSize(); i++){
        cout<<list.get(i)<<" ";
    }
    cout<<endl;
    return 0;
}
