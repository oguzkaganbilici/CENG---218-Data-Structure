#include<iostream>
#include "BSTWords.h"
using namespace std;


int main() {
    BSTWords BST;
    BST.insert("aRAba", "file1");
    BST.insert("zurna", "file1");
    BST.insert("Arada", "file1");
    BST.insert("Bursa", "file1");
    BST.insert("Ceyhan", "file1");
    BST.insert("Arap", "file1");
    BST.insert("Aa", "file1");
    BST.inOrderTraversal();
    return 0;
}