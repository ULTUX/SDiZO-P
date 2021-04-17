//
// Created by bulio on 17.04.2021.
//

#include "Menu.h"
#include "../IO/FileReader.h"
#include "../Benchmark.h"

Menu::Menu() {
    printMainMenu();
}

void Menu::printMainMenu() {

    while (true){
        cout<<"Wybierz polecenie: "<<endl;
        cout<<"1. Uruchom testy"<<endl;
        cout<<"2. Zaladuj strukture z pliku"<<endl;
        cout<<"0. Wylacz program"<<endl;
        int input;
        cin>>input;
        switch (input) {
            case 1: {
                printBenchmarkMenu();
                break;
            }
            case 2: {
                printFileLoadMenu();
                break;
            }
            case 0: {
                cout<<"Wylaczanie programu..."<<endl;
                exit(0);
            }
            default: {
                cout<<"Nieznana komenda"<<endl;
                break;

            }
        }
    }
}

void Menu::printFileLoadMenu() {
    cout<<"Podaj rodzaj struktury: "<<endl;
    cout<<"\t1. BST"<<endl;
    cout<<"\t2. DoublyLinkedList"<<endl;
    cout<<"\t3. DynamicArray"<<endl;
    cout<<"\t4. Heap"<<endl;
    cout<<"\t5. RBTree"<<endl;
    int input;
    cin>>input;
    switch (input) {
        case 1: {
            type = BST_T;
            initBST();
            printBSTMenu();
            break;
        }
        case 2: {
            type = DoublyLinkedList_T;
            initDoublyLinkedList();
            printDoublyLinkedListMenu();
            break;
        }
        case 3: {
            type = DynamicArray_T;
            initDynamicArray();
            printDynamicArrayMenu();
            break;
        }
        case 4: {
            type = Heap_T;
            initHeap();
            printHeapMenu();
            break;
        }
        case 5: {
            type = RBTree_T;
            initRBTree();
            printRBTreeMenu();
            break;
        }
    }

}

void Menu::initBST() {
    cout<<"Podaj nazwe pliku, z ktorego chcesz pobrac dane do BST: ";
    string input;
    cin>>input;
    cout<<"Wczytywanie danych..."<<endl;
    try {
        FileReader reader(input);
        bst = new BST();
        reader.readToBST(bst);
        printBSTMenu();
    } catch (runtime_error& e){
        cout<<"Wystapil blad: "<<endl;
        cerr<<e.what()<<endl;
        initBST();
        return;
    }
}

void Menu::initDoublyLinkedList() {
    cout<<"Podaj nazwe pliku, z ktorego chcesz pobrac dane do BST: ";
    string input;
    cin>>input;
    cout<<"Wczytywanie danych..."<<endl;
    try {
        FileReader reader(input);
        bst = new BST();
        reader.readToBST(bst);
        printBSTMenu();
    } catch (runtime_error& e){
        cout<<"Wystapil blad: "<<endl;
        cerr<<e.what()<<endl;
        initBST();
        return;
    }
}

void Menu::initDynamicArray() {
    cout<<"Podaj nazwe pliku, z ktorego chcesz pobrac dane do DynamicArray: ";
    string input;
    cin>>input;
    cout<<"Wczytywanie danych..."<<endl;
    try {
        FileReader reader(input);
        dynamicArray = new DynamicArray();
        reader.readToDynamicArray(dynamicArray, BACK);
        printDynamicArrayMenu();
    } catch (runtime_error& e){
        cout<<"Wystapil blad: "<<endl;
        cerr<<e.what()<<endl;
        initDynamicArray();
        return;
    }
}

void Menu::initHeap() {
    cout<<"Podaj nazwe pliku, z ktorego chcesz pobrac dane do Heap: ";
    string input;
    cin>>input;
    cout<<"Wczytywanie danych..."<<endl;
    try {
        FileReader reader(input);
        heap = new Heap();
        reader.readToHeap(heap);
        printHeapMenu();
    } catch (runtime_error& e){
        cout<<"Wystapil blad: "<<endl;
        cerr<<e.what()<<endl;
        initHeap();
        return;
    }
}

