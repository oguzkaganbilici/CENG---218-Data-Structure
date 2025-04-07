//
//  main.cpp
//  linkedListExample
//
//  Created by Oğuz Kağan Bilici on 7.04.2025.
//

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    
    Node(int d)
    {
        data = d;
        next = nullptr;
    }
};

class LinkedList
{
private:
    Node *head;
    int counter;
    
public:
    LinkedList()
    {
        head = nullptr;
        counter = 0;
    }
    
    void append(int data) // sona ekle
    {
        Node *newNode = new Node(data);
        Node *walker = head;
        
        if(head == nullptr)
        {
            head = newNode;
            counter++;
            return;
        }
        if(head -> next == nullptr)
        {
            head -> next = newNode;
            counter++;
            return;
        }
        while(walker -> next != nullptr)
        {
            walker = walker -> next;
        }
        walker -> next = newNode;
        counter++;
        return;
    }
    void printLinkedList() const{
        Node *walker = head;
        
        if(head == nullptr)
        {
            cout<<"List is empty"<<endl;
            return;
        }
        while(walker != nullptr)
        {
            cout<<walker->data<<" -> ";
            walker = walker->next;
        }
        cout<<endl;
    }
    
    void deleteFirst()
    {
        if(head == nullptr)
        {
            cout<<"List is empty"<<endl;
            return;
        }
        
        Node *temp = head;
        head = head -> next;
        delete temp;
        printLinkedList();
        
    }
    
    void deleteLast()
    {

        if(head == nullptr)
        {
            cout<<"List is empty"<<endl;
            return;
        }
        if(head -> next == nullptr)
        {
            delete head;
            head = nullptr;
            counter--;
            printLinkedList();
            return;
        }
        
        Node *walker = head;
        while(walker -> next -> next != nullptr)
        {
            walker = walker->next;
        }
        delete walker->next;
        walker -> next = nullptr;
        
        printLinkedList();
    }
    
    void deleteElement(int element){
        if(head == nullptr)
        {
            cout<<"List is empty"<<endl;
            return;
        }
        if(head -> data == element && head->next == nullptr)
        {
            delete head;
            head = nullptr;
            counter--;
            printLinkedList();
            return;
        }
        if(head -> data == element)
        {
            Node *temp = head;
            head = head -> next;
            delete temp;
            printLinkedList();
            return;
        }
        
        Node *walker = head;
        Node *prev = nullptr;
        while(walker -> next != nullptr)
        {
            if(walker->data == element)
            {
                prev->next = walker->next;
                walker = nullptr;
                printLinkedList();
                return;
            }
            prev = walker;
            walker = walker->next;
        }
        
    }
    
    int totalCount() const
    {
        int total = 0;
        Node *walker = head;
        if(head == nullptr)
        {
            return 0;
        }
        
        while(walker != nullptr)
        {
            total++;
            walker = walker->next;
        }
        return total;
    }
    
    void reverseList()
    {
        Node *walker = head;
        Node *prev = nullptr;
        LinkedList *newList = new LinkedList;
        
        if(head == nullptr)
        {
            cout<<"List is empty!"<<endl;
            return;
        }
        while(walker -> next -> next)
        {
            walker = walker->next;
        }
        
    }
    /*
    
    6. Bağlantılı Listeyi Tersine Çevirme
    Problem: Bir linked list oluşturun ve listedeki elemanları tersine çevirin. Ters çevirdikten sonra, yeni listeyi ekrana yazdırın.

    7. Ortadaki Elemanı Bulma
    Problem: Bir linked list oluşturun ve listedeki ortadaki elemanı bulun. Eğer liste çift sayıda elemandan oluşuyorsa, ortadaki iki elemanın ortalamasını alarak yazdırın.

    8. Düzgün ve Döngü Kontrolü
    Problem: Bir linked list oluşturun ve listenin düzgün olup olmadığını kontrol edin. Yani, döngü (cycle) olup olmadığını tespit edin. Eğer varsa, bu döngüyü yakalayın ve çıkış noktası ile ilgili bilgi verin.

    9. İki Linked List’i Birleştirme
    Problem: İki ayrı linked list oluşturun ve bu iki listeyi birleştirerek tek bir linked list oluşturun. Yeni listeyi yazdırın.

    10. Döngü Tespiti ve Kaldırma
    Problem: Bir linked list oluşturun ve belirli bir noktada döngü oluşturun. (Örneğin, son eleman, listenin ortasında bir elemanı işaret etsin). Daha sonra, döngü oluşup oluşmadığını kontrol edin ve varsa döngüyü kaldırın.
   */
};

int main(int argc, const char * argv[]) {
    LinkedList list1;
    for(int i=0;i<=100;i+=10)
    {
        list1.append(i);
    }
    list1.printLinkedList();
    /*
    for(int i=0;i<=11;i++)
    {
        list1.deleteLast();
    }
    
    for(int i=0;i<=100;i+=10)
    {
        list1.deleteElement(i);
    }
     */
    
    cout<<list1.totalCount()<<endl;
    return 0;
}
