//
// Created by Oğuz Kağan Bilici on 18.05.2025.
//

#include "LinkedListFiles.h"
#include "LinkedListNode.h"

LinkedListFiles::LinkedListFiles(): head(nullptr), fileCount(0) {};
void LinkedListFiles::insert(string fileName) {
    // her dosyayi linkedList'in sonuna eklemektense basa eklemek daha hizli olacaktir.
    // gemini önerisi.
    LinkedListNode *newNode = new LinkedListNode(fileName);
    newNode -> next = head;
    head = newNode;
    fileCount++;
}