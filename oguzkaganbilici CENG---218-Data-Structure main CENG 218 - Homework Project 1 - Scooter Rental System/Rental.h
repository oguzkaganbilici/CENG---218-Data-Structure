//
// Created by oguz.bilici on 24.03.2025.
//

#ifndef RENTAL_H
#define RENTAL_H

#include<iostream>
using namespace std;

class Rental {
public:
    int scooterID, customerID;
    string rentDate, returnDate;

    Rental* next;

    Rental(int sID, int cID, string rentanDate): scooterID(sID), customerID(cID), rentDate(rentanDate),
    returnDate("Not returned"), next(nullptr) {};


};



#endif //RENTAL_H
