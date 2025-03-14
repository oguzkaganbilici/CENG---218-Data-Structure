#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
#include<iomanip> // verileri daha düzenli göstermek için

#include <ctime> // tarih için
#include <string>


using namespace std;

class Node { // for car lists
    public:
        string carType, Brand, Model, Status;
        int Year, carIndex;
        Node* next;

        Node(int index, string type, string brand, string model, int year, string status = "Avaible") {
            carIndex = index;
            carType = type;
            Brand = brand;
            Model = model;
            Status = status;
            Year = year;

            next = nullptr;
        }
};

class CustomerNode { // for customers
public:
    CustomerNode* next;

    string customerName, customerSurname, customerPhoneNumber, customerAddress ;
    int customerAge, customerId;

    vector<Node*> rentedCars;
    vector<string> customerBookingHistory;

    CustomerNode(int ID, string name,string surname,string phoneNumber,string address, int age)
    {
        next = nullptr;
        customerId = ID;
        customerName = name;
        customerSurname = surname;
        customerPhoneNumber = phoneNumber;
        customerAddress = address;
        customerAge = age;
    }
};

class ForwardList{
private:
    Node *head;
    int counter;

public:
    ForwardList() {
        head = nullptr;
        counter = 0;
    }

    Node *getHead() {
        return head;
    }

    void append(int carID,string carType, string carBrand, string carModel, int carYear, string carStatus = "Avaible") {
        carID = counter;
        Node *newNode = new Node(carID, carType, carBrand, carModel, carYear, carStatus);

        if (head == nullptr) {
            newNode->next = nullptr;
            head = newNode;
        }

        else {
            Node *walker = head;
            while (walker != nullptr) {
                if (walker->next == nullptr) {
                    break;
                }
                walker = walker->next;
            }
            walker->next = newNode;
        }
        counter++;
    }

    void uploadTxt(const string& filename="cars.txt") {

        ifstream carFile(filename);

        if (!carFile.is_open()) {
            cerr << "File not found!" << endl;
        }

        string lines;
        int carId = 0;
        while (getline(carFile, lines)) {
            stringstream ss(lines);
            string type;
            string brand;
            string model;
            int year;


            getline(ss, type,',');
            getline(ss, brand, ',');
            getline(ss, model, ',');
            ss >> year;

            append(carId,type, brand, model, year);
            carId++;
        }
        carFile.close();
    }

    void print() {
        uploadTxt("cars.txt");
        
        Node *walker = head;
        
        
        cout << left
                 << setw(5)  << "ID"
                 << setw(12) << "CarType"
                 << setw(12) << "Brand"
                 << setw(12) << "Model"
                 << setw(8)  << "Year"
                 << setw(12) << "Status" << endl;
        cout << "---------------------------------------------------------------" << endl;
        
        while (walker != nullptr) {
            
            cout << left
                 << setw(5)  << walker->carIndex
                 << setw(12) << walker->carType
                 << setw(12) << walker->Brand
                 << setw(12) << walker->Model
                 << setw(8)  << walker->Year
                 << setw(12) << walker->Status
                 << endl;
            
            walker = walker->next;
        }
    }

    void searchCar(int index) {
        Node *walker = head;

        while (walker != nullptr) {
            if (walker->carIndex == index) {
                cout<<walker->carIndex <<" | " <<walker->Brand << " | " << walker->Model <<endl;
                return;
            }
            walker = walker->next;
        }
    }
    
    void const searchByType(string carType)
    {
        Node* walker = head;
        
        cout << left
                 << setw(5)  << "ID"
                 << setw(12) << "CarType"
                 << setw(12) << "Brand"
                 << setw(12) << "Model"
                 << setw(8)  << "Year"
                 << setw(12) << "Status" << endl;
        cout << "---------------------------------------------------------------" << endl;
        
        while(walker != nullptr)
        {
            if(walker->carType == carType)
            {
                cout << left
                     << setw(5)  << walker->carIndex
                     << setw(12) << walker->carType
                     << setw(12) << walker->Brand
                     << setw(12) << walker->Model
                     << setw(8)  << walker->Year
                     << setw(12) << walker->Status
                     << endl;
            }
            walker = walker -> next;
        }
    }
    
    void const searchByBrand(string carBrand)
    {
        Node *walker = head;
        cout << left
                 << setw(5)  << "ID"
                 << setw(12) << "CarType"
                 << setw(12) << "Brand"
                 << setw(12) << "Model"
                 << setw(8)  << "Year"
                 << setw(12) << "Status" << endl;
        cout << "---------------------------------------------------------------" << endl;
        
        while(walker != nullptr)
        {
            if(walker->Brand == carBrand)
            {
                cout << left
                     << setw(5)  << walker->carIndex
                     << setw(12) << walker->carType
                     << setw(12) << walker->Brand
                     << setw(12) << walker->Model
                     << setw(8)  << walker->Year
                     << setw(12) << walker->Status
                     << endl;
            }
            walker = walker -> next;
        }
    }
    
