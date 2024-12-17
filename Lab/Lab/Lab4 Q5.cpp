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
    cout<<"Enter the second number: ";
    cin>>b;
    cout<<"Enter your choice (1-5) \n1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n5. Exit \n";
    cin>>op;
    switch (op)
    {
    case '1':
        sum(a, b);
        break;
    case '2':
        diff(a, b);
        break;
    case '3':
        product(a, b);
        break;
    case '4':
        quotient(a, b);
        break;
    case '5':
        exit = 5;
    default:
        break;
    }
    }
    while (exit != 5);
    return 0;
}

void sum(int x, int y){
    int sum = 0;
    sum = x+y;
    cout<<"x + y = "<<sum<<endl;
}

void diff(int x, int y){
    int diff = 0;
    diff = x-y;
    cout<<"x - y = "<<diff<<endl;
}

void product(int x, int y){
    int product = 1;
    product = x*y;
    cout<<"x * y = "<<product<<endl;
        
}

void quotient(int x, int y){
    int quotient;
    if (y == 0){
        cout<<"Division by 0 is not possible \n";
    }
    else{
        quotient = x/y;
        cout<<"x / y = "<<quotient<<endl;
    }
}

