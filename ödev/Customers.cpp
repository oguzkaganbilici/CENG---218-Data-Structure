//
// Created by Oğuz Kağan Bilici on 23.03.2025.
//

#include "Customers.h"

Customers::Customers(int id, string name_surname, string telephone, string email, string address)
{
    customerID = id;
    customerName_customerSurname= name_surname;
    customerTelephone = telephone;
    customerEmail = email;
    customerAddress = address;

    next = nullptr;
}

int Customers::getId() const {
    return customerID;
}
string Customers::getNameSurname() const {
    return customerName_customerSurname;
}
string Customers::getTelephone() const {
    return customerTelephone;
}
string Customers::getEmail() const {
    return customerEmail;
}
string Customers::getAddress() const {
    return customerAddress;
}