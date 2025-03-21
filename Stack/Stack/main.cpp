//
//  main.cpp
//  Stack
//
//  Created by Oğuz Kağan Bilici on 21.03.2025.
//

#include <iostream>
using namespace std;

#define MAX 100

class Stack
{
private:
    int array[MAX];
    int top;
public:
    Stack(): top(-1){};
    
    bool isEmpty(){
        return top == -1;
    }
    
    bool isFull()
    {
        return top == MAX - 1;
    }
    
    void push(int element)
    {
        if(top >= MAX -1) // top == MAX - 1 de calısır ama hata payını 0'a indirmek için bu                     sekil kullanım daha saglıklı
        {
            cout<<"stack is overflow"<<endl;
            exit(0);
        }
        top++;
        array[top] = element;
    }
    
    int pop()
    {
        if(isEmpty())
        {
            cout<<"List is empty"<<endl;
            exit(0);
        }
        int removedElement = array[top];
        top--;
        return removedElement;
    }
    
    void printStack() const
    {
        cout<<"------"<<endl;
        for(int i = top; i >= 0; i--)
            {
                
                cout<<array[i]<<endl;
        }
        cout<<"------"<<endl;
    }
    
    int peek()
    {
        if(isEmpty())
        {
            cout<<"List is empty"<<endl;
            exit(0);
        }
        return array[top];
    }
    
    bool isBalanced(int *exp)
    {
        Stack s;
        int i = 0;
        while(exp[i] != '\0')
        {
            if(exp[i] == '(')
                s.push(exp[i]);
            else if(exp[i] == ')')
            {
                if(s.isEmpty())
                    return false;
                else
                    s.pop();
            }
            i++;
        }
        
        if(s.isEmpty())
            return  true;
        return false;
    }
};

int main(int argc, const char * argv[]) {
    
    Stack *s = new Stack();
    
    cout<<s->isEmpty()<<endl;
    s->push(1);
    s->push(2);
    s->push(3);
    s->printStack();
    s->pop();
    s->pop();
    s->printStack();
    
    return 0;
}
