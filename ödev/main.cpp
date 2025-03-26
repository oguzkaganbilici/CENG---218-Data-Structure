#include <iostream>
#include "ScooterRentalSystem.h"

#include <ctime>
#include <sstream>
#include <chrono>
#include <iomanip>


using namespace std;

void clearConsole() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}
void printMenu() {
    cout << endl;
    cout << "+--------------------------------------------+" << endl;
    cout << "|              MENU SYSTEM                   |" << endl;
    cout << "+--------------------------------------------+" << endl;
    cout << "|  1. List Available Scooters                |" << endl;
    cout << "|  2. Rent a Scooter                         |" << endl;
    cout << "|  3. Return a Scooter                       |" << endl;
    cout << "|  4. View Customer Rental History           |" << endl;
    cout << "|  5. Register a New Scooter                 |" << endl;
    cout << "|  6. Delete a Scooter                       |" << endl;
    cout << "|  7. Update a Scooter                       |" << endl;
    cout << "|  8. Register a New Customer                |" << endl;
    cout << "|  9. Delete a Customer                      |" << endl;
    cout << "| 10. Update a Customer                      |" << endl;
    cout << "+--------------------------------------------+" << endl;
    cout << "| 11. Exit                                   |" << endl;
    cout << "+--------------------------------------------+" << endl;
    cout << endl;
}

string getCurrentDateTime() {
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

int main() {

    ScooterRentalSystem newSystem;
    newSystem.uploadScooterTxt();
    newSystem.uploadCustomerTxt();
    clearConsole();

    int kullaniciGiris = 0;
    while (kullaniciGiris != 11)
    {
        printMenu();
        cout<<"Enter your selection: ";
        cin>>kullaniciGiris;

        if (kullaniciGiris == 1) {
            newSystem.listAvailableScooters();
        }
        if (kullaniciGiris == 2) {
            int kullaniciID, scooterID;
            cout<<"Enter customer ID: ";
            cin>>kullaniciID;
            cout<<"\nEnter scooter ID: ";
            cin>>scooterID;
            newSystem.rentScooter(scooterID, kullaniciID);
        }
        if (kullaniciGiris == 3) {
            int scooterID;
            cout<<"\nEnter scooter ID: ";
            cin>>scooterID;
            newSystem.returnScooter(scooterID);
        }
        if (kullaniciGiris == 4) {
            int kullaniciID;
            cout<<"Enter customer ID: ";
            cin>>kullaniciID;
            newSystem.viewCustomerHistory(kullaniciID);
        }
        if (kullaniciGiris == 5) {
            string location;
            int battery_level;
            int distance;

            cout<<"Enter scooter location: ";
            cin>>location;
            cout<<"\nEnter battery level of scooter: ";
            cin>>battery_level;
            cout<<"\nEnter distance of scooter: ";
            cin>>distance;

            newSystem.addScooter(location, 0, battery_level, distance, getCurrentDateTime());
        }
        if (kullaniciGiris == 6) {
            int index;
            cout<<"Enter a scooter ID that you want to delete: ";
            cin>>index;
            newSystem.deleteScooter(index);
        }
        if (kullaniciGiris == 7) {
            int index;
            string loc;
            int battery, distance;

            cout<<"Enter a scooter ID that you want to update: ";
            cin>>index;

            cout<<"\nEnter new location: ";
            getline(cin>>ws, loc);
            cout<<"\nEnter new battery level: ";
            cin>>battery;
            cout<<"\nEnter new distance: ";
            cin>>distance;
            newSystem.updateScooter(index, loc, battery, distance, getCurrentDateTime());

        }
        if (kullaniciGiris == 8) {
            string customerName_customerSurname, customerTelephone, customerEmail, customerAddress;
            cout<<"Enter the customer name and surname: ";
            getline(cin>>ws, customerName_customerSurname);
            cout<<"\nEnter the customer telephone: ";
            getline(cin, customerTelephone);
            cout<<"\nEnter the customer e-mail: ";
            getline(cin, customerEmail);
            cout<<"\nEnter the customer address: ";
            getline(cin, customerAddress);

            newSystem.registerCustomer(customerName_customerSurname, customerTelephone,  customerEmail, customerAddress);
            newSystem.displayCustomerInformation();
        }
        if (kullaniciGiris == 9) {
            int kullaniciID;
            cout<<"Enter the customer ID that you want to delete: ";
            cin>> kullaniciID;
            cout<<endl;
            newSystem.deleteCustomer(kullaniciID);

            newSystem.displayCustomerInformation();

            printMenu();
        }
        if (kullaniciGiris == 10) {
            int kullaniciID;
            std::string name_surname, telephone, email, address;

            cout<<"Enter the customer ID that you want to update: ";
            cin>> kullaniciID;
            cout<<"\nEnter the new name and surname: ";
            getline(cin>>ws, name_surname);
            cout<<"\nEnter the new telephone: ";
            getline(cin, telephone);
            cout<<"\nEnter the new e-mail: ";
            getline(cin, email);
            cout<<"\nEnter the new address: ";
            getline(cin, address);

            newSystem.updateCustomer(kullaniciID,name_surname, telephone, email, address);

            newSystem.displayCustomerInformation();
        }
    }
    return 0;
}

// TIP See CLion help at <a
// href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>.
//  Also, you can try interactive lessons for CLion by selecting
//  'Help | Learn IDE Features' from the main menu.
