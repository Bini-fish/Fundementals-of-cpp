#include <iostream>

using namespace std;

int main(){
    int choice, exit;
    float a,b;
    float sum, sub, quotient, dividend;
    do{
        cout<<"Enter the first number: ";
    cin>>a;
    cout<<"Enter the second number: ";
    cin>>b;
    cout<<"Which operation do you want to do? \n";
    cout<<"1. Addition\n";
    cout<<"2. Subtraction\n";
    cout<<"3. Multiplication\n";
    cout<<"4. Division\n";
    cin>>choice;

    switch (choice){
        case 1:
        cout<<"Addition: "<<a+b<<endl;
        break;
        case 2:
        cout<<"Subtraction: "<<a-b<<endl;
        break;
        case 3:
        cout<<"Product: "<<a*b<<endl;
        break;
        case 4:
        cout<<"Dividend: "<<a/b<<endl;
        break;
    }

    if (a>b){
        cout<<a<<" is Greater."<<endl;
    }
    else if (b>a){
        cout<<b<<" is Greater."<<endl;
    }
    else{
        cout<<a<<" and "<<b<<" are equal."<<endl;
    }
    cout<<"press 1 to continue\npress 2 to exit   ";
    cin>>exit;
    }
    while(exit!=2);
    
    

    return 0;
}