#include <iostream>
#include <string.h>
using namespace std;

struct Emp{
    string employee_name; 
    int employee_number;
    string address;
};
const int index = 20;
void display_emp(Emp *employee, int index);
int main(){
    Emp employee[index];
    for (int i=0; i<index;i++){
        cout<<"Enter Employee Name: "<<endl;
        cin>>employee[i].employee_name;
        cout<<"Enter Employee Number: "<<endl;
        cin>>employee[i].employee_number;
        cout<<"Enter Address: "<<endl;
        cin>>employee[i].address;
    }
    display_emp(employee, index);

    return 0;
}
void display_emp(Emp *employee, int index){
    for (int i=0; i<index; i++){
    cout<<"Employee Name: "<<employee[i].employee_name<<endl;
    cout<<"Employee Number: "<<employee[i].employee_number<<endl;
    cout<<"Address: "<<employee[i].address<<endl;
    }
}