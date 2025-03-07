//
//  main.cpp
//  pointerToClass
//
//  Created by Oğuz Kağan Bilici on 7.03.2025.
//

#include <iostream>
using namespace std;

class Student
{
public:
    string name;
    int age;
    
    void introduce()
    {
        cout<<"Hello my name is "<< name << " and I'm " << age << " years old." <<endl;
    }
};

int main(int argc, const char * argv[]) {
    Student s1;
    Student* s1Ptr = &s1;
    
    s1Ptr->name = "Oğuz Kağan";
    s1Ptr->age = 28;
    s1Ptr->introduce();
    cout<<"----------------------"<<endl;
    Student* students = new Student[3];
    students[0].name = "Adnan";
    students[0].age = 58;
    students[1].name = "Selda";
    students[1].age = 49;
    students[2].name = "Sıla";
    students[2].age = 22;
    
    for(int i=0;i<3;i++)
    {
        students[i].introduce();
        cout<<"----------------------"<<endl;
    }
    
    Student* deneme = new Student;
    deneme->name = "deneme";
    deneme->age = 0;
    deneme->introduce();
    return 0;
}
