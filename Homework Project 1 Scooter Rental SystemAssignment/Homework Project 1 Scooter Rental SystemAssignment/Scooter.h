//
// Created by Oðuz Kaðan Bilici on 23.03.2025.
//

#ifndef SCOOTER_H
#define SCOOTER_H

#include <iostream>
using namespace std;

class Scooter {
public:
    int id;
    string location;
    int status;
    int battery_level;
    int distance;
    string last_usage_date;

    Scooter* next;

    Scooter(int id, string loc, int stats, int battery, int distance, string data);

    int getId() const;
    string getLocation() const;
    int getStatus() const;
    int getBatteryLevel() const;
    int getDistance() const;
    string getLastUsageDate() const;

    void rent(); //Marks the scooter as rented.
    void returnScooter();//Marks the scooter as available again.
    void updateDetails(int status, int battery_level, int distance, std::string last_usage_date);


};



#endif //SCOOTER_H