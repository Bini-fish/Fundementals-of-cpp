#include <iostream>
using namespace std;

int main(){
    int a = 20;
    int *ptr = &a;
    cout<<"Value of a: "<<a<<endl;
    cout<<"Value of pointer ptr: "<<ptr<<endl;
    cout<<"Value of *ptr: "<<*ptr<<endl;
    cout<<"Value of &a: "<<&a<<endl;
    return 0;
}