    void const searchByStatus(string carStatus)
    {
        Node *walker = head;
        
        cout << left
                 << setw(5)  << "ID"
                 << setw(12) << "CarType"
                 << setw(12) << "Brand"
                 << setw(12) << "Model"
                 << setw(8)  << "Year"
                 << setw(12) << "Status" << endl;
        cout << "---------------------------------------------------------------" << endl;
        
        while(walker != nullptr)
        {
            if(walker->Status == carStatus)
            {
                cout << left
                     << setw(5)  << walker->carIndex
                     << setw(12) << walker->carType
                     << setw(12) << walker->Brand
                     << setw(12) << walker->Model
                     << setw(8)  << walker->Year
                     << setw(12) << walker->Status
                     << endl;
            }
            walker = walker -> next;
        }
    }


};

class CustomerLists
{
private:
    CustomerNode *head;
    int customerCounter;
public:
    CustomerLists()
    {
        head = nullptr;
        customerCounter = 0;
    }
    void newCustomer(string name,string surname,string phoneNumber,string address, int age)
    {
        CustomerNode *newCustomer = new CustomerNode(customerCounter,name, surname, phoneNumber, address, age);
        CustomerNode *walker = head;

        if(head == nullptr)
        {
            head = newCustomer;
            customerCounter++;
            cout<<"New customer added!"<<endl;
            return;
        }
        else
        {
            while(walker -> next != nullptr)
            {
                walker = walker->next;
            }
            walker->next = newCustomer;
            customerCounter++;
            cout<<"New customer added!"<<endl;
        }
    }

    void const printCustomers()
    {
        CustomerNode* walker = head;
        
        cout << left
                 << setw(5)  << "ID"
                 << setw(18) << "Name"
                 << setw(18) << "Surname"
                 << setw(5)  << "Age"
                 << setw(18) << "Phone Number"
                 << setw(25) << "Address" << endl;

            cout << "---------------------------------------------------------------------------" << endl;

            while (walker != nullptr) {
                cout << left
                     << setw(5)  << walker->customerId
                     << setw(18) << walker->customerName
                     << setw(18) << walker->customerSurname
                     << setw(5)  << walker->customerAge
                     << setw(18) << walker->customerPhoneNumber
                     << setw(25) << walker->customerAddress
                     << endl;
                walker = walker->next;
            }
    }

    void rentAcar(int ID, ForwardList &carList, int carIndex) {
        CustomerNode *walker = head;
            while (walker != nullptr) {
                if (walker->customerId == ID) {
                    break;
                }
                walker = walker->next;
            }
            if (walker == nullptr) {
                cout<<"Customer could not found!"<<endl;
                return;
            }

            if (walker == nullptr) {
                cout<<"Customer could not found!"<<endl;
            }
        
        Node *carWalker = carList.getHead();
        while (carWalker != nullptr) {
            //cout << "Checking car ID: " << carWalker->carIndex << " Status: " << carWalker->Status << endl;

            if (carWalker->carIndex == carIndex && carWalker->Status == "Avaible") {
                carWalker -> Status = "Rented";

                walker->rentedCars.push_back(carWalker);
                
                string today = getCurrentDate();
                walker->customerBookingHistory.push_back(today);
                cout<<"The car is rented!"<<endl;
                return;
            }
            carWalker = carWalker->next;
        }
        cerr << "Car could not be found or is it is already rented!" << endl;
    }
    
    string getCurrentDate() {
        // Şu anki zaman bilgisini alıyoruz
        time_t now = time(0);
        
        // Yerel zamana çeviriyoruz
        struct tm *localTime = localtime(&now);
        
        // Gün, ay ve yıl değerlerini alıyoruz
        int day = localTime->tm_mday;
        int month = localTime->tm_mon + 1; // Aylar 0-11 arası olduğu için +1
        int year = localTime->tm_year + 1900; // Yıl 1900'dan başladığı için +1900
        
        // String'e çeviriyoruz
        std::ostringstream oss;
        oss << year << "-";
        
        // Ay ve günü iki haneli yazmak için kontrol ediyoruz
        if (month < 10)
            oss << "0";
        oss << month << "-";
        
        if (day < 10)
            oss << "0";
        oss << day;
        
        return oss.str();
    }

    void const printRentedCars(int customerID) {
        CustomerNode *walker = head;

        while (walker != nullptr) {
            if (walker->customerId == customerID) {
                cout << left
                << setw(5)  << "ID"
                << setw(15) << "Name"
                << setw(15) << "Surname"
                << setw(25) << "Booking History"
                << setw(25) << "Rented Cars" << endl;
                cout << "---------------------------------------------------------------------------\n";
                
                if (walker->rentedCars.empty()) {
                    cout << left
                    << setw(5)  << walker->customerId
                    << setw(15) << walker->customerName
                    << setw(15) << walker->customerSurname
                    << setw(25) << "No rented cars!"
                    << setw(25) << "-" << endl;
                }
                else {
                    for (int i=0;i<walker->rentedCars.size();i++) {
                        Node *cars = walker->rentedCars[i];
                        string carInfo = to_string(cars->carIndex) + " | " + cars->carType + " | " + cars->Brand + " | " + cars->Model +   " | " + to_string(cars->Year);
                        
                        cout << left
                        << setw(5)  << walker->customerId
                        << setw(15) << walker->customerName
                        << setw(15) << walker->customerSurname
                        << setw(25) << walker->customerBookingHistory[i]
                        << setw(25) << carInfo
                        << endl;
                    }
                    cout<<endl;
                }
            }
            walker = walker->next;
        }
    }
    
