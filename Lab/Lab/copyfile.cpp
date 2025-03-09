// #include <iostream>
// #include <string>
// #include <fstream>
// using namespace std;

// void copy(){
//     ofstream d("C:/Users/Administrator/Desktop/copyfile.txt", ios::out);
//     ofstream s("C:/Users/Administrator/Desktop/count_words.txt",ios::out);
//     s<<"This is the new text to be copied";
//     s.close();
//     ifstream a("C:/Users/Administrator/Desktop/count_words.txt", ios::in);
//     string temp;
//     while (!a.eof()){
//         getline(a, temp);
//         d << temp;
//     }
    
//     d.close();
//     s.close();
//     ifstream outp("C:/Users/Administrator/Desktop/copyfile.txt", ios::in);
//     string outstr;
//     while(!outp.eof()){
//         getline(outp, outstr);
//         cout<<outstr;
//     }
//     outp.close();
// }

// int main(){
//     copy();
    

//     return 0;
// }

#include <iostream>
#include <fstream>



int main(){

    ofstream out("C:/Users/Administrator/Desktop/binary.bin",ios::binary | ios::out);
    ifstream w("C:/Users/Administrator/Desktop/binary.bin", ios::binary | ios::in);


    return 0;
}