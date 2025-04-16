//
// Created by oguz.bilici on 14.04.2025.
//

#ifndef INDEXNODELIST_H
#define INDEXNODELIST_H

#include "IndexNode.h"
#include<iostream>
using namespace std;

class IndexNodeList {
private:
    IndexNode *head;
public:
    IndexNodeList();
    void addNewIndex(int i);
    void deleteIndex(int i);
    void printIndexList() const;
    int getIndexCount() const;
};



#endif //INDEXNODELIST_H
