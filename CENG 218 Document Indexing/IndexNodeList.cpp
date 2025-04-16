//
// Created by oguz.bilici on 14.04.2025.
//

#include "IndexNodeList.h"

IndexNodeList::IndexNodeList(): head(nullptr) {};

void IndexNodeList::addNewIndex(int i) {
    IndexNode *newNode = new IndexNode(i);
    if (head == nullptr) {
        head = newNode;
    }
    else {
        IndexNode *walker = head;
        while (walker != nullptr) {
            if (walker->index == i) return;
            if (walker->next == nullptr)
                break;
            walker = walker->next;
        }
        walker->next = newNode;
    }
}

void IndexNodeList::deleteIndex(int i) {
    IndexNode *walker = head, *prev=nullptr;

    if (head == nullptr) {
        cout<<"There is not any index"<<endl;
        return;
    }
    if (head->index == i) {
        IndexNode *temp = head;
        head = head->next;
        delete temp;
        return;
    }
    while (walker != nullptr) {
        if (walker->index == i) {
            prev->next = walker->next;
            delete walker;
            break;
        }
        prev = walker;
        walker = walker->next;
    }
}


void IndexNodeList::printIndexList() const {
    IndexNode *walker = head;

    if (head == nullptr) {
        cout<<"List is empty"<<endl;
        return;
    }
    while (walker != nullptr) {
        cout<<walker->index<< " -> ";
        walker = walker->next;
    }
    cout<<endl;
}

int IndexNodeList::getIndexCount() const {
    int totalIndex = 0;
    IndexNode *walker(head);

    while (walker != nullptr) {
        totalIndex += 1;
        walker = walker->next;
    }

    return totalIndex;
}
