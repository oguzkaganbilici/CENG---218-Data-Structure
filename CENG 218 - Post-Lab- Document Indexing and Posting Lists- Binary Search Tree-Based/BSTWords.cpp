//
// Created by oguz.bilici on 19.05.2025.
//
#include<iostream>
#include<string>
#include "BSTWords.h"

#include <algorithm>

using namespace std;


BSTWords::BSTWords(): root(nullptr) {};

void BSTWords::insert(string newWord, int fileName, BSTNode *&r) {
    //std::transform(newWord.begin(), newWord.end(), newWord.begin(), ::tolower);
    BSTNode *newNode = new BSTNode(newWord);
    if (r == nullptr) {
        r = newNode;
        r->files.insert(fileName);
        return;
    }
    if (newWord < r->word) BSTWords::insert(newWord, fileName, r->leftChild);
    if (newWord > r->word) BSTWords::insert(newWord, fileName, r->rightChild);
    if (newWord == r->word) r->files.insert(fileName);
}
void BSTWords::insert(string newWord, int fileName) {
    insert(newWord, fileName, root);
}

void BSTWords::inOrderTraversal(BSTNode *&r, vector<pair<string,int>> &wordFreq) {
    if (r == nullptr) return;
    inOrderTraversal(r->leftChild, wordFreq);
    wordFreq.push_back({r->word, r->files.getFileCount()});
    inOrderTraversal(r->rightChild, wordFreq);
}
/*
void BSTWords::inOrderTraversal() {
    inOrderTraversal(root);
}
*/

const void BSTWords::searchFile(string keyWord, BSTNode *&r) {
    if (r == nullptr) return;
    if (r->word == keyWord) {
        r->files.print();
    }
    if (keyWord < r->word) searchFile(keyWord, r->leftChild);
    else {
        searchFile(keyWord, r->rightChild);
    }
}
const void BSTWords::searchFile(string keyWord) {
    searchFile(keyWord, root);
}

const vector<pair<string,int>>  BSTWords::mostAndLeastFrequentWords() {
    vector<pair<string,int>> wordFreq;
    inOrderTraversal(root, wordFreq);

    //vector sort işlemi
    sort(wordFreq.begin(), wordFreq.end(), [](const auto &a, const auto &b) {
        return a.second > b.second;
    });

    return wordFreq;

}
