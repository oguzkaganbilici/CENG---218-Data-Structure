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
    ~LinkedList()
    {
        Node *temp;
        while(head != nullptr)
        {
            temp = head;
            head = head -> next;
            delete temp;
        }
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
    
    int getSize() // Get size of
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
        
        if(head -> name == name)
        {
            Node* temp = head;
            head = head -> next;
            delete temp;
            count --;
            return true;
        }
        Node *walker = head;
        Node *prev = nullptr;
        while( walker != nullptr)
        {
            if(walker->name == name)
            {
                prev -> next = walker -> next;
                count --;
                return true;
            }
            prev = walker;
            walker = walker ->next;
        }
        
        cout<<"There is not "<<name<< " in the list"<<endl;
        return false;
    }
    void insertAt(string key, int index)
    {
        Node *newNode = new Node(key);
        if(index == 0)
        {
            newNode->next = head;
            head = newNode;
            count++;
        }
        if(index <= getSize() && index > 0)
        {
            Node *walker = head, *prev = nullptr;
            int indexCounter = 0;
            while(walker != nullptr)
            {
                if(indexCounter == index)
                {
                    prev -> next = newNode;
                    newNode -> next = walker;
                    count++;
                }
                indexCounter++;
                prev = walker;
                walker = walker -> next;
            }
        }
    }
    
    void collapse()
    {
        Node *walker = head;
        
        while(walker != nullptr && walker->next != nullptr)
        {
            if(walker->name == walker->next->name)
            {
                Node *temp = walker->next;
                walker->next = walker->next->next;
                delete temp;
                count--;
            }
            else
            {
                walker = walker->next;
            }
        }
    }
    void deleteLast()
    {
        Node *walker = head, *prev = nullptr;
        
        while(walker != nullptr)
        {
            if(walker -> next == nullptr)
            {
                Node *temp = walker;
                prev->next = nullptr;
                delete temp;
            }
            prev = walker;
            walker = walker -> next;
        }
    }
    void moveToFront(string key)
    {
        Node *walker = head, *prev = nullptr;
        
        if(head -> name == key)
        {
            return;
        }
        
        while(walker != nullptr)
        {
            if(walker->name == key)
            {
                prev->next = walker -> next;
    
                walker -> next = head;
                head = walker;
                return;
            }
            prev = walker;
            walker = walker -> next;
        }
    }
    
    void deleteMax()
    {
        Node *walker = head;
        int max = 0;
        
        while(walker != nullptr)
        {
            if(max < walker -> name)
            {
                max = walker -> name;
            }
            walker = walker -> next;
        }
        
        Node *walker2 = head, *prev = nullptr;
        while(walker2 != nullptr)
        {
            if(head -> name == max)
            {
                head = head -> next;
                return;
            }
            if(walker2 -> name == max)
            {
                prev -> next = walker2 -> next;
                return;
            }
            
            prev = walker2;
            walker2 = walker2 -> next;
        }
        
    }
	bool isClone(LinkedList &LList)
	{
	    Node *walker1 = head;
	    Node *walker2 = LList.head;
	    if(walker1 == nullptr || walker2 == nullptr)
	        return false;
	        
	    while(walker1 != nullptr && walker2 != nullptr)
	    {
	        if(walker1 -> name != walker2 -> name)
	        {
	            return false;
	        }
	        
	        walker1 = walker1 -> next;
	        walker2 = walker2 -> next;
	    }
	    
	    
	    return true;
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
    newList.insertFront("Adnan");
    newList.print();
    newList.insertFront("Adnan");
    newList.print();
    newList.append("Aybüke");
    newList.print();
    newList.append("Aybüke");
    newList.print();
    newList.append("Aybüke");
    newList.print();
    newList.append("Aybüke");
    newList.print();
    newList.append("Aybüke");
    newList.print();
    
    /*
    newList.removeFirst();
    newList.print();
    */
    
    newList.search("Oğuz Kağan");
    newList.search("deneme");
    
    cout<<"Size of the list is: "<<newList.getSize()<<endl;
    
    newList.append("Urungu");
    newList.print();
    cout<<"------"<<endl;
    newList.deleteNode("Urungu");
    newList.print();
    newList.insertAt("Oğuz", 2);
    newList.print();
    newList.insertAt("Oğuz", 2);
    newList.print();
    newList.insertAt("Oğuz", 2);
    newList.print();
    newList.insertAt("Sabri cavus", 0);
    newList.print();
    
    //newList.~LinkedList();
    //newList.print();
    newList.collapse();
    newList.print();
    newList.append("deneme");
    newList.print();
    newList.deleteLast();
    newList.print();
    
    newList.moveToFront("Oğuz");
    newList.print();
    
    return 0;
}
