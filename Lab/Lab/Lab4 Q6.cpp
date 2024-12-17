#include <iostream>
using namespace std;
int factorial();
int main(){
    int n;
    cout<<"Enter a number: "<<endl;
    cin>>n;
    num = factorial();
    return 0;
}
int factorial(n){
        while (n>= 1){
            n*=(n-1);
            factorial(n);
        }
    }