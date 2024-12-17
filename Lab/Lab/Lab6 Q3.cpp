#include <iostream>
using namespace std;

const int index = 2;
struct emp{
    int id; 
    char name[100]; 
    float sal;
};
void display_emp(emp *employee, int index);
int main(){
    emp employee[index];
    cout<<"Enter the profiles of "<<index<<" employees"<<endl;
    for (int i=0; i<index; i++){ 
    cout<<"Enter Name: "<<endl;
    cin>>employee[i].name;
    cout<<"Enter Salary: "<<endl;
    cin>>employee[i].sal;
    cout<<"Enter ID: "<<endl;
    cin>>employee[i].id;
    }
    display_emp(employee, index);

    return 0;
}
void display_emp(emp *employee, int index){
    for (int i = 0; i<index; i++){
    cout<<"Name: "<<employee[i].name<<endl;
    cout<<"ID: "<<employee[i].id<<endl;
    cout<<"Salary: "<<employee[i].sal<<endl;
    }
}