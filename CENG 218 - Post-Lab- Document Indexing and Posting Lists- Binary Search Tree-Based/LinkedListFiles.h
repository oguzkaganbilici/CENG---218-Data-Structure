//
// Created by Oğuz Kağan Bilici on 18.05.2025.
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
    void insert(string fileName);
};



#endif //LINKEDLISTFILES_H
