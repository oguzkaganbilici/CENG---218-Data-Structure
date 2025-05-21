//
// Created by oguz.bilici on 19.05.2025.
//

#include<iostream>
using namespace std;

#ifndef LINKEDLISTNODE_H
#define LINKEDLISTNODE_H



class LinkedListNode {
public:
    int fileName;
    LinkedListNode *next;

    LinkedListNode(int file): fileName(file), next(nullptr) {};
};



#endif //LINKEDLISTNODE_H
