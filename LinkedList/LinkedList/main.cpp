//
//  main.cpp
//  LinkedList
//
//  Created by Oğuz Kağan Bilici on 7.03.2025.
//

#include <iostream>
using namespace std;

class Node
{
public:
    string name;
    Node *next;
    
    Node(string n)
    {
        name = n;
        next = nullptr;
    }
};

class LinkedList
{
private:
    Node *head;
    int count;
    
public:
    LinkedList()
    {
        head = nullptr;
        count = 0;
    }
    
    void insertFront(string name)// Insert at beginning
    {
        Node* newNode = new Node(name);
        newNode->next = head;
        head = newNode;
        count++;
    }
    
    void removeFirst()  // Remove first element
    {
        if(head != nullptr)
        {
            Node *temp = head;
            head = head -> next;
            delete temp;
            count--;
        }
        else
            cout<<"The list is empty!"<<endl;
    }
    const void print () // Print the list
    {
        Node *walker = head;
        cout<< "LinkedList: ";
        while(walker != nullptr)
        {
            cout<< walker->name << "->";
            walker = walker->next;
        }
        cout<<endl;
        
        delete walker;
    }
    
    bool search(string name)      // Search for a value
    {
        Node *walker = head;
        
        while(walker != nullptr)
        {
            if(walker->name == name)
            {
                cout<<"Yes, there is " <<name<< " in the list"<<endl;
                return true;
            }
            walker = walker ->next;
        }
        cout<<"No, there is NOT " <<name<< " in the list"<<endl;;
        
        return false;
    }
    
    int size() // Get size of
    {
        return count;
    }
    
    void append(string name)      // Insert at end
    {
        Node *nPtr = new Node(name);
        
        if(head == nullptr) // list is empty
            head = nPtr;
        else
        {
            Node *walker = head;
            while(walker->next != nullptr)
            {
                walker = walker->next;
            }
            walker -> next = nPtr;
            count ++;
        }
    }
    
    bool deleteNode(string name)  // Delete first occurrence of val
    {
        
        if(head == nullptr)
        {
            cout<<"List is empty"<<endl;
            return false;
        }
        
        if(name == head -> name)
        {
            Node* temp = head;
            head = head -> next;
            delete temp;
            count --;
            return true;
        }
        Node *walker = head;
        
        while(walker->next != nullptr)
        {
            if(walker->next->name == name)
            {
                Node *deletedNode = walker -> next;
                walker -> next = walker -> next -> next;
                delete deletedNode;
                cout<<"Deleted: "<<name<<endl;
                count --;
                return true;
            }
            walker = walker ->next;
        }
        
        cout<<"There is not "<<name<< " in the list"<<endl;
        return false;
    }

};

int main(int argc, const char * argv[]) {
    LinkedList newList;
    newList.insertFront("Oğuz Kağan");
    newList.print();
    newList.insertFront("Sıla");
    newList.print();
    newList.insertFront("Selda");
    newList.print();
    newList.insertFront("Adnan");
    newList.print();
    
    /*
    newList.removeFirst();
    newList.print();
    */
    
    newList.search("Oğuz Kağan");
    newList.search("deneme");
    
    cout<<"Size of the list is: "<<newList.size()<<endl;
    
    newList.append("Urungu");
    newList.print();
    cout<<"------"<<endl;
    newList.deleteNode("Urungu");
    newList.print();

    
    return 0;
}
