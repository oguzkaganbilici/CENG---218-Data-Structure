//
// Created by Oðuz Kaðan Bilici on 23.03.2025.
//

#ifndef CUSTOMERS_H
#define CUSTOMERS_H


#include<iostream>
#include<string>
using namespace std;

class Customers {
public:
    int customerID;
    string customerName_customerSurname;
    string customerTelephone;
    string customerEmail;
    string customerAddress;

    Customers* next;

    Customers(int id, string name_surname, string telephone, string email, string address);

    int getId() const;
    string getNameSurname() const;
    string getTelephone() const;
    string getEmail() const;
    string getAddress() const;
};



#endif //CUSTOMERS_H