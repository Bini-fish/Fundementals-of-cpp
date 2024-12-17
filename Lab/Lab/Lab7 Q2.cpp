#include <iostream>
#include <string.h>
using namespace std;

struct BTC{
    int RollNo; 
    char Name[30]; 
    char Address[30]; 
    int Age;
    float average_marks;
};
const int index = 2;

void display_stud(BTC *s, int index);

int main(){
    BTC student[index];
    for (int i=0; i<index; i++){
    cout<<"Enter the Roll Number of Student "<<i+1<<endl;
    cin>>student[i].RollNo;
    cout<<"Enter the name of the Student"<<endl;
    cin.getline(student[i].Name, 30);
    cout<<"Enter the Address of the Student"<<endl;
    cin.getline(student[i].Address, 30);
    cout<<"Enter the Age of the Student"<<endl;
    cin>>student[i].Age;
    cout<<"Enter the Average Mark of the Student"<<endl;
    cin>>student[i].average_marks;
    }
    display_stud(student, index);
    return 0;
}
void display_stud(BTC *s, int index){
    for (int i=0; i<index; i++){
    cout<<"--------------------------Student "<<i+1<<"--------------------------------\n";
    cout<<"Roll Number: "<<s[i].RollNo<<endl;
    cout<<"name: "<<s[i].Name<<endl;
    cout<<"Address: "<<s[i].Address<<endl;
    cout<<"Age: "<<s[i].Age<<endl;
    cout<<"Average Mark: "<<s[i].average_marks<<endl;
    }
}