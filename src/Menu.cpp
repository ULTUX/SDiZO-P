//
// Created by Wladyslaw Nowak on 17.04.2021.
//

#include "../include/Menu.h"
#include "IO/FileReader.h"
#include "../include/Benchmark.h"

Menu::Menu() {
    printMainMenu();
}

void Menu::printMainMenu() {

    while (true){
        cout<<"Wybierz polecenie: "<<endl;
        cout<<"\t1. Uruchom testy"<<endl;
        cout<<"\t2. Zaladuj strukture z pliku"<<endl;
        cout<<"\t0. Wylacz program"<<endl;
        int input = getIntegerInput("Wybor: ");
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
    cout<<"\t0. Powrot"<<endl;
    int input = getIntegerInput("Wybor: ");
    bool isPicked = false;
    while (!isPicked) {
        switch (input) {
            case 1: {
                type = BST_T;
                initBST();
                isPicked = true;
                break;
            }
            case 2: {
                type = DoublyLinkedList_T;
                initDoublyLinkedList();
                isPicked = true;
                break;
            }
            case 3: {
                type = DynamicArray_T;
                initDynamicArray();
                isPicked = true;
                break;
            }
            case 4: {
                type = Heap_T;
                initHeap();
                isPicked = true;
                break;
            }
            case 5: {
                type = RBTree_T;
                initRBTree();
                isPicked = true;
                break;
            }
            default: {
                cout<<"Nieznany wybor."<<endl;
            }
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
        printException(e);
        initBST();
        return;
    }
}

void Menu::initDoublyLinkedList() {
    cout<<"Podaj nazwe pliku, z ktorego chcesz pobrac dane do listy dwukierunkowej: ";
    string input;
    cin>>input;
    cout<<"Wczytywanie danych..."<<endl;
    try {
        FileReader reader(input);
        doublyLinkedList = new DoublyLinkedList();
        reader.readToDoublyLinkedList(doublyLinkedList, BACK);
        printDoublyLinkedListMenu();
    } catch (runtime_error& e){
        printException(e);
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
        printException(e);
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
        printException(e);
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
        printException(e);
        initRBTree();
        return;
    }
}

void Menu::printBSTMenu() {
    bool goBack = false;
    while (!goBack){
        cout<<"Drzewo BST: "<<endl;
        bst->postOrder(bst->getRoot(), 0);
        cout<<"\nIn-order: "<<endl;
        bst->printInOrder();
        cout<<"\nCo chcesz zrobic? "<<endl;
        cout<<"\t1. Dodaj element"<<endl;
        cout<<"\t2. Usun element"<<endl;
        cout<<"\t3. Znajdz element"<<endl;
        cout<<"\t4. Napraw DSW"<<endl;
        cout<<"\t0. Wroc do menu glownego"<<endl;
        cout<<"\t-1 Wyjdz"<<endl;
        int input = getIntegerInput("Wybor: ");
        switch (input) {
            case 1: {
                int input2 = getIntegerInput("Podaj element do dodania: ");
                bst->add(input2);
                break;
            }
            case 2: {
                int input2 = getIntegerInput("Podaj element do usuniecia: ");
                if (bst->search(input2) != nullptr){
                    try {
                        bst->remove(input2);
                    } catch (invalid_argument& e) {
                        printException(e);
                    }
                }
                else cout<<"Ten element nie istnieje.\n";
                break;
            }
            case 3: {
                int input2;
                input2 = getIntegerInput("Podaj element do znalezienia: ");
                BSTNode* found = bst->search(input2);
                if (found != nullptr){
                    cout<<"Znaleziono taki element.";
                    if (found->getParent() != nullptr) cout<<"\n\tJego ojciec: "<<found->getParent()->getValue()<<".";
                    if (found->getLeft() != nullptr) cout<<"\n\tDziecko lewe: "<<found->getLeft()->getValue();
                    if (found->getRight() != nullptr) cout<<"\n\tDziecko prawe: "<<found->getRight()->getValue();
                    cout<<"\n";

                }
                else cout<<"Ten element nie istnieje.\n";
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
        cout<<"\t5. Znajdz element"<<endl;
        cout<<"\t0. Wroc do menu glownego"<<endl;
        cout<<"\t-1 Wyjdz"<<endl;
        int input;
        input = getIntegerInput("Wybor: ");
        switch (input) {
            case 1: {
                int input2;
                input2 = getIntegerInput("Podaj element do dodania: ");
                doublyLinkedList->addFront(input2);
                break;
            }
            case 2: {
                int input2;
                input2 = getIntegerInput("Podaj element do dodania: ");
                doublyLinkedList->addBack(input2);
                break;
            }
            case 3: {
                int input2;
                input2 = getIntegerInput("Podaj element do dodania: ");
                int input3;
                input3 = getIntegerInput("Podaj indeks: ");
                doublyLinkedList->addAtIndex(input3, input2);
                break;
            }
            case 4: {
                cout<<"Usuwanie elementu."<<endl;
                int input2;
                input2 = getIntegerInput("Element do usuniecia: ");
                if (doublyLinkedList->indexOf(input2) != -1){
                    doublyLinkedList->removeElement(input2);
                    cout<<"Usunieto element"<<endl;
                }
                else {
                    cout<<"Element nie istnieje\n";
                }
                break;
            }
            case 5: {
                int input2 = getIntegerInput("Podaj element to znalezienia: ");
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
            }
            default: {
                cout<<"Nieznany argument"<<endl;
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
        cout<<"\t5. Znajdz element"<<endl;
        cout<<"\t0. Wroc do menu glownego"<<endl;
        cout<<"\t-1 Wyjdz"<<endl;
        int input;
        input = getIntegerInput("Wybor: ");
        switch (input) {
            case 1: {
                int input2 = getIntegerInput("Podaj element do dodania: ");
                dynamicArray->addFront(input2);
                break;
            }
            case 2: {
                int input2 = getIntegerInput("Podaj element do dodania: ");
                dynamicArray->addBack(input2);
                break;
            }
            case 3: {
                int input2 = getIntegerInput("Podaj element do dodania: ");
                int input3 = getIntegerInput("Podaj indeks: ");
                dynamicArray->addAtIndex(input2, input3);
                break;
            }
            case 4: {
                cout<<"Usuwanie elementu."<<endl;
                int input2 = getIntegerInput("Indeks elementu do usuniecia: ");
                if (dynamicArray->getSize() > input2){
                    dynamicArray->remove(input2);
                    cout<<"Usunieto element"<<endl;
                }
                else {
                    cout<<"Element nie istnieje"<<endl;
                }
                break;
            }
            case 5: {
                int input2 = getIntegerInput("Podaj element to znalezienia: ");
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
        heap->print();
        cout<<"Co chcesz zrobic? "<<endl;
        cout<<"\t1. Dodaj element"<<endl;
        cout<<"\t2. Usun element"<<endl;
        cout<<"\t3. Wyswietl kopiec"<<endl;
        cout<<"\t0. Wroc do menu glownego"<<endl;
        cout<<"\t-1 Wyjdz"<<endl;
        int input = getIntegerInput("Wybor: ");
        switch (input) {
            case 1: {
                int input2 = getIntegerInput("Podaj element do dodania: ");
                heap->add(input2);
                break;
            }
            case 2: {
                cout<<"Usuwanie elementu bedacego korzeniem...\n";
                try {
                    heap->remove();
                } catch (length_error& e) {
                    printException(e);
                }
                break;
            }
            case 3: {
                heap->print();
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
        cout<<"Drzewo czerwono-czarne: "<<endl;
        rBTree->postOrder(rBTree->getRoot(), 0);
        cout<<"\nIn-order: "<<endl;
        rBTree->printInOrder();
        cout<<"\nCo chcesz zrobic? "<<endl;
        cout<<"\t1. Dodaj element"<<endl;
        cout<<"\t2. Usun element"<<endl;
        cout<<"\t3. Znajdz element"<<endl;
        cout<<"\t0. Wroc do menu glownego"<<endl;
        cout<<"\t-1 Wyjdz"<<endl;
        int input = getIntegerInput("Wybor: ");
        switch (input) {
            case 1: {
                int input2 = getIntegerInput("Podaj element do dodania: ");
                rBTree->add(input2);
                break;
            }
            case 2: {
                int input2 = getIntegerInput("Podaj element do usuniecia: ");
                if (rBTree->search(input2) != nullptr){
                    rBTree->remove(input2);
                }
                else cout<<"Ten element nie istnieje."<<endl;
                break;
            }
            case 3: {
                int input2 = getIntegerInput("Podaj element do znalezienia: ");
                RBNode* found = rBTree->search(input2);
                if (found != nullptr){
                    cout<<"Znaleziono taki element.";
                    if (found->getParent() != nullptr) cout<<"\n\tJego ojciec: "<<found->getParent()->getData()<<".";
                    if (found->getLeft() != nullptr) cout<<"\n\tDziecko lewe: "<<found->getLeft()->getData();
                    if (found->getRight() != nullptr) cout<<"\n\tDziecko prawe: "<<found->getRight()->getData();
                    cout<<"\n";

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
    bool isPicked = false;
    while (!isPicked) {
        int input = getIntegerInput("Wybor: ");
        switch (input) {
            case 1: {
                toTest = BST_T;
                isPicked = true;
                break;
            }
            case 2: {
                toTest = DoublyLinkedList_T;
                isPicked = true;
                break;
            }
            case 3: {
                toTest = DynamicArray_T;
                isPicked = true;
                break;
            }
            case 4: {
                toTest = Heap_T;
                isPicked = true;
                break;
            }
            case 5: {
                toTest = RBTree_T;
                isPicked = true;
                break;
            }
            default: {
                cout<<"Nieznany wybor."<<endl;
            }
        }
    }

    cout<<"Czy ma nastapic zapis danych do pliku .csv? (T/N): ";
    string odp;
    cin>>odp;
    if (odp[0] == 'T' || odp[0] == 't') writeToFile = true;
    else writeToFile = false;

    initialSize= getIntegerInput("Poczatkowa wielkosc struktury: ", true);

    multiplier = getFloatInput("Mnoznik wielkosci (zalecane 1): ", true);

    step = getIntegerInput("Krok (wielkosc o jaka ma byc zwiekszona wielkosc po kazdej iteracji): ", true);

    testNumber = getIntegerInput("Ile razy maja byc powtarzane testy: ", true);

    maxSize = getIntegerInput("Jaka ma byc maksymalna wielkosc strulktury: ", true);

    Benchmark benchmark(toTest, writeToFile, initialSize, step, multiplier, testNumber, maxSize);

    cout<<"Test ukonczony"<<endl;
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

int Menu::getIntegerInput(string message, bool mustPositive) {
    bool isNum = false;
    bool isPositive = false;
    int val;
    while (!isNum) {
        cout << message;
        string input;
        cin.clear();
        cin.sync();
        getline(cin, input);
        try {
            val = stoi(input);
            if (val > 0) isPositive = true;
            if (!mustPositive) isNum = true;
            else if (isPositive) isNum = true;
            else isNum = false;
        } catch (invalid_argument &e) {
            cout << "Wprowadzone dane nie sa liczba!" << endl;
            continue;
        }
        catch (out_of_range &e) {
            cout << "Wprowadzona liczba jest za duza!" << endl;
            continue;
        }
    }
    return val;
}
float Menu::getFloatInput(string message, bool mustPositive) {
    bool isNum = false;
    bool isPositive = false;
    float val;
    while (!isNum) {
        cout << message;
        string input;
        cin.clear();
        cin.sync();
        getline(cin, input);
        try {
            val = stof(input);
            if (val > 0) isPositive = true;
            if (!mustPositive) isNum = true;
            else if (isPositive) isNum = true;
            else isNum = false;
        } catch (invalid_argument &e) {
            cout << "Wprowadzone dane nie sa liczba!" << endl;
            continue;
        }
        catch (out_of_range &e) {
            cout << "Wprowadzona liczba jest za duza!" << endl;
            continue;
        }
    }
    return val;
}

void Menu::printException(exception &e) {
    cout<<"-------------------------------"<<endl;
    cout<<endl<<endl<<"UWAGA: Wystapil blad: ";
    cerr<<e.what()<<endl<<endl<<endl;
    cout<<"-------------------------------"<<endl;
}

