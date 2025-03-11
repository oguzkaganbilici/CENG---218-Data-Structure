#include <iostream>
#include<fstream>
#include<sstream>
#include<vector>

using namespace std;

class Node {
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

class ForwardList{
private:
    Node *head;
    int counter ;

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
            cerr << "File not found" << endl;
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
        Node *walker = head;
        int i = 1;
        cout<<"   CarType |  Brand  |  Model  |  Year  |  Status  |"<<endl;
        while (walker != nullptr) {
            cout<<i<<") "<< walker->carType << " | " << walker->Brand << " | " << walker->Model << " | " <<walker->Year<< " | "<< walker->Status << endl;
            walker = walker->next;
            i++;
        }
    }
};

int main() {

    ForwardList Cars;
    Cars.uploadTxt("cars.txt");

    int kullaniciGiris;
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
    }





    return 0;
}

// TIP See CLion help at <a
// href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>.
//  Also, you can try interactive lessons for CLion by selecting
//  'Help | Learn IDE Features' from the main menu.