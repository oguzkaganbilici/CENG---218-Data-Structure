//
//  main.cpp
//  Scooter Rental System
//
//  Created by Oğuz Kağan Bilici on 22.03.2025.
//

#include <iostream>
#include "CustomerList.hpp"

using namespace std;


int main(int argc, const char * argv[]) {
    CustomerList *newCustomerList = new CustomerList();
    newCustomerList->uploadCustomerFile();
    /*
    newCustomerList->registerNewCustomer("Oğuz Kağan Bilici", "0541 864 8389", "deneme@trt.net.tr", "Ankara Gölbaşı");
    newCustomerList->registerNewCustomer("Adnan Bilici", "0505 375 9289", "adnanbilici@trt.net.tr", "Ordu Fatsa");
    newCustomerList->registerNewCustomer("Selda Bilici", "0505 375 9289", "seldabilici@trt.net.tr", "Ordu Kumru");

    newCustomerList->displayCustomerInformation();
    newCustomerList->deleteCustomer(2);
    newCustomerList->displayCustomerInformation();
    
    newCustomerList->registerNewCustomer("Sıla Bilici", "0505 375 9289", "sılabilici@trt.net.tr", "Ordu Çankaya");
    newCustomerList->registerNewCustomer("Sıla Bilici", "0505 375 9289", "sılabilici@trt.net.tr", "Ordu Çankaya");
    newCustomerList->registerNewCustomer("Sıla Bilici", "0505 375 9289", "sılabilici@trt.net.tr", "Ordu Çankaya");
    newCustomerList->registerNewCustomer("Sıla Bilici", "0505 375 9289", "sılabilici@trt.net.tr", "Ordu Çankaya");
    newCustomerList->registerNewCustomer("Sıla Bilici", "0505 375 9289", "sılabilici@trt.net.tr", "Ordu Çankaya");
    newCustomerList->displayCustomerInformation();
    
    
    newCustomerList->deleteCustomer(1);
    newCustomerList->deleteCustomer(5);
    newCustomerList->displayCustomerInformation();
     */
        
    return 0;
}
