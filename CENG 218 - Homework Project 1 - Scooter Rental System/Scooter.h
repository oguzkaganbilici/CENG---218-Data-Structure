//
// Created by Oğuz Kağan Bilici on 23.03.2025.
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

    Scooter *next;

    Scooter(int id, string loc, int stats, int battery, int distance, string data);

};



#endif //SCOOTER_H
