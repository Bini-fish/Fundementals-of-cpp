#include <iostream>
using namespace std;
void swap_val(float, float);
void ref_swap_val(int &a, int &b);
int main(){
    int a,b;
    cout<<"Enter the first number: ";
    cin>>a;
    cout<<"Enter the second number: ";
    cin>>b;
    cout<<"Pass by value\n";
    cout<<"Before swap a = "<<a<<" b = "<<b<<endl;
    swap_val(a, b);
    cout<<"After swap a = "<<a<<" b = "<<b<<endl;
    cout<<"pass by Reference\n";
    cout<<"Before swap a = "<<a<<" b = "<<b<<endl;
    ref_swap_val(a, b);
    cout<<"After swap a = "<<a<<" b = "<<b<<endl;
    return 0;
}
void swap_val(float a, float b){
    float z;
    z = a;
    a = b;
    b = z;
}
void ref_swap_val(int &a, int &b){
    float z;
    z = a;
    a = b;
    b = z;
}