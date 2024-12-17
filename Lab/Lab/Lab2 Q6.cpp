#include <iostream>

using namespace std;

int main(){
    float total, average;
    float grade[10] = {};
    for (int i=0; i<10; i++){
        cout<<"Enter mark: ";
        cin>>grade[i];
    }
    for (int j=0; j<10; j++){
        total+=grade[j];
    }
    average = total/10;
    cout<<"Class Average is: "<<average;
                                                                                                                                                                                                                                                                                                        

    return 0;
}