//
// Created by Oğuz Kağan Bilici on 23.03.2025.
//

#include "ScooterRentalSystem.h"
#include<iostream>
#include<fstream>
#include<sstream>
#include <ctime>
#include <chrono>
#include <string.h>

void ScooterRentalSystem::addScooter(const Scooter& scooter) {
    Scooter *newScooter = new Scooter(scooter);
    Scooter *walker = scooterHead;

    if (scooterHead == nullptr) {
        scooterHead = newScooter;
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

    scooterCounter++;
    totalScooterCounter++;
}
void ScooterRentalSystem::addScooter(const std::string &loc, int stats, int battery, int distance, const std::string &date) {
    Scooter newScooter(scooterCounter, loc, stats, battery, distance, date);
    addScooter(newScooter);
}
void ScooterRentalSystem::listAvailableScooters() const{
    Scooter *walker = scooterHead;
    bool flag = false;

    if (scooterHead == nullptr) {
        cout<<"There are no scooters in the system."<<endl;
    }
    else {
        while (walker != nullptr) {
            if (walker -> status == 0) {
                flag = true;
                cout<<"- Scooter "<<walker->id << ": Location: " << walker -> location <<
                    ", Status: " << ((walker -> status == 0) ? "Available" : "Rented") <<
                        ", Battery Level: " << walker -> battery_level << ", Distance: " << walker -> distance <<
                            " km, Last Usage: " << walker-> last_usage_date << endl;
            }
            walker = walker->next;
        }
    }
    if (!flag) {
        cout<<"No available scooters at the moment." << endl;
    }
}

void ScooterRentalSystem::rentScooter(int scooterId, int customerId) {
    cout << "Renting scooter " << scooterId<<" to customer "<< customerId<<"..."<<endl;
    Scooter *scooterWalker = findScooter(scooterId);
    Customers *customersWalker = findCustomers(customerId);

    if (!customersWalker) {
        cout<<"Customer cannot be found !"<<endl;
        return;
    }
    if (!scooterWalker) {
        cout<<"Scooter cannot be found!"<<endl;
        return;
    }
    if (scooterWalker -> status == 1) {
        cout<<"The scooter is already rented!"<<endl;
        return;
    }

    scooterWalker -> status = 1;
    scooterWalker -> last_usage_date = getCurrentDateTime();

    Rental *newRental = new Rental(scooterId, customerId, getCurrentDateTime());
    Rental *rentalWalker = rentalHead;

    if (rentalHead == nullptr) {
        rentalHead = newRental;
    }
    else {
        while (rentalWalker != nullptr) {
            if (rentalWalker -> next == nullptr) {
                rentalWalker -> next = newRental;
                return;
            }
            rentalWalker = rentalWalker -> next;
        }
    }
    cout << "Scooter " << scooterId << " has been rented to customer " << customerId << "." << endl;
}
void ScooterRentalSystem::returnScooter(int scooterId) {
    cout<<"Return scooter "<<scooterId<<"..."<<endl;
    Scooter *scooterWalker = findScooter(scooterId);

    if (!scooterWalker) {
        cout<<"Scooter cannot be found !"<<endl;
        return;
    }
    if (scooterWalker -> status == 0) {
        cout<<"The scooter was NOT rented"<<endl;
        return;
    }
    scooterWalker -> status = 0;
    scooterWalker->last_usage_date = getCurrentDateTime();

    Rental *rentalWalker = rentalHead;
    Rental *lastRental = nullptr;

    while (rentalWalker != nullptr) {
        if (rentalWalker -> scooterID == scooterId && rentalWalker->returnDate == "Not returned") {
            lastRental = rentalWalker;
        }
        rentalWalker = rentalWalker -> next;
    }

    if (lastRental) {
        lastRental -> returnDate = getCurrentDateTime();
        cout<<"Scooter "<<scooterId<<" has been returned and is now available."<<endl;
    }
    else {
        cout << "Error: No active rental found for this scooter!" << endl;
    }
}

void ScooterRentalSystem::uploadScooterTxt(const string& filename){
    ifstream scooterList(filename);
    if (!scooterList.is_open()) {
        cerr<<"The file is not found!"<<endl;
        return;
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
void ScooterRentalSystem::deleteScooter(int scooterId) {
    Scooter *walker = scooterHead, *prev = nullptr;

    if (scooterHead == nullptr) {
        cout<<"List is empty! There is not any scooter"<<endl;
        return;
    }
    if (walker->id == scooterId) {
        cout<<"Deleting scooter "<<walker ->id <<"..."<<endl;
        scooterHead = scooterHead -> next;
        delete walker;
        totalScooterCounter--;
        cout << "Scooter " << scooterId << " has been deleted from the system." << endl;
        return;
    }
    while (walker != nullptr) {
        if (walker -> id == scooterId) {
            cout<<"Deleting scooter "<<walker ->id <<"..."<<endl;
            prev -> next = walker -> next;
            delete walker;
            totalScooterCounter--;
            cout<<"Scooter "<<scooterId<<" has been deleted from the system."<<endl;
            return;
        }
        prev = walker;
        walker = walker -> next;
    }
    cout<< "The scooter is not found.. Try again!"<<endl;
}
void ScooterRentalSystem::updateScooter(int scooterId, string location, int battery_level, int distance, string last_usage_date) {
    Scooter *walker = scooterHead;

    if (scooterHead == nullptr) {
        cout<<"List is empty! There is not any scooter"<<endl;
        return;
    }
    while (walker != nullptr) {
        if (walker -> id == scooterId) {
            cout<<"Updating scooter "<< walker-> id <<"..."<<endl;
            walker -> location = location;
            walker -> battery_level = battery_level;
            walker -> distance = distance;
            walker -> last_usage_date = last_usage_date;
            cout<<"Scooter "<<walker->id<<"'s details have been updated successfully"<<endl;
            return;
        }
        walker = walker -> next;
    }
    cout<< "The scooter is not found.. Try again!"<<endl;
}

void ScooterRentalSystem::registerCustomer(const Customers& customer) {
    Customers *newCustomer = new Customers(customer);
    Customers *walker = customerHead;

    if(customerHead == nullptr)
    {
        customerHead = newCustomer;
    }
    else
    {
        while(walker != nullptr)
        {
            if(walker->next == nullptr)
            {
                walker->next = newCustomer;
                break;
            }
            walker = walker->next;
        }
    }
    cout<<"Registering new customer..."<<endl;
    cout<<"Customer has been added successfully."<<endl;
    customerCounter++;
    totalCustomerCounter++;
}
void ScooterRentalSystem::registerCustomer(string name_surname, string telephone, string email, string address) {
    Customers newCustomer(customerCounter, name_surname, telephone, email, address);

    registerCustomer(newCustomer);
}
void ScooterRentalSystem::uploadCustomerTxt(const string& filename) {
    ifstream customerFile(filename);

    if(!customerFile.is_open())
    {
        cerr << "The file is not found!"<<endl;
        return;
    }

    string lines;
    getline(customerFile, lines);
    while(getline(customerFile, lines))
    {
        stringstream ss(lines);

        int id;
        string name_surname;
        string telephone;
        string email;
        string address;

        ss>>id;
        ss.ignore(1, ',');
        getline(ss, name_surname, ',');
        getline(ss, telephone, ',');
        getline(ss, email, ',');
        getline(ss, address, ',');

        registerCustomer(name_surname, telephone, email, address);
    }
    customerFile.close();
}
void ScooterRentalSystem::deleteCustomer(int customerId) {
    if(customerHead == nullptr)
    {
        cout<<"There is not any customer!"<<endl;
        return;
    }
    cout<<"Deleting customer "<< customerId <<"..."<<endl;
    if(customerHead -> customerID == customerId)
    {
        Customers *temp = customerHead;
        customerHead = customerHead -> next;
        delete temp;
        totalCustomerCounter--;
        cout<<"Customer "<< customerId <<" has been deleted from the system."<<endl;
    }
    else
    {
        Customers *walker = customerHead, *prev = nullptr;

        while(walker != nullptr)
        {
            if(walker -> customerID == customerId)
            {
                prev->next = walker->next;

                delete walker;
                totalCustomerCounter--;
                cout<<"Customer "<< customerId <<" has been deleted from the system."<<endl;
                return;
            }
            prev = walker;
            walker = walker -> next;
        }
        cout<<"The customer cannot be found!"<<endl;
    }
}
void ScooterRentalSystem::updateCustomer(int customerId, std::string name_surname, std::string telephone, std::string email, std::string
address) {
    Customers *walker = customerHead;

    while(walker != nullptr)
    {
        if(walker -> customerID == customerId)
        {
            cout<<"Updating customer "<<customerId<<"..."<<endl;
            walker->customerName_customerSurname = name_surname;
            walker->customerTelephone = telephone;
            walker->customerEmail = email;
            walker->customerAddress = address;
            cout<<"Customer "<<customerId<<"'s details have been updated successfully."<<endl;
            return;
        }
        walker = walker -> next;
    }
    cout<<"The customer is NOT found!: "<<endl;
}

void ScooterRentalSystem::displayCustomerInformation() const {
    Customers *walker = customerHead;

    if(customerHead == nullptr)
    {
        cout<<"There is not any customers"<<endl;
        return;
    }

    cout << left
                     << setw(5)  << "ID"
                     << setw(25) << "Name and Surname"
                     << setw(15) << "Phone Number"
                     << setw(40) << "E-mail"
                     << setw(25) << "Address" << endl;
    cout << "-------------------------------------------------------------------------------------------------------" << endl;

    while(walker != nullptr)
    {
        cout << left
             << setw(5)  << walker->customerID
             << setw(25) << walker->customerName_customerSurname
             << setw(15) << walker->customerTelephone
             << setw(40) << walker->customerEmail
             << setw(25)  << walker->customerAddress
             << endl;

        walker = walker -> next;
    }

    cout<<"Total customer number: "<<totalCustomerCounter<<endl;
}

void ScooterRentalSystem::viewCustomerHistory(int customerId) {

    Customers *customersWalker = findCustomers(customerId);
    if (!customersWalker) {
        cout << "The customer cannot be found!" << endl;
        return;
    }

    cout << "Customer " << customerId << "'s Rental History:" << endl;
    bool foundHistory = false;

    Rental *rentalWalker = rentalHead;

    while (rentalWalker != nullptr) {
        if (rentalWalker->customerID == customerId) {

            int ScooterId = rentalWalker->scooterID;
            Scooter *ScooterWalker = findScooter(ScooterId);

            if (ScooterWalker) {
                string returnDate = (rentalWalker->returnDate.empty()) ? "Not Returned" : rentalWalker->returnDate;

                cout << "- Scooter " << ScooterId << ", Location: " << ScooterWalker->location
                     << ", Status: " << ((ScooterWalker->status == 0) ? "Available" : "Rented")
                     << ", Battery Level: " << ScooterWalker->battery_level
                     << ", Distance: " << ScooterWalker->distance << " km"
                     << ", Rental Date: " << rentalWalker->rentDate
                     << ", Return Date: " << returnDate << endl;

                foundHistory = true;
            }
            else {
                cout << "- Scooter " << ScooterId << " (No longer exists in the system)" << endl;
            }
        }
        rentalWalker = rentalWalker->next;
    }

    if (!foundHistory) {
        cout << "No rental history found for customer " << customerId << "." << endl;
    }
}



Customers* ScooterRentalSystem::findCustomers(int customerID) {
    Customers *walker = customerHead;
    while (walker != nullptr) {
        if (walker -> customerID == customerID) {
            return walker;
        }
        walker = walker -> next;
    }
    return nullptr;
}

Scooter* ScooterRentalSystem::findScooter(int scooterID) {
    Scooter *walker = scooterHead;

    while (walker != nullptr) {
        if (walker -> id == scooterID) {
            return walker;
        }
        walker = walker -> next;
    }
    return nullptr;
}
string ScooterRentalSystem::getCurrentDateTime() {
    // Şu anki zaman bilgisini alıyoruz
    auto now = chrono::system_clock::now();

    // time_t formatına dönüştürüyoruz
    time_t now_time_t = chrono::system_clock::to_time_t(now);

    // Yerel zaman dilimine göre çözüyoruz
    tm local_tm = *localtime(&now_time_t);

    // String stream ile yazdırıyoruz
    stringstream ss;
    ss << put_time(&local_tm, "%Y-%m-%d %H:%M");

    return ss.str();
}
