#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;
void read_file()
{
    int count;
    ifstream f("Alphabet.txt", ios::in);
    string txt;
    while (!f.eof())
    {
        getline(f, txt);
        count++;
    }
    f.close();
    cout <<"Your entered "<<count<<" characters";
}
string file;
int main()
{
    string text;
    ofstream create(file, ios::out);
    cout<<"Enter a text: ";
    cin>>text;
    create<<text;
    create.close();
    read_file();

    return 0;
}