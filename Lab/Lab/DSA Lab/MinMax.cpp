#include <iostream>
using namespace std;

const int SIZE = 6;
void min_max(int *list, int size){
    int min;
    int max;
    for(int i=0; i<size;i++){
        
            if(min<list[i]){
                max = list[i];
                continue;
            }
            else{
                min=list[i];
            }
    }
    cout<<"Min: "<<min<<endl;
    cout <<"Max: " << max << endl;
}

int main(){
    int my_list[SIZE]={9,88,77,22,5,87};
    min_max(my_list, SIZE);


    return 0;
}