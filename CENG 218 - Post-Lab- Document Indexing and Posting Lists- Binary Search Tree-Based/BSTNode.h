//
// Created by Oğuz Kağan Bilici on 18.05.2025.
//
#include<iostream>
#include<string>
#include "LinkedListFiles.h"
using namespace std;

#ifndef BSTNODE_H
#define BSTNODE_H



class BSTNode {
public:
    string word;
    LinkedListFiles files;

    BSTNode *leftChild;
    BSTNode *rightChild;

    BSTNode(string w);
};



#endif //BSTNODE_H
