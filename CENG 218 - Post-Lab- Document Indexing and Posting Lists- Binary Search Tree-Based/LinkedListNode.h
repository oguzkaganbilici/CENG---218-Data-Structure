//
// Created by Oğuz Kağan Bilici on 18.05.2025.
//

#include<iostream>
using namespace std;

#ifndef LINKEDLISTNODE_H
#define LINKEDLISTNODE_H


class LinkedListNode {
public:
    string fileName;
    LinkedListNode *next;

    LinkedListNode(string file): fileName(file), next(nullptr) {};

};



#endif //LINKEDLISTNODE_H
