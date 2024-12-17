#include <iostream>
using namespace std;

struct Company{
    char name[50]; 
    int address; 
    int phone;
    int noOfEmployees; 
};
void display_comp(Company);

int main(){
    Company emp;
    cout<<"Enter the name of the Company"<<endl;
    cin>>emp.name;
    cout<<"Enter the Address of the Company"<<endl;
    cin>>emp.address;
    cout<<"Enter the Phone Number of the Company"<<endl;
    cin>>emp.phone;
    cout<<"Enter the Number of employees of the Company"<<endl;
    cin>>emp.noOfEmployees;
    display_comp(emp);

    return 0;
}
void display_comp(Company c){
    cout<<"Name: "<<c.name<<endl;
    cout<<"Address: "<<c.address<<endl;
    cout<<"Phone Number: "<<c.phone<<endl;
    cout<<"No of Employees: "<<c.noOfEmployees<<endl;
};