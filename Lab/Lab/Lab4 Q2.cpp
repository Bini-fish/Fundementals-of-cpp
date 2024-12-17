#include <iostream>
using namespace std;

// Write a C++ function that accepts two numbers and finds sum, difference, product and quotient
// of the numbers. Write a four functions for those operations?

void sum(int x, int y);
void diff(int x, int y);
void product(int x, int y);
void quotient(int x, int y);

int main(){
    int a, b, exit;
    char op;
    do {
    cout<<"Enter the first number: ";
    cin>>a;
    cout<<"Choose an operation: + | - | * | / \n";
    cin>>op;
    cout<<"Enter the second number: ";
    cin>>b;
    

    switch (op)
    {
    case '+':
        sum(a, b);
        break;
    case '-':
        diff(a, b);
        break;
    case '*':
        product(a, b);
        break;
    case '/':
        quotient(a, b);
        break;
    default:
        break;
    }
    cout<<"\nPress 1 to exit \nPress 2 to continue: ";
    cin>>exit;
    }
    while (exit!=1);
    return 0;
}

void sum(int x, int y){
    int sum = 0;
    sum = x+y;
    cout<<"x + y = "<<sum;
}

void diff(int x, int y){
    int diff = 0;
    diff = x-y;
    cout<<"x - y = "<<diff;
}

void product(int x, int y){
    int product = 1;
    product = x*y;
    cout<<"x * y = "<<product;
        
}

void quotient(int x, int y){
    int quotient;
    if (y == 0){
        cout<<"Division by 0 is not possible \n";
    }
    else{
        quotient = x/y;
        cout<<"x / y = "<<quotient;
    }
}

