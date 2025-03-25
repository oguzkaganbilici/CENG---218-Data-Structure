//
// Created by Oğuz Kağan Bilici on 23.03.2025.
//

#ifndef SCOOTERLIST_H
#define SCOOTERLIST_H

#include<iostream>
#include "Scooter.h"

class ScooterList {
private:
    Scooter *head;

    int totalScooterCount;
    int scooterID;
public:
    ScooterList();

    void addScooter(string loc, int stats, int battery, int distance, string data);
    void addScooter(const Scooter& scooter);

    void displayAllScooters(int index) const;
    void uploadScooterFile(const string& filename);
    void deleteScooter(int index);
    void updateScooter(int index, string loc, int battery, int distance);
};



#endif //SCOOTERLIST_H
