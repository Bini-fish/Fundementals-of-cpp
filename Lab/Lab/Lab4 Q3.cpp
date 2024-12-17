#include <iostream>
using namespace std;
void abs_val(int);
int main(){
    int a;
    cout<<"Enter a number: ";
    cin>>a;
    abs_val(a);
    return 0;
}
void abs_val(int num){
    float abs;
    if (num >= 0){
        abs = num;
    }
    else {
        abs = -(num);
    }
    cout<<"|"<<num<<"|"<<" is "<<abs;

}