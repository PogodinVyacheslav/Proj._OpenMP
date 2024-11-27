#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <cctype>
//#include <time.h>
#include <omp.h>
//#include <ctime>  
#include "StdCUtil/split.h"
#include "withoutsigns.h"
//using namespace std;

const int g_nNumberOfThreads = 4;

// Функция для преобразования строки в нижний регистр
string to_lower(const string& str) {
    string result;
    for (char c : str) {
        result += tolower(c);
    }
    return result;
}

int main() {

    
    //unsigned int start_time = clock(); 
    omp_set_num_threads(g_nNumberOfThreads);
    setlocale(LC_ALL, "Russian");

    clock_t start = clock();
    string inputFileName = "prestuplenie-i-nakazanie.txt";
    string outputFileName = "output.txt";

    removeNonLetters(inputFileName, outputFileName);

    std::cout << "Processing complete. Result saved to " << outputFileName << endl;

    ifstream input("output.txt");
    if (!input.is_open()) {
        cerr << "Error opening file" << endl;
        return 1;
    }

    unordered_map<string, int> word_count;
    string word;

    // Чтение файла и подсчет количества вхождений каждого слова
    while (input >> word) {
        word = to_lower(word);
        word_count[word]++;
    }

    input.close();



    // Создание вектора пар (слово, количество вхождений)
    vector<pair<string, int>> word_vector;

    {
        for (const auto& pair : word_count)
        {
            word_vector.push_back(pair);
        }
    }
    // Сортировка вектора по убыванию количества вхождений
    
#pragma omp parallel
    std::sort(word_vector.begin(), word_vector.end(),
        [](const auto& a, const auto& b) {
            return a.second > b.second;
        });
        
         //Вывод топ-30 самых популярных слов
    std::cout << "Top 30 popular words:" << endl;
    for (size_t i = 0; i < 30; ++i) {
        cout << i + 1 << ". " << word_vector[i].first << ": " << word_vector[i].second << endl;
    }                             // Время начала вычислений
    //unsigned int end_time = clock();                                // Время окончания вычислений
    //std::cout << "time = " << end_time - start_time << " ms.\n";
    return 0;
}
