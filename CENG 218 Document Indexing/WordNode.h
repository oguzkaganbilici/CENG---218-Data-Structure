//
// Created by oguz.bilici on 14.04.2025.
//

#ifndef WORDNODE_H
#define WORDNODE_H

#include "IndexNodeList.h"
#include<iostream>
using namespace std;

class WordNode {
public:
    string word;
    IndexNodeList wordList;
    WordNode *next;

    WordNode(string w);
};



#endif //WORDNODE_H
