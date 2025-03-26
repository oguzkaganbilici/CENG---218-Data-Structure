//
// Created by Oğuz Kağan Bilici on 23.03.2025.
//

#include "ScooterList.h"
#include "Scooter.h"
#include<iomanip> // verileri daha düzenli göstermek için
#include<iostream>
#include<fstream>
#include<sstream>

using namespace std;

ScooterList::ScooterList(): head(nullptr), totalScooterCount(0), scooterID(1) {};

void ScooterList::addScooter(string loc, int stats, int battery, int distance, string data) {
    Scooter *newScooter = new Scooter(scooterID, loc, stats, battery, distance, data);
    Scooter *walker = head;

    if (head == nullptr) {
        head = newScooter;
    }
    else {
        while (walker != nullptr) {
            if (walker -> next == nullptr) {
                walker -> next  = newScooter;
                break;
            }
            walker = walker -> next;
        }
    }
    cout<<"Registering new scooter..."<<endl;
    cout<<"Scooter has been added successfully."<<endl;

    totalScooterCount++;
    scooterID++;
}

void ScooterList::displayAllScooters(int index) const {
    Scooter *walker = head;

    if (head == nullptr) {
        cout<<"There is not any scooter"<<endl;
    }
    else {
        while (walker != nullptr) {
            if (walker -> id == index) {
                    cout<<"- Scooter "<<walker->id << ": Location: " << walker -> location <<
                        ", Status: " << ((walker -> status == 0) ? "Available" : "Rented") <<
                            ", Battery Level: " << walker -> battery_level << ", Distance: " << walker -> distance <<
                                " km, Last Usage: " << walker-> last_usage_date << endl;
            }
            walker = walker->next;
        }
    }
}

void ScooterList::uploadScooterFile(const string& filename="scooters.txt") {
    ifstream scooterList(filename);
    if (!scooterList.is_open()) {
        cerr<<"The file is not found!"<<endl;
    }
    string lines;
    getline(scooterList, lines);

    while (getline(scooterList, lines)) {
        stringstream ss(lines);

        string idStr, location, batteryStr, statusStr,  distanceStr, lastUsageDate;
        getline(ss, idStr, ',');
        getline(ss, location, ',');
        getline(ss, batteryStr, ',');
        getline(ss, statusStr, ',');
        getline(ss, distanceStr, ',');
        getline(ss, lastUsageDate, ',');

        int id = stoi(idStr);
        int status = stoi(statusStr);
        int battery_level = stoi(batteryStr);
        int distance = stoi(distanceStr);

        addScooter(location, status, battery_level, distance, lastUsageDate);
    }
    scooterList.close();
}

void ScooterList::deleteScooter(int index) {
    Scooter *walker = head, *prev = nullptr;

    if (head == nullptr) {
        cout<<"List is empty! There is not any scooter"<<endl;
        return;
    }
    if (walker == head && walker->next == nullptr) {
        head = head -> next;
        delete walker;
        totalScooterCount--;
        return;
    }
    while (walker != nullptr) {
        if (walker -> id == index) {
            cout<<"Deleting scooter"<<walker ->id <<"..."<<endl;
            prev->next = walker -> next;
            delete walker;
            totalScooterCount--;
            cout<<"Scooter "<<index<<" has been deleted from the system."<<endl;
            return;
        }
        else {
            cout<< "The scooter is not found.. Try again!"<<endl;
        }
        prev = walker;
        walker = walker -> next;
    }
}

void ScooterList::updateScooter(int index, string loc, int battery, int distance) {
    Scooter *walker = head;

    if (head == nullptr) {
        cout<<"List is empty! There is not any scooter"<<endl;
        return;
    }
    while (walker != nullptr) {
        if (walker -> id == index) {
            cout<<"Updating scooter "<< walker-> id <<"..."<<endl;
            walker -> location = loc;
            walker -> battery_level = battery;
            walker -> distance = distance;
            cout<<"Scooter "<<walker->id<<"'s details have been updated successfully"<<endl;
            break;
        }
        else {
            cout<< "The scooter is not found.. Try again!"<<endl;
        }

        walker = walker -> next;
    }

}