#include <iostream>
#include "WordNodeList.h"
#include "fstream"
#include<cctype>

string clearWord(const string &word) {
    string clearWord;
    for (char c: word) {
        if (isalpha(static_cast<unsigned char>(c))) {
            clearWord += tolower(c);
        }
    }
    return clearWord;
}
void readDocuments(const string &filename, WordNodeList *wordList) {
    ifstream documents(filename);
    string word;

    if (!documents.is_open()) {
        cout<<"File does not exist"<<endl;
        return;
    }

    while (documents>> word) {
        wordList->addNewWord(clearWord(word), 1);
        //cout<<clearWord(word)<<endl
    }
}

int main() {

    WordNodeList newWordList;
    readDocuments("C:\\Users\\oguz.bilici\\Desktop\\CENG 218 Document Indexing\\AllDocs\\1.txt", &newWordList);
    readDocuments("C:\\Users\\oguz.bilici\\Desktop\\CENG 218 Document Indexing\\AllDocs\\2.txt", &newWordList);
    newWordList.printWordList();



    return 0;
}
