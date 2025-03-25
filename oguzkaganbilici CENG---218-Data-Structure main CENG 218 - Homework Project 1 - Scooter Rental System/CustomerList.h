//
// Created by Oğuz Kağan Bilici on 23.03.2025.
//

#ifndef CUSTOMERLIST_H
#define CUSTOMERLIST_H

#include <iostream>
#include "Customers.h"

using namespace std;

class CustomerList
{
private:
    Customers *head;
    int customerCounter, totalCustomerNumber;

public:
    CustomerList();

    void displayCustomerInformation() const;
    void registerNewCustomer(string name_surname, string telephone, string email, string address);
    void deleteCustomer(int id);
    void updateCustomer(int id, string name_surname, string telephone, string email, string address);
    int getTotalCustomerNumber() const;
    void uploadCustomerFile(const string& filename="customers.txt");

};


#endif //CUSTOMERLIST_H
