//
// Created by Oğuz Kağan Bilici on 23.03.2025.
//

#ifndef SCOOTERRENTALSYSTEM_H
#define SCOOTERRENTALSYSTEM_H

#include<iostream>
#include "Customers.h"
#include "Scooter.h"


class ScooterRentalSystem {
private:
    Customers *customerHead;
    Scooter *scooterHead;

    int customerCounter, totalCustomerCounter;
    int scooterCounter, totalScooterCounter;

public:
    ScooterRentalSystem(): customerHead(nullptr),scooterHead(nullptr), customerCounter(1), totalCustomerCounter(0), scooterCounter(1), totalScooterCounter(0) {};

    void addScooter(const Scooter& scooter); //Adds a new scooter to the system.
    void addScooter(const std::string &loc, int stats, int battery, int distance, const std::string &date);
    void listAvailableScooters() const; //Lists all scooters that are available.

    void rentScooter(int scooterId, int customerId); //Rents a scooter to a customer.
    void returnScooter(int scooterId); //Returns a rented scooter.

    void uploadScooterTxt(const string& filename="scooters.txt"); //Adds a new scooter.
    void deleteScooter(int scooterId); //Deletes a scooter from the system.
    void updateScooter(int scooterId, string location, int battery_level, int distance); //Updates an existing scooter’s details.

    void registerCustomer(const Customers& customer); //Registers a new customer.
    void registerCustomer(string name_surname, string telephone, string email, string address);
    void displayCustomerInformation() const;
    void uploadCustomerTxt(const string& filename="customers.txt");
    void deleteCustomer(int customerId); //Deletes a customer from the system.
    void updateCustomer(int customerId, std::string name_surname, std::string telephone, std::string email, std::string
address); //Updates customer details.

    void viewCustomerHistory(int customerId); //Displays a customer’s rental history.

};


#endif //SCOOTERRENTALSYSTEM_H
