#include <iostream>
using namespace std;

int main(){
    int a,b;
    
    cout<<"Enter the value of a: "<<endl;
    cin>>a;
    cout<<"Enter the value of b: "<<endl;
    cin>>b;
    int *aptr = &a;
    int *bptr = &b;
    cout<<"Value of aptr: "<<aptr<<endl;
    cout<<"Value of bptr: "<<bptr<<endl;
    cout<<"Value of *aptr point to : "<<*aptr<<endl;
    cout<<"Value of *bptr point to: "<<*bptr<<endl;
    return 0;
}