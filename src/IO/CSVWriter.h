//
// Created by Wladyslaw Nowak on 15.04.2021.
//

#ifndef SDIZO1_CSVWRITER_H
#define SDIZO1_CSVWRITER_H

#include <fstream>
#include "../../include/DynamicArray.h"

using namespace std;
class CSVWriter {
private:
    const string fileName;
    const int dataSize;
    const int columnWidth;
    DynamicArray* data;
    string * headers;
    ofstream stream;
public:
    CSVWriter(string fileName, int dataSize, int columnWidth, string* headers, DynamicArray* data);

    void writeData();
};


#endif //SDIZO1_CSVWRITER_H
