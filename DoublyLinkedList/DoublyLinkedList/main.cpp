    //
    //  main.cpp
    //  DoublyLinkedList
    //
    //  Created by Oğuz Kağan Bilici on 20.03.2025.
    //

    #include <iostream>
    using namespace std;

    class DLNode
    {
    public:
        DLNode *next;
        DLNode *prev;
        int data;
        
        DLNode(int d): data(d), next(nullptr), prev(nullptr) {};
    };
    class DLLinkedList
    {
    private:
        DLNode *head;
        DLNode *tail;

    public:
        DLLinkedList(): head(nullptr), tail(nullptr){};
        
        int getSize()
        {
            DLNode *walker = head;
            int size = 0;
            while(walker != nullptr)
            {
                size++;
                walker = walker -> next;
            }
            return size;
        }
        
        void deleteNode(int element)
        {
            DLNode *walker = head;
            
            if(head == nullptr)
            {
                cout<<"List is empty"<<endl;
                return;
            }
            
            while(walker != nullptr)
            {
                if(walker -> data == element)
                {
                    if(walker == head && walker == tail)
                    {
                        head = tail = nullptr;
                        delete walker;
                        return;
                    }
                    
                    else if(walker == tail)
                    {
                        tail = tail -> prev;
                        tail -> next = nullptr;
                        delete walker;
                        return;
                    }
                    else if(walker == head)
                    {
                        head = head -> next;
                        head -> prev = nullptr;
                        delete walker;
                        return;
                    }
                    else
                    {
                        walker -> prev -> next = walker -> next;
                        walker -> next -> prev = walker -> prev;
                        delete walker;
                        return;
                    }
                }
                walker = walker -> next;
            }
        }
        
        void insertAt(int index, int data)
        {
            int count = 0;
            DLNode *walker = head;
            DLNode *newNode = new DLNode(data);
            
            int size = getSize();
            if(index >= 0 && index <= size)
            {
                if(head == nullptr)
                {
                    head = tail = newNode;
                    return;
                }
                else if(index == 0)
                {
                    newNode -> next = head;
                    head -> prev = newNode;
                    head = newNode;
                    return;
                }
                else if(index == size)
                {
                    tail -> next = newNode;
                    newNode -> prev = tail;
                    tail = newNode;
                    return;
                }
                else
                {
                    while(walker != nullptr)
                    {
                        if(count == index)
                        {
                            newNode -> next = walker;
                            newNode -> prev = walker -> prev;
                            
                            walker -> prev -> next = newNode;
                            walker -> prev = newNode;
                            
                            return;
                        }
                        count++;
                        walker = walker -> next;
                    }
                }
            }
        }
        
        void printForward() const
        {
            DLNode *walker = head;
            
            if(head == nullptr)
            {
                cout<<"List is empty!"<<endl;
                return;
            }
            while(walker != nullptr)
            {
                cout<<walker -> data << "->";

                walker = walker -> next;
            }
            cout<<endl;
        }
        
        void printBackward() const
        {
            DLNode *walker = tail;
            
            if(head == nullptr)
            {
                cout<<"List is empty!"<<endl;
                return;
            }
            while(walker != nullptr)
            {
                cout<<walker -> data << "<-";
                walker = walker -> prev;
            }
            cout<<endl;
        }
        
        void reverse()
        {
            DLNode *walker = head;
            
            if(head == nullptr)
            {
                cout<<"List is empty"<<endl;
                return;
            }
            if(walker == head && walker == tail)
            {
                cout<<"List is already sorted"<<endl;
                return;
            }
            DLNode *temp = nullptr;
            while(walker != nullptr)
            {
                temp = walker -> next;
                walker->next = walker -> prev;
                walker -> prev = temp;
                walker = temp;
            }
            temp = head;
            head = tail;
            tail = temp;
            
        }
        
    };


    int main(int argc, const char * argv[]) {
        
        DLLinkedList *list1 = new DLLinkedList();
        list1->insertAt(0, 1);
        list1->insertAt(1, 2);
        list1->insertAt(2, 3);
        list1->insertAt(3, 4);
        list1->insertAt(4, 5);
        list1->insertAt(5, 6);
        list1->insertAt(6, 7);
        list1->insertAt(7, 8);
        list1->printForward();
        list1->reverse();
        list1->printForward();
        return 0;
    }
