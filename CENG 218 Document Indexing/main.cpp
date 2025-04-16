#include <iostream>
#include <cctype>
#include "WordNodeList.h"
#include "fstream"
#include <chrono>
#include <algorithm>
using namespace std;
using namespace std::chrono;

string clearWord(const string &word) {
    string clearWord;
    for (char c: word) {
        if (isalpha(static_cast<unsigned char>(c))) {
            clearWord += tolower(c);
        }
    }
    return clearWord;
}
bool isWhitespaceOnly(const std::string& str) {
    return std::all_of(str.begin(), str.end(), [](unsigned char c) {
        return std::isspace(c);
    });
}
void readDocuments(const string &filename, WordNodeList *wordList) {
    ifstream documents(filename);
    string word;
    int fileID;
    size_t pos = filename.find(".");
    if (pos != string::npos) {
        fileID = std::stoi(filename.substr(0, pos));
    }

    if (!documents.is_open()) {
        cout<<"File does not exist"<<endl;
        return;
    }

    while (documents>> word) {
        string cleanedWord = clearWord(word);
        if (!cleanedWord.empty() && !isWhitespaceOnly(cleanedWord)) {
            wordList->addNewWord(cleanedWord, fileID);
            //cout<<clearWord(word)<<endl
        }
    }
}
void printMenu(auto minutes, auto seconds) {
    std::cout << "=============================================\n";
    std::cout << "|       Simple Document Retrieval System     |\n";
    std::cout << "|(index creation time: "<<minutes<<" Minutes "<<seconds<<" Seconds) |\n";
    std::cout << "=============================================\n";
    std::cout << "| 1. Enter a single keyword to list the      |\n";
    std::cout << "|    document(s) (file names)                |\n";
    std::cout << "| 2. Print the top 10 words that appeared    |\n";
    std::cout << "|    most frequently                         |\n";
    std::cout << "| 3. Print the top 10 words that appeared    |\n";
    std::cout << "|    least frequently                        |\n";
    std::cout << "| 4. Exit                                    |\n";
    std::cout << "=============================================\n";
}

int main() {
    WordNodeList newWordList;
    auto startTime = high_resolution_clock::now();
    for (int i=1;i<=9598;i++) {
        string filename = std::to_string(i) + ".txt";
        readDocuments(filename, &newWordList);
    }
    auto endTime = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(endTime - startTime);
    int minutes = duration.count() / 60000;
    int seconds = (duration.count() % 60000) / 1000;

    int kullaniciGiris;
    while (kullaniciGiris != 4) {
        printMenu(minutes, seconds);
        cout<<"Enter your selection: ";
        cin>>kullaniciGiris;

        if (kullaniciGiris == 1) {
            string keyWord;
            cout<<endl<<"Enter a word you want to search: ";
            cin>>keyWord;
            cout<<"\nFile Name: "<<endl;
            newWordList.searchWord(keyWord);
        }
        if (kullaniciGiris == 2) {
            newWordList.searchMostFrequent();
        }
        if (kullaniciGiris == 3) {
            newWordList.searchLeastFrequent();
        }
        if (kullaniciGiris == 4) {
            exit(0);
        }
    }
    return 0;
}
