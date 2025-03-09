#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

int main()
{
    ofstream create("file.txt", ios::out);
    create << "Today is the last class of C++ programming ";
    create.close();
    ifstream read("file.txt", ios::in);
    string temp_store;
    while (!read.eof())
    {
        getline(read, temp_store);
    }
    read.close();
    cout << temp_store;

    return 0;
}