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
        case 'À': case 'Á': case 'Â': case 'Ã': case 'Ä': case 'Å': case '¨': case 'Æ':
        case 'Ç': case 'È': case 'É': case 'Ê': case 'Ë': case 'Ì': case 'Í': case 'Î':
        case 'Ï': case 'Ð': case 'Ñ': case 'Ò': case 'Ó': case 'Ô': case 'Õ': case 'Ö':
        case '×': case 'Ø': case 'Ù': case 'Ú': case 'Û': case 'Ü': case 'Ý': case 'Þ':
        case 'ß':
        case 'à': case 'á': case 'â': case 'ã': case 'ä': case 'å': case '¸': case 'æ':
        case 'ç': case 'è': case 'é': case 'ê': case 'ë': case 'ì': case 'í': case 'î':
        case 'ï': case 'ð': case 'ñ': case 'ò': case 'ó': case 'ô': case 'õ': case 'ö':
        case '÷': case 'ø': case 'ù': case 'ú': case 'û': case 'ü': case 'ý': case 'þ':
        case 'ÿ': case ' ': case '-':
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
