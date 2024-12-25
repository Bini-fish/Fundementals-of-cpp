#include <iostream>

using namespace std;
void swap(int *x,int *y);
int main(){
    int a = 50;
    int b = 60;
    cout<<"Value of A before swap: "<<a<<endl;
    cout<<"Value of B before swap: "<<b<<endl;
    swap(&a, &b);
    cout<<"Value of A after swap: "<<a<<endl;
    cout<<"Value of B after swap: "<<b<<endl;
    return 0;
}
void swap(int *x, int *y){
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}