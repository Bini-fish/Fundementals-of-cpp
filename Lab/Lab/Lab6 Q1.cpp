#include <iostream>
#include <string.h>
using namespace std;

struct Person{
    string name;
    int age;
    string dept;
};

int main()
{
    Person Student;
    Student = {"Biniyam", 20, "IS"};
    cout<<"Name: "<<Student.name<<endl;
    cout<<"Age: "<<Student.age<<endl;
    cout<<"Departement: "<<Student.dept<<endl;

    return 0;
}