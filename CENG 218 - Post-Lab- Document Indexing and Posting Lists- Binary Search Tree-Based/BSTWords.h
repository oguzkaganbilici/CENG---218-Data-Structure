//
// Created by oguz.bilici on 19.05.2025.
//
#include<iostream>
#include <vector>
#include "BSTNode.h"
using namespace std;

#ifndef BSTWORDS_HTrtpolo.2025.
#define BSTWORDS_H

class BSTWords {
private:
    BSTNode *root;

    void insert(string newWord, int fileName, BSTNode *&r);
    void inOrderTraversal(BSTNode *&r, vector<pair<string, int>> &wordFreq);
    const void searchFile(string keyWord, BSTNode *&r);

public:
    BSTWords();
    void insert(string newWord, int fileName);
    //void inOrderTraversal();
    const void searchFile(string keyWord);
    const vector<pair<string,int>>  mostAndLeastFrequentWords();
};



#endif //BSTWORDS_H
