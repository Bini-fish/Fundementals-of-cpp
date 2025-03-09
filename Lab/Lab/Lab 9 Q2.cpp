#include <iostream>
#include <fstream>
#include <string>

using namespace std;
int main()
{
    ofstream f("mytext.txt", ios::out);
    f << "A computer program consists of code that is executed on a computer to perform particular tasks.This code is written by programmers.";
    f.close();
    string text;
    ifstream f1("mytext.txt", ios::in);
    f1.seekg(95);
    getline(f1, text);
    f1.close();
    cout << text;

    return 0;
}