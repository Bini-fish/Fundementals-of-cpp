#include <iostream>
#include <string>
#include <fstream>
using namespace std;

// int *create_arr(int n){
//     int *arr = new int[n];
//     for (int i = 0; i < n; i++){
//         arr[i] = i;
//     }
//     return arr;
// }
struct Person
{
    string name;
    int age;
};

int main()
{
    // int *ar = create_arr(5);
    // for (int i = 0; i < 5; i++){
    //     cout<<ar[i]<<" ";
    // }
    // delete[] ar;
    // return 0;

    // Person p1;
    // p1.name = "Benji";
    // Person *p;
    // p = &p1;
    // cout << (*p).name << endl;
    // cout << p->name << endl;

    const string filePath = "C:/Users/Administrator/Desktop/count_words.txt";
    const string filePath2 = "C:/Users/Administrator/Desktop/copyfile.txt";
    ofstream f(filePath, ios::out);
    f<<"This are words to be counted\nBut now it's easy than ever";
    f.close();
    ifstream r(filePath);
    // char c[100];
    // int count = 0;
    // while(!r.eof()){
    //     r>>c;
    //     cout<<c<<endl;
    //     count++;
    // }
    // cout<<count<<endl;
    ifstream d(filePath2, ios::in);
    string str;
    while(!r.eof()){
        getline(r, str);
        d << str;
    }
    
    d.close();
    r.close();
        return 0;
}