#include <iostream>
using namespace std;

int main(){
    int index;
    // Asking how may elements does our array take.
    cout<<"How many do numbers you want to add? ";
    cin>>index;
    int list_of_num[index];
    // alt method (am) int *ptr = list_of_num
    // Taking the numbers from the user
    for (int i=0; i<index; i++){
            cout<<"Enter Element "<<i+1<<": ";
            cin>>*(list_of_num+i);
            // am: ptr[i]
        }
    cout<<"ptr = [ ";
    for (int j=0; j<index; j++){
        cout<<*(list_of_num+j)<<",";
        // am: ptr[j]
        
    }
    cout<<"]";
    return 0;
}