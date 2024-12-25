#include <iostream>
using namespace std;

int main(){
    int a,b;
    
    cout<<"Enter the value of a: ";
    cin>>a;
    cout<<"Enter the value of b: ";
    cin>>b;
    int *aptr = &a;
    int *bptr = &b;
    int c;
    c = *aptr + *bptr;
    cout<<"Value of aptr: "<<aptr<<endl;
    cout<<"Value of bptr: "<<bptr<<endl;
    cout<<"Value of *aptr point to : "<<*aptr<<endl;
    cout<<"Value of *bptr point to: "<<*bptr<<endl;
    cout<<"Sum of *aptr and *bptr: "<<c<<endl;

    return 0;
}