#include <iostream>
#include <fstream>
#include <cctype>
using namespace std;

void removeNonLetters(const string& inputFileName, const string& outputFileName) {
    ifstream inputFile(inputFileName);
    ofstream outputFile(outputFileName);

    if (!inputFile) {
        cerr << "Unable to open input file: " << inputFileName << endl;
        return;
    }

    if (!outputFile) {
        cerr << "Unable to open output file: " << outputFileName << endl;
        return;
    }

    char ch;
    while (inputFile.get(ch)) {
        switch (ch) {
        case '�': case '�': case '�': case '�': case '�': case '�': case '�': case '�':
        case '�': case '�': case '�': case '�': case '�': case '�': case '�': case '�':
        case '�': case '�': case '�': case '�': case '�': case '�': case '�': case '�':
        case '�': case '�': case '�': case '�': case '�': case '�': case '�': case '�':
        case '�':
        case '�': case '�': case '�': case '�': case '�': case '�': case '�': case '�':
        case '�': case '�': case '�': case '�': case '�': case '�': case '�': case '�':
        case '�': case '�': case '�': case '�': case '�': case '�': case '�': case '�':
        case '�': case '�': case '�': case '�': case '�': case '�': case '�': case '�':
        case '�': case ' ': case '-':
        case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9': case '0':
            outputFile.put(ch);
            break;
        default:
            break;
        }
    }

    inputFile.close();
    outputFile.close();
}
