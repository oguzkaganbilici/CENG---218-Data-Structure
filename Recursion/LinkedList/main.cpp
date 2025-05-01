#include <iostream>
class Node {
public:
    int data;
    Node *next;

    Node(int data): data(data), next(nullptr) {};
};
class LList {
private:
    Node *head;
public:
    LList(): head(nullptr) {};
    int getSize() const {
        return getSize(head);
    }
    void clear() {
        head = clear(head);
    }
    void deleteLast() {
        head = deleteLast(head);
    }
    void append(int data) {
        Node *newNode = new Node(data);

        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node *walker(head);

        while (walker != nullptr) {
            if (walker -> next == nullptr) {
                walker->next = newNode;
                break;
            }
            walker = walker->next;
        }
    }
    void printList() const {
        return printList(head);
    }
private:
    int getSize(Node *n) const {
        if (n == nullptr) return 0;
        return 1+getSize(n->next);
    }
    Node *clear(Node *n) {
        if (n == nullptr) return nullptr;
        n->next = clear(n->next);
        delete n;
        return nullptr;
    }
    Node *deleteLast(Node *n) {
        if (n == nullptr) return nullptr;
        if (n->next == nullptr) {
            delete n;
            return nullptr;
        }
        n->next = deleteLast(n->next);
        return n;
    }
    void printList(Node *n) const {
        if (n == nullptr) return;
        std::cout<<n->data<<" -> ";
        printList(n->next);
    }
};
int main() {
    LList list1;
    for (int i=0;i<10;i++) {
        list1.append(i);
    }
    std::cout<<"Size of list: "<<list1.getSize()<<std::endl;
    list1.printList();
    std::cout<<std::endl;
    //list1.clear();
    //std::cout<<"Size of list: "<<list1.getSize()<<std::endl;
    list1.deleteLast();
    std::cout<<"Size of list: "<<list1.getSize()<<std::endl;
    list1.printList();
    return 0;
}
