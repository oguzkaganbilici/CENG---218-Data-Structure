//
// Created by Oðuz Kaðan Bilici on 23.03.2025.
//

#include "Scooter.h"

Scooter::Scooter(int id, string loc, int stats, int battery, int distance, string data) : next(nullptr), id(id), location(loc), status(stats), battery_level(battery), distance(distance), last_usage_date(data) {};

int Scooter::getId() const {
    return id;
}
string Scooter::getLocation() const {
    return location;
}
int Scooter::getStatus() const {
    return status;
}
int Scooter::getBatteryLevel() const {
    return battery_level;
}
int Scooter::getDistance() const {
    return distance;
}
string Scooter::getLastUsageDate() const {
    return last_usage_date;
}

void Scooter::rent() //Marks the scooter as rented.
{
    status = 1;
}
void Scooter::returnScooter() //Marks the scooter as available again.
{
    status = 0;
}
void Scooter::updateDetails(int status, int battery_level, int distance, std::string last_usage_date) {
    status = status;
    battery_level = battery_level;
    distance = distance;
    last_usage_date = last_usage_date;
}