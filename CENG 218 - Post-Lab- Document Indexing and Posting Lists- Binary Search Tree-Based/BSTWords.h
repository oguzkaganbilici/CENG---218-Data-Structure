//
// Created by Oğuz Kağan Bilici on 18.05.2025.
//

#include<iostream>
#include "BSTNode.h"
using namespace std;

#ifndef BSTWORDS_H
#define BSTWORDS_H



class BSTWords {
private:
    BSTNode *root;

    void insert(string newWord, string fileName, BSTNode *&r);
    void inOrderTraversal(BSTNode *&r);

public:
    BSTWords();
    void insert(string newWord, string fileName);
    void inOrderTraversal();
};



#endif //BSTWORDS_H