void Menu::initRBTree() {
    cout<<"Podaj nazwe pliku, z ktorego chcesz pobrac dane do RBTree: ";
    string input;
    cin>>input;
    cout<<"Wczytywanie danych..."<<endl;
    try {
        FileReader reader(input);
        rBTree = new RBTree();
        reader.readToRBTree(rBTree);
        printRBTreeMenu();
    } catch (runtime_error& e){
        cout<<"Wystapil blad: "<<endl;
        cerr<<e.what()<<endl;
        initRBTree();
        return;
    }
}

void Menu::printBSTMenu() {
    bool goBack = false;
    while (!goBack){
        cout<<"Drzewo BST in-order: "<<endl;
        bst->printInOrder();
        cout<<"Co chcesz zrobic? "<<endl;
        cout<<"\t1. Dodaj element"<<endl;
        cout<<"\t2. Usun element"<<endl;
        cout<<"\t3. Znajdź element"<<endl;
        cout<<"\t4. Napraw DSW"<<endl;
        cout<<"\t0. Wroc do menu glownego"<<endl;
        cout<<"\t-1 Wyjdź"<<endl;
        int input;
        cout<<"Wybor: ";
        cin>>input;
        switch (input) {
            case 1: {
                cout<<"Podaj element do dodania: ";
                int input2;
                cin>>input;
                bst->add(input2);
                break;
            }
            case 2: {
                cout<<"Podaj element do usuniecia: ";
                int input2;
                cin>>input;
                if (bst->search(input2) != nullptr){
                    bst->remove(input2);
                }
                else cout<<"Ten element nie istnieje."<<endl;
                break;
            }
            case 3: {
                cout<<"Podaj element do znalezienia: ";
                int input2;
                cin>>input2;
                BSTNode* found = bst->search(input2);
                if (found != nullptr){
                    cout<<"Znaleziono taki element.";
                    if (found->getParent() != nullptr) cout<<"Jego ojciec: "<<found->getParent()->getValue()<<".";
                    if (found->getLeft() != nullptr) cout<<"Dziecko lewe: "<<found->getLeft()->getValue();
                    if (found->getRight() != nullptr) cout<<"Dziecko prawe: "<<found->getRight()->getValue();

                }
                else cout<<"Ten element nie istnieje.";
                break;
            }
            case 4: {
                cout<<"Naprawianie drzewa algorytmem DSW"<<endl;
                bst->fixDSW();
                break;
            }
            case 0: {
                backToMainMenu();
                goBack = true;
                break;
            }
            case -1: {
                cout<<"Zamykanie programu..."<<endl;
                exit(0);
            }
        }
    }
}

void Menu::printDoublyLinkedListMenu() {
    bool goBack = false;
    while (!goBack){
        cout<<"Doubly linked list: "<<endl;
        cout<<"Od poczatku do konca: ";
        doublyLinkedList->printFromStart();
        cout<<"Od konca do poczatku: ";
        doublyLinkedList->printFromEnd();
        cout<<"Co chcesz zrobic?"<<endl;
        cout<<"\t1. Dodaj element na poczatku"<<endl;
        cout<<"\t2. Dodaj element na koncu"<<endl;
        cout<<"\t3. Dodaj element na indeksie"<<endl;
        cout<<"\t4. Usun element"<<endl;
        cout<<"\t5. Znajdź element"<<endl;
        cout<<"\t0. Wroc do menu glownego"<<endl;
        cout<<"\t-1 Wyjdź"<<endl;
        int input;
        cout<<"Wybor: ";
        cin>>input;
        switch (input) {
            case 1: {
                cout<<"Podaj element do dodania: ";
                int input2;
                cin>>input;
                doublyLinkedList->addFront(input2);
                break;
            }
            case 2: {
                cout<<"Podaj element do dodania: ";
                int input2;
                cin>>input;
                doublyLinkedList->addBack(input2);
                break;
            }
            case 3: {
                cout<<"Podaj element do dodania: ";
                int input2;
                cin>>input;
                cout<<"Podaj indeks: ";
                int input3;
                cin>>input3;
                doublyLinkedList->addAtIndex(input3, input2);
                break;
            }
            case 4: {
                cout<<"Usuwanie elementu."<<endl;
                cout<<"Element do usuniecia: ";
                int input2;
                cin>>input2;
                if (doublyLinkedList->getNodeAt(input2) != nullptr){
                    doublyLinkedList->removeElement(input2);
                    cout<<"Usunieto element"<<endl;
                }
                else {
                    cout<<"Element nie istnieje";
                }
                break;
            }
            case 5: {
                cout<<"Podaj element to znalezienia: ";
                int input2;
                cin>>input2;
                if (doublyLinkedList->indexOf(input2) != -1){
                    cout<<"Element istnieje. Sasiednie wartosci: ";
                    DoublyLinkedNode* node = doublyLinkedList->getNodeAt(doublyLinkedList->indexOf(input2));
                    if (node->getPrev() != nullptr) cout<<" Poprzedni element: "<<node->getPrev()->getVal()<<".";
                    if (node->getNext() != nullptr) cout<<"Nastepny element: "<<node->getNext()->getVal()<<"."<<endl;
                }
                else {
                    cout<<"Ten element nie istnieje!"<<endl;
                }
                break;
            }
            case 0: {
                backToMainMenu();
                goBack = true;
                break;
            }
            case -1: {
                cout<<"Zamykanie programu..."<<endl;
                exit(0);
                break;
            }
        }
    }
}

