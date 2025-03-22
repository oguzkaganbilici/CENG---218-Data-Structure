//
//  CustomerList.cpp
//  Scooter Rental System
//
//  Created by Oğuz Kağan Bilici on 22.03.2025.
//

#include "CustomerList.hpp"
#include<iomanip> // verileri daha düzenli göstermek için
#include<iostream>
#include<fstream>
#include<sstream>

using namespace std;

CustomerList::CustomerList(): head(nullptr), customerCounter(1), totalCustomerNumber(0){};

void CustomerList::displayCustomerInformation() const
{
    Customers *walker = head;
    
    if(head == nullptr)
    {
        cout<<"There is not any customers"<<endl;
        return;
    }
    
    cout << left
                     << setw(5)  << "ID"
                     << setw(25) << "Name and Surname"
                     << setw(15) << "Phone Number"
                     << setw(40) << "E-mail"
                     << setw(25) << "Address" << endl;
    cout << "-------------------------------------------------------------------------------------------------------" << endl;
    
    while(walker != nullptr)
    {
        cout << left
             << setw(5)  << walker->customerID
             << setw(25) << walker->customerName_customerSurname
             << setw(15) << walker->customerTelephone
             << setw(40) << walker->customerEmail
             << setw(25)  << walker->customerAddress
             << endl;

        walker = walker -> next;
    }
    
    cout<<"Total customer number: "<<getTotalCustomerNumber()<<endl;
}
void CustomerList::registerNewCustomer(string name_surname, string telephone, string email, string address)
{
    Customers *newNode = new Customers(customerCounter, name_surname, telephone, email, address);
    Customers *walker = head;
    
    if(head == nullptr)
    {
        head = newNode;

    }
    else
    {
        while(walker != nullptr)
        {
            if(walker->next == nullptr)
            {
                walker->next = newNode;
                break;
            }
            walker = walker->next;
        }
    }
    cout<<"New customer is added: "<<newNode -> customerName_customerSurname<<endl;
    totalCustomerNumber++;
    customerCounter++;
}

void CustomerList::deleteCustomer(int id)
{
    if(head == nullptr)
    {
        cout<<"There is not any customer!"<<endl;
        return;
    }
    
    if(head -> customerID == id)
    {
        cout<<"The customer is deleted!: "<< head->customerName_customerSurname <<endl;
        Customers *temp = head;
        head = head -> next;
        delete temp;
        totalCustomerNumber--;
        return;
    }
    else
    {
        Customers *walker = head, *prev = nullptr;
        
        while(walker != nullptr)
        {
            if(walker -> customerID == id)
            {
                prev->next = walker->next;
                cout<<"The customer is deleted!: "<< walker->customerName_customerSurname<<endl;
                delete walker;
                totalCustomerNumber--;
                return;
            }
            prev = walker;
            walker = walker -> next;
        }
        cout<<"The customer cannot be found!"<<endl;
    }
}
int CustomerList::getTotalCustomerNumber() const
{
    return totalCustomerNumber;
}

void CustomerList::uploadCustomerFile(const string& filename)
{
    ifstream customerFile(filename);
    
    if(!customerFile.is_open())
    {
        cerr << "The file is not found!"<<endl;
    }
    
    string lines;
    while(getline(customerFile, lines))
    {
        stringstream ss(lines);
        
        string name_surname;
        string telephone;
        string email;
        string address;
        

        getline(ss, name_surname, ',');
        getline(ss, telephone, ',');
        getline(ss, email, ',');
        getline(ss, address, ',');
        
        registerNewCustomer(name_surname, telephone, email, address);
    }
    customerFile.close();
}
