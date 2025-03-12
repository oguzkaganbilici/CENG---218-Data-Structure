    #include <iostream>
    #include<fstream>
    #include<sstream>
    #include<vector>

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

        string customerName, customerSurname, customerPhoneNumber, customerAddress;
        int customerAge, customerId;

        vector<Node*> rentedCars;

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

        void append(int carID,string carType, string carBrand, string carModel, int carYear, string carStatus = "Avaible!") {
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
            cout<<" ID  |  CarType    |  Brand    |  Model    |  Year  |  Status     |"<<endl;
            cout<<"---------------------------------------------------------------------------\n";
            while (walker != nullptr) {
                cout<<walker->carIndex<<" - "<< walker->carType << " | " << walker->Brand << " | " << walker->Model << " | " <<walker->Year<< " | "<< walker->Status << endl;
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
                cout << "ID   |  Name       |  Surname   |  Age  |  Phone Number  |  Address    |\n";
                cout << "---------------------------------------------------------------------------\n";
                while (walker != nullptr) {
                    cout << walker->customerId << "   |  "
                         << walker->customerName << "   |  "
                         << walker->customerSurname << "   |  "
                         << walker->customerAge << "   |  "
                         << walker->customerPhoneNumber << "   |  "
                         << walker->customerAddress << "   |\n";
                    walker = walker->next;
                }
        }

        void rentAcar(int choice, int ID, ForwardList &carList, int carIndex) {
            CustomerNode *walker = head;
            if (choice == 1) {
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
            }
            /*
            else if (choice == 2) {
                while (walker != nullptr) {
                    if (walker->customerSurname == surname) {
                        break;
                    }
                    walker = walker->next;
                }*/
                if (walker == nullptr) {
                    cout<<"Customer could not found!"<<endl;
                }
            Node *carWalker = carList.getHead();
            //int index = 0;
            while (carWalker != nullptr) {
                cout << "Checking car ID: " << carWalker->carIndex << " Status: " << carWalker->Status << endl;

                if (carWalker->carIndex == carIndex ) { // && carWalker->Status == "Avaible"
                    carWalker -> Status = "Rented";

                    walker->rentedCars.push_back(carWalker);
                    cout<<"The car is rented!"<<endl;
                    return;
                }
                carWalker = carWalker->next;
            }
            cout << "Car could not be found or is already rented!" << endl;
        }
            //walker->rentedCars.push_back(carWalker);

        void const printRentedCars(int customerID) {
            CustomerNode *walker = head;

            while (walker != nullptr) {
                if (walker->customerId == customerID) {
                    cout << "ID   |  Name       |  Surname   |  Rented Cars  |  Booking History  |\n";
                    cout << "---------------------------------------------------------------------------\n";
                    cout<< walker->customerId<< "   |  "
                        << walker->customerName<<"  |  "
                        << walker->customerSurname << "   |  ";
                    if (walker->rentedCars.empty()) {
                        cout<<"No rented cars!"<<endl;
                    }
                    else {
                        for (int i=0;i<walker->rentedCars.size();i++) {
                            Node *cars = walker->rentedCars[i];
                            cout<<cars->Brand << "-" << cars->Model<< "|  "<<endl;
                            delete cars;
                        }

                        cout<<endl;
                    }
                }
                walker = walker->next;
            }
        }
    };



    int main() {

        ForwardList Cars;
        CustomerLists customerList;


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
                Cars.print();
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
            if (kullaniciGiris == 2)
            {
                string customerSurname;
                int choice,customerID, carID;
                cout<<"Do you want to enter customer ID or surname:"
                      "1) ID"
                      "2) Surname\n";
                cin>>choice;
                cout<<endl;
                if(choice == 1) {
                    cout<<"Enter customer ID: ";
                    cin>>customerID;
                    cout<<endl;
                    cout<<"Enter car ID that you want to rent: ";
                    cin>>carID;
                    customerList.rentAcar(choice, customerID, Cars, carID);

                }
                else {
                    cout<<"Enter customer surname: ";
                    cin>>customerSurname;
                    cout<<endl;
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