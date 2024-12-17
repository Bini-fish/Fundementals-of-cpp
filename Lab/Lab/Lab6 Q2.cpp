#include <iostream>
#include <string.h>
using namespace std;

struct Person{ //stud[i].person.name;
    string name;
    int age;
}; 
struct Student
{
    int roll_num;
    float grade;
    Person person;
};
void display_std(Student *stud, int index);

const int index = 2;

int main()
{
    Student stud[index]; 
    cout<<"Enter the profiles of "<<index<<" Students"<<endl;
    for (int i=0; i<index; i++){ 
    cout<<"Enter Name: "<<endl;
    cin>>stud[i].person.name;
    cout<<"Enter Age: "<<endl;
    cin>>stud[i].person.age;
    cout<<"Enter Roll_num: "<<endl;
    cin>>stud[i].roll_num;
    cout<<"Enter Grade: "<<endl;
    cin>>stud[i].grade;
    }
    display_std(stud, index);
    return 0;
}
void display_std(Student *stud, int index){
    for (int i = 0; i<index; i++){
    cout<<"Roll_num: "<<stud[i].roll_num<<endl;
    cout<<"Name: "<<stud[i].person.name<<endl;
    cout<<"Age: "<<stud[i].person.age<<endl;
    cout<<"Grade: "<<stud[i].grade<<endl;  
    }
}