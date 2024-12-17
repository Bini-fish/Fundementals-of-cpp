#include <iostream>

using namespace std;

int main(){
    cout<<"For loop\n";
    for (int i = 10; i>=0; i--){
        if (i == 5){
            continue;
        }
        else{
            cout<<i<<" ";
        }
    }
    int j=10;
    cout<<"\nWhile loop\n";
    while (j>=0){
        if (j != 5){
            cout<<j<<" ";
        }
        j--;
    }
    cout<<"\nDo-while loop\n";
    int k = 10;
    do{
        
        if (k!=5){
            cout<<k<<" ";
        }
        k--;
    }
    while(k >= 0);
    return 0;
}