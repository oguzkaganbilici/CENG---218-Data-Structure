//
// Created by oguz.bilici on 14.04.2025.
//

#ifndef WORDNODELIST_H
#define WORDNODELIST_H

#include "WordNode.h"


class WordNodeList {
private:
    WordNode *head;
public:
    WordNodeList();
    void addNewWord(string w, int fileID);
    void deleteIndex(string w, int fileID);
    void printWordList() const;
    void searchWord(string w) const;
    void searchMostFrequent() const;
    void searchLeastFrequent() const;
};



#endif //WORDNODELIST_H
