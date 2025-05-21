//
// Created by oguz.bilici on 19.05.2025.
//

#ifndef LINKEDLISTFILES_H
#define LINKEDLISTFILES_H

#include<iostream>
#include "LinkedListNode.h"
using namespace std;

class LinkedListFiles {
private:
    LinkedListNode *head;
    int fileCount;

public:
    LinkedListFiles();
    void insert(int fileName);
    const void print();
    const int getFileCount();
};




#endif //LINKEDLISTFILES_H
