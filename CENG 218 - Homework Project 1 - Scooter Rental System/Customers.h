//
// Created by Oğuz Kağan Bilici on 23.03.2025.
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
};



#endif //CUSTOMERS_H