void Menu::printDynamicArrayMenu() {
    bool goBack = false;
    while (!goBack){
        cout<<"Dynamic array list: "<<endl;
        cout<<"Od poczatku do konca: ";
        dynamicArray->printFromBeginning();
        cout<<"Od konca do poczatku: ";
        dynamicArray->printFromEnd();
        cout<<"Co chcesz zrobic?"<<endl;
        cout<<"\t1. Dodaj element na poczatku"<<endl;
        cout<<"\t2. Dodaj element na koncu"<<endl;
        cout<<"\t3. Dodaj element na indeksie"<<endl;
        cout<<"\t4. Usun element"<<endl;
        cout<<"\t5. Znajdź element"<<endl;
        cout<<"\t0. Wroc do menu glownego"<<endl;
        cout<<"\t-1 Wyjdź"<<endl;
        int input;
        cout<<"Wybor: ";
        cin>>input;
        switch (input) {
            case 1: {
                cout<<"Podaj element do dodania: ";
                int input2;
                cin>>input;
                dynamicArray->addFront(input2);
                break;
            }
            case 2: {
                cout<<"Podaj element do dodania: ";
                int input2;
                cin>>input;
                dynamicArray->addBack(input2);
                break;
            }
            case 3: {
                cout<<"Podaj element do dodania: ";
                int input2;
                cin>>input;
                cout<<"Podaj indeks: ";
                int input3;
                cin>>input3;
                dynamicArray->addAtIndex(input3, input2);
                break;
            }
            case 4: {
                cout<<"Usuwanie elementu."<<endl;
                cout<<"Element do usuniecia: ";
                int input2;
                cin>>input2;
                if (dynamicArray->contains(input2)){
                    dynamicArray->remove(input2);
                    cout<<"Usunieto element"<<endl;
                }
                else {
                    cout<<"Element nie istnieje";
                }
                break;
            }
            case 5: {
                cout<<"Podaj element to znalezienia: ";
                int input2;
                cin>>input2;
                if (dynamicArray->contains(input2)){
                    cout<<"Element istnieje. Jego indeks: "<<dynamicArray->indexOf(input2)<<endl;
                }
                else {
                    cout<<"Ten element nie istnieje!"<<endl;
                }
                break;
            }
            case 0: {
                backToMainMenu();
                goBack = true;
                break;
            }
            case -1: {
                cout<<"Zamykanie programu..."<<endl;
                exit(0);
                break;
            }
        }
    }
}

void Menu::printHeapMenu() {
    bool goBack = false;
    while (!goBack){
        cout<<"Heap: "<<endl;
        heap->printHeap();
        cout<<"Co chcesz zrobic? "<<endl;
        cout<<"\t1. Dodaj element"<<endl;
        cout<<"\t2. Usun element"<<endl;
        cout<<"\t0. Wroc do menu glownego"<<endl;
        cout<<"\t-1 Wyjdź"<<endl;
        int input;
        cout<<"Wybor: ";
        cin>>input;
        switch (input) {
            case 1: {
                cout<<"Podaj element do dodania: ";
                int input2;
                cin>>input;
                heap->add(input2);
                break;
            }
            case 2: {
                cout<<"Usuwanie elementu bedacego korzeniem...";
                heap->remove();
                break;
            }
            case 0: {
                backToMainMenu();
                goBack = true;
                break;
            }
            case -1: {
                cout<<"Zamykanie programu..."<<endl;
                exit(0);
            }
        }
    }
}

