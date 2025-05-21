//
// Created by oguz.bilici on 19.05.2025.
//
#include<iostream>
#include "LinkedListFiles.h"

#include <vector>

#include "LinkedListNode.h"

LinkedListFiles::LinkedListFiles(): head(nullptr), fileCount(0) {};

void LinkedListFiles::insert(int fileName) {
    // her dosyayi linkedList'in sonuna eklemektense basa eklemek daha hizli olacaktir.
    // gemini önerisi.
    // v.2. - ama bu yöntem linkedlist'de olan degeri kontrol etmedigi için iptal ediyoruz.
    // en iyi yol bildigin yol.....
    /*
    LinkedListNode *newNode = new LinkedListNode(fileName);
    newNode -> next = head;
    head = newNode;
    fileCount++;
    */
    LinkedListNode* newNode = new LinkedListNode(fileName);

    if (head == nullptr) {
        head = newNode;
        fileCount++;
        return;
    }
    LinkedListNode* walker = head;
    while (walker -> next != nullptr) {
        if (walker -> fileName == fileName) {
            delete newNode;
            return;
        }
        walker = walker->next;
    }
    newNode -> next = head;
    head = newNode;
    fileCount++;
}

const void LinkedListFiles::print() {
    if (head == nullptr) return;

    LinkedListNode *walker = head;
    while (walker != nullptr) {
        cout << walker -> fileName << endl;
        walker = walker -> next;
    }
}

const int LinkedListFiles::getFileCount() {
    return fileCount;
}