    bool checkCustomer(int index)
    {
        CustomerNode *walker = head;
        
        while(walker != nullptr){
            if(walker->customerId == index)
            {
                return true;
            }
            walker = walker -> next;
        }
        return false;
    }
};



int main() {

    ForwardList Cars;
    CustomerLists customerList;

    Cars.uploadTxt("cars.txt");
    
    
    int kullaniciGiris = 0;
    while (kullaniciGiris != 7) {
        
        
        cout<<"---- MENU ----\n"
          "1) Display all inventory\n"
          "2) Rent a car\n"
          "3) Return a car\n"
          "4) Display customer information\n"
          "5) Register new customer\n"
          "6) View customer accounts\n"
          "7) Exit\n\n\n"
          "Enter the number of selection in menu: "<<endl;
        cin>>kullaniciGiris;

        if (kullaniciGiris == 1) {
            int carSearch;
            cout<<"---- CAR MENU ----\n"
              "1) Display all inventory\n"
              "2) Search by Car Type\n"
              "3) Search by Brand\n"
              "4) Search by Status\n"
              "5) Exit\n\n\n"
              "Enter the number of selection in menu: "<<endl;
            cin>>carSearch;
            if(carSearch == 1)
            {
                Cars.print();
            }
            else if(carSearch == 2)
            {
                string carType;
                cout<<"---- CAR MENU ----\n"
                "- Economy \n"
                "- Compact \n"
                "- Midsize \n"
                "- FullSize \n"
                "- SUV \n"
                "- Crossover \n"
                "- Luxury \n"
                "- Convertible \n"
                "- Van \n"
                "- Truck \n"
                "- Electric \n"
                "- Hybrid \n"<<endl;
                
                cout<<"Enter car type that you want to rent: ";
                cin>>carType;
                cout<<endl;
                Cars.searchByType(carType);
            }
            if(carSearch == 3)
            {
                string carBrand;
                
                cout<<"---- CAR MENU ----\n"
                "- Toyota \n"
                "- Ford \n"
                "- Honda \n"
                "- Chevrolet \n"
                "- Mazda \n"
                "- Chrysler \n"
                "- Nissan \n"
                "- BMW \n"
                "- Mercedes-Benz \n"
                "- Tesla \n"<<endl;
                cout<<"Enter car brand that you want to rent: ";
                cin>>carBrand;
                cout<<endl;
                Cars.searchByBrand(carBrand);
            }
            if(carSearch == 4)
            {
                string carStatus;
                
                cout<<"---- CAR MENU ----\n"
                "- Avaible \n"
                "- Rented \n"<<endl;
                
                cout<<"Enter car status that you want to rent: ";
                cin>>carStatus;
                cout<<endl;
                Cars.searchByStatus(carStatus);
            }
        }
        
        if (kullaniciGiris == 2)
        {
            int customerID,carID;
            cout<<"Enter your customer ID : ";
            cin>>customerID;
            bool flag = customerList.checkCustomer(customerID);
            if(flag)
            {
                cout<<"Customer is found"<<endl;
                cout<<"Enter car ID that you want to rent: ";
                cin>>carID;
                customerList.rentAcar(customerID, Cars, carID);
            }
            else
            {
                cout<<"Customer is NOT found! "<<endl;
            }
            
        }

        if (kullaniciGiris == 3) {
            int carIndex;
            cout<<"Enter customer car index: ";
            cin>> carIndex;
            Cars.searchCar(carIndex);
        }
        
        if (kullaniciGiris == 4) {
            int kullaniciID;
            cout<<"Enter customer ID: ";
            cin>>kullaniciID;
            cout<<endl;

            customerList.printRentedCars(kullaniciID);
        }
        
        if(kullaniciGiris == 5)
        {
            string name, surname, phoneNumber, address;
            int age;
            cin.ignore();
            cout << "Enter customer name: ";
            getline(cin, name);
            cout<<endl;
            cout << "Enter customer surname: ";
            getline(cin, surname);
            cout<<endl;
            cout << "Enter customer age: ";
            cin >> age;
            cin.ignore();
            cout<<endl;
            cout << "Enter customer phone: ";
            getline(cin, phoneNumber);
            cout<<endl;
            cout << "Enter customer address: ";
            getline(cin, address);
            cout<<endl;
            cout<<endl;

            customerList.newCustomer(name, surname, phoneNumber, address, age);
        }

        if(kullaniciGiris == 6)
        {
            customerList.printCustomers();
        }
    }

    return 0;
}

// TIP See CLion help at <a
// href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>.
//  Also, you can try interactive lessons for CLion by selecting
//  'Help | Learn IDE Features' from the main menu.
