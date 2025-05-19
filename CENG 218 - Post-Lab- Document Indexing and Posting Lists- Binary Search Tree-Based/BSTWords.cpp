//
// Created by Oğuz Kağan Bilici on 18.05.2025.
//

#include "BSTWords.h"

BSTWords::BSTWords(): root(nullptr) {};

void BSTWords::insert(string newWord, string fileName, BSTNode *&r) {
    std::transform(newWord.begin(), newWord.end(), newWord.begin(), ::tolower);
    std::transform(fileName.begin(), fileName.end(), fileName.begin(), ::tolower);
    
    BSTNode *newNode = new BSTNode(newWord);
    if (r == nullptr) {
        r = newNode;
        r->files.insert(fileName);
        return;
    }
    if (newWord < r->word) BSTWords::insert(newWord, fileName, r->leftChild);
    if (newWord > r->word) BSTWords::insert(newWord, fileName, r->rightChild);
    if (newWord == r->word) r->files.insert(fileName);
}
void BSTWords::insert(string newWord, string fileName) {
    insert(newWord, fileName, root);
}

void BSTWords::inOrderTraversal(BSTNode *&r) {
    if (r == nullptr) return;
    BSTWords::inOrderTraversal(r->leftChild);
    cout<<r->word<< " ";
    BSTWords::inOrderTraversal(r->rightChild);
}
void BSTWords::inOrderTraversal() {
    inOrderTraversal(root);
}