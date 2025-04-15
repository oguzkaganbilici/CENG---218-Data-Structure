//
// Created by oguz.bilici on 14.04.2025.
//

#include "WordNodeList.h"
#include<iostream>
using namespace std;

WordNodeList::WordNodeList(): head(nullptr) {};

void WordNodeList::addNewWord(string w, int fileID) {

    if (head == nullptr) {
        WordNode *newNode = new WordNode(w);
        newNode->wordList.addNewIndex(fileID);
        head = newNode;
        return;
    }

    WordNode *walker = head;
    while (walker != nullptr) {
        if (walker->word == w) {
            walker->wordList.addNewIndex(fileID);
            return;
        }
        if (walker->next == nullptr)
            break;
        walker = walker -> next;
    }

    WordNode *newNode = new WordNode(w);
    newNode->wordList.addNewIndex(fileID);
    walker->next = newNode;

}

void WordNodeList::deleteIndex(string w, int fileID) {
    WordNode *walker(head), *ptr(nullptr);

    if (head == nullptr) {
        cout<<"There is no index"<<endl;
        return;
    }
    if (head->word == w) {

    }
}

void WordNodeList::printWordList() const {
    WordNode *walker = head;

    while (walker != nullptr) {
        cout<<walker->word<<" -> ";
        walker = walker->next;
    }
    cout<<endl;
}

void WordNodeList::searchWord(string w) const {
    WordNode *walker = head;
    if (head == nullptr) {
        cout<<"Nothing to search"<<endl;
        return;
    }

    while (walker != nullptr) {
        if (walker->word == w) {
            walker->wordList.printIndexList();
            break;
        }
        walker = walker->next;
    }
    cout<<endl;
}
