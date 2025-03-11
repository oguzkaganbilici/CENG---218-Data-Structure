    #include <iostream>
    #include<fstream>
    #include<sstream>
    #include<vector>

    using namespace std;

    class Node { // for car lists
        public:
            string carType, Brand, Model, Status;
            int Year;
            Node* next;

            Node(string type, string brand, string model, int year, string status = "Avaible!") {
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
        int customerAge;
        
        CustomerNode(string name,string surname,string phoneNumber,string address, int age)
        {
            next = nullptr;
            
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

        void append(string carType, string carBrand, string carModel, int carYear, string carStatus = "Avaible!") {
            Node *newNode = new Node(carType, carBrand, carModel, carYear, carStatus);

            if (head == nullptr) {
                newNode->next = nullptr;
                head = newNode;
                counter++;
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
        }

        void uploadTxt(const string& filename="cars.txt") {

            ifstream carFile(filename);

            if (!carFile.is_open()) {
                cerr << "File not found!" << endl;
            }

            string lines;

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

                append(type, brand, model, year);
            }
            carFile.close();
        }

        void print() {
            uploadTxt("cars.txt");
            
            Node *walker = head;
            int i=1;
            cout<<"   CarType |  Brand  |  Model  |  Year  |  Status  |"<<endl;
            while (walker != nullptr) {
                cout<<i<<") "<< walker->carType << " | " << walker->Brand << " | " << walker->Model << " | " <<walker->Year<< " | "<< walker->Status << endl;
                walker = walker->next;
                i++;
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
            CustomerNode *newCustomer = new CustomerNode(name, surname, phoneNumber, address, age);
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
        
        void printCustomers()
        {
            CustomerNode* walker = head;
                cout << "  Name       |  Surname   |  Age  |  Phone Number  |  Address    |\n";
                cout << "---------------------------------------------------------------------------\n";
                while (walker != nullptr) {
                    cout << walker->customerName << "   |  "
                         << walker->customerSurname << "   |  "
                         << walker->customerAge << "   |  "
                         << walker->customerPhoneNumber << "   |  "
                         << walker->customerAddress << "   |\n";
                    walker = walker->next;            }
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