void Menu::printRBTreeMenu() {
    bool goBack = false;
    while (!goBack){
        cout<<"Drzewo czerwono-czarne in-order: "<<endl;
        rBTree->printInOrder();
        cout<<"Co chcesz zrobic? "<<endl;
        cout<<"\t1. Dodaj element"<<endl;
        cout<<"\t2. Usun element"<<endl;
        cout<<"\t3. Znajdź element"<<endl;
        cout<<"\t0. Wroc do menu glownego"<<endl;
        cout<<"\t-1 Wyjdź"<<endl;
        int input;
        cout<<"Wybor: ";
        cin>>input;
        switch (input) {
            case 1: {
                cout<<"Podaj element do dodania: ";
                int input2;
                cin>>input;
                rBTree->add(input2);
                break;
            }
            case 2: {
                cout<<"Podaj element do usuniecia: ";
                int input2;
                cin>>input;
                if (rBTree->search(input2) != nullptr){
                    rBTree->remove(input2);
                }
                else cout<<"Ten element nie istnieje."<<endl;
                break;
            }
            case 3: {
                cout<<"Podaj element do znalezienia: ";
                int input2;
                cin>>input2;
                RBNode* found = rBTree->search(input2);
                if (found != nullptr){
                    cout<<"Znaleziono taki element.";
                    if (found->getParent() != nullptr) cout<<"Jego ojciec: "<<found->getParent()->getData()<<".";
                    if (found->getLeft() != nullptr) cout<<"Dziecko lewe: "<<found->getLeft()->getData();
                    if (found->getRight() != nullptr) cout<<"Dziecko prawe: "<<found->getRight()->getData();

                }
                else cout<<"Ten element nie istnieje.";
                break;
            }
            case 0: {
                backToMainMenu();
                goBack = true;
                break;
            }
            case -1: {
                cout<<"Zamykanie programu..."<<endl;
                exit(0);
            }
        }
    }
}

void Menu::printBenchmarkMenu() {
    StructureType toTest;
    bool writeToFile;
    int initialSize;
    int step;
    float multiplier;
    int testNumber;
    int maxSize;

    cout<<"Podaj rodzaj struktury to przetestowania: "<<endl;
    cout<<"\t1. BST"<<endl;
    cout<<"\t2. DoublyLinkedList"<<endl;
    cout<<"\t3. DynamicArray"<<endl;
    cout<<"\t4. Heap"<<endl;
    cout<<"\t5. RBTree"<<endl;
    int input;
    cin>>input;
    switch (input) {
        case 1: {
            toTest = BST_T;
            break;
        }
        case 2: {
            toTest = DoublyLinkedList_T;
            break;
        }
        case 3: {
            toTest = DynamicArray_T;
            break;
        }
        case 4: {
            toTest = Heap_T;
            break;
        }
        case 5: {
            toTest = RBTree_T;
            break;
        }
    }

    cout<<"Czy ma nastapic zapis danych do pliku .csv? (T/N)";
    string odp;
    cin>>odp;
    if (odp[0] == 'T' || odp[0] == 't') writeToFile = true;
    else writeToFile = false;

    cout<<"Poczatkowa wielkosc struktury: ";
    cin>>initialSize;

    cout<<"Mnoznik wielkosci (zalecane 1): ";
    cin>>multiplier;

    cout<<"Krok (wielkosc o jaka ma byc zwiekszona wielkosc po kazdej iteracji): ";
    cin>>step;

    cout<<"Ile razy maja byc powtarzane testy: ";
    cin>>testNumber;

    cout<<"Jaka ma byc maksymalna wielkosc strulktury: ";
    cin>>maxSize;

    Benchmark benchmark(toTest, writeToFile, initialSize, step, multiplier, testNumber, maxSize);

    cout<<"Test ukończony"<<endl;
    backToMainMenu();
}

void Menu::backToMainMenu() {
    switch (type) {
        case BST_T: {
            delete bst;
            break;
        }
        case DoublyLinkedList_T: {
            delete doublyLinkedList;
            break;
        }
        case DynamicArray_T: {
            delete dynamicArray;
            break;
        }
        case Heap_T: {
            delete heap;
            break;
        }
        case RBTree_T: {
            delete rBTree;
            break;
        }
    }
}
