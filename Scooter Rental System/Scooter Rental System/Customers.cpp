//
//  Customers.cpp
//  Scooter Rental System
//
//  Created by Oğuz Kağan Bilici on 22.03.2025.
//

#include <stdio.h>
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

