#include <iostream>
using namespace std;

int main(){
    int count, exit, limit, even_sum, odd_sum;
    do{
        cout<<"Enter the limit: ";
        cin>>limit;
        for (int i=2; i<limit; i++){
            if (i%2 == 0){
                even_sum+=i;
            }
        }
        for (int j=1; j<limit; j++){
            if (j%2 != 0){
                odd_sum*=j;
            }
        }
        cout<<"Even Sum = "<<even_sum<<endl;
        cout<<"Odd Sum = "<<odd_sum<<endl;
        count+=1;
        cout<<"Round "<<count<<endl;

        cout<<"Press 1 to continue\nPress 2 to exit  ";
        cin>>exit;
    }
    while(exit!=2);
    return 0;
}