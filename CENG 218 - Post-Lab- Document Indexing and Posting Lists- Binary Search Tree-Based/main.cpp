#include<iostream>
#include <fstream>
#include <sstream> // stringstream kullanmak için eklendi
#include <cctype>  // isalpha kullanmak için eklendi
#include <format> // string format için
#include <chrono> //time için
#include "BSTWords.h"
using namespace std;

string cleanWord(const string &word) {
    string cleanedWord;

    for (char c: word) {
        if (isalpha(static_cast<unsigned char>(c))) {
            cleanedWord += ::tolower(c);
        }
    }
    //std::transform(cleanedWord.begin(), cleanedWord.end(), cleanedWord.begin(), ::tolower);
    //baştan dolasmanın manası yok. eklerken kücültürüz
    return cleanedWord;
}

void readFiles(const string &fileName, BSTWords &bstTree) {
    ifstream documents(fileName);
    string line;

    int fileID;
    size_t pos = fileName.find(".");
    if (pos != string::npos) {
        fileID = stoi(fileName.substr(0, pos));
    }

    if (!documents.is_open()) {
        cout<<"File does not exist"<<endl;
    }

    while (getline(documents, line)) {
        stringstream ss(line);
        string word;
        while (ss >> word) {
            string cleanedWord = cleanWord(word);
            if (!cleanedWord.empty()) {
                bstTree.insert(cleanedWord, fileID);
            }
        }
    }
    documents.close();
}

void printMenu(string processTime) {
    auto menu = std::format(
     "Simple Document Retrieval System\n"
     "           ({})\n"
     "---------------------------------\n"
     "1. Enter a single keyword to list the document(s) (filenames)\n"
     "2. Print the top 10 words that appeared most frequently\n"
     "3. Print the top 10 words that appeared least frequently\n"
     "4. Exit",
     processTime
 );
    cout << menu << endl;
}

int main() {
    auto startTime = std::chrono::high_resolution_clock::now();
    BSTWords BST;
    for (int i=1;i<9599;i++) {
        string file = std::to_string(i) + ".txt";
        readFiles(file, BST);
    }
    auto endTime = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);
    int minutes = duration.count() / 60000;
    int seconds = (duration.count() % 60000) / 1000;

    string processTime = std::to_string(minutes) + ":" + std::to_string(seconds);
    int userSelection;
    while (userSelection != 4) {
        printMenu(processTime);
        cin >> userSelection;

        if (userSelection == 1) {
            string word;
            cout << "Enter a word to search: ";
            cin >> word;
            cout<<endl;
            BST.searchFile(word);
        }
        else if (userSelection == 2) {
            vector<pair<string,int>> wordFreq = BST.mostAndLeastFrequentWords();
            cout<< "---Most frequent 10 words---"<<endl;
            for (int i = 1; i <= 10; i++) {
                cout<<i<<". "<<wordFreq[i].first<<" -> "<<wordFreq[i].second<<endl;
            }
        }
        else if (userSelection == 3) {
            vector<pair<string,int>> wordFreq = BST.mostAndLeastFrequentWords();
            cout<< "---Most frequent 10 words---"<<endl;
            for (int i = wordFreq.size(); i >= wordFreq.size() - 10; i--) {
                cout<<i<<". "<<wordFreq[i].first<<" -> "<<wordFreq[i].second<<endl;
            }
        }
        else if (userSelection == 4) {
            exit(0);
        }
        else {
            cout << "Invalid selection" << endl;
        }
    }

    return 0;
}