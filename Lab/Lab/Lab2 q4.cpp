#include <iostream>

using namespace std;

int main(){
    int a,b;
    cout<<"Welcome\n";
    cout<<"Enter number 1: ";
    cin>>a;
    cout<<"Enter number 2: ";
    cin>>b;
    if (a>b){
        cout<<"Number "<<a<<" is greater than number "<<b<<endl;
    }
    else{
        cout<<"Number "<<b<<" is greater than number "<<a<<endl;
    }

    if (a%2 == 0){
        cout<<"Number "<<a<<" is EVEN.\n";
    }
    else{
        cout<<"Number "<<a<<" is ODD.\n";
    }
    if (b%2 == 0){
        cout<<"Number "<<b<<" is EVEN.\n";
    }
    else{
        cout<<"Number "<<b<<" is ODD.\n";
    }
    

    return 0;
}