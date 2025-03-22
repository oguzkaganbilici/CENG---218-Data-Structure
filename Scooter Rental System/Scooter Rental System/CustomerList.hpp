//
//  CustomerList.hpp
//  Scooter Rental System
//
//  Created by Oğuz Kağan Bilici on 22.03.2025.
//

#ifndef CustomerList_hpp
#define CustomerList_hpp

#include <stdio.h>
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
    int getTotalCustomerNumber() const;
    void uploadCustomerFile(const string& filename="customers.txt");
    
};


#endif /* CustomerList_hpp */
