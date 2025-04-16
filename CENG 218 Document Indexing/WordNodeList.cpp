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

void WordNodeList::searchMostFrequent() const {
    vector<pair<string, int>> wordFreq;
    WordNode *walker(head);

    while (walker != nullptr) {
        wordFreq.push_back({walker->word, walker->wordList.getIndexCount()});
        walker = walker->next;
    }

    sort(wordFreq.begin(), wordFreq.end(), [](const auto& a, const auto& b) {
        return a.second > b.second;
    });

    cout << "Top 10 most frequent words:\n";
    for (int i=0;i<10;i++) {
        cout<<i+1<<". "<<wordFreq[i].first << " -> "<<wordFreq[i].second<<endl;
    }
}

void WordNodeList::searchLeastFrequent() const {
    vector<pair<string, int>> leastFreq;
    WordNode *walker(head);

    while (walker != nullptr) {
        leastFreq.push_back({walker->word, walker->wordList.getIndexCount()});
        walker = walker->next;
    }

    sort(leastFreq.begin(), leastFreq.end(), [](const auto &a, const auto &b) {
        return a.second < b.second;
    });

    cout << "Top 10 least frequent words:\n";
    for (int i=0;i<10;i++) {
        cout<<i+1<<". "<<leastFreq[i].first << " -> "<<leastFreq[i].second<<endl;
    }
}
