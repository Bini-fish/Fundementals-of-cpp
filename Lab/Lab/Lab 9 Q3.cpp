#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    fstream f("num.txt", ios::out);
    for (int i = 0; i < 51; i++)
    {
        f << i << " ";
    }
    f.close();
    string n;
    f.open("num.txt", ios::in);
    while (!f.eof())
    {
        getline(f, n);
    }
    f.close();
    cout << n;

    return 0;
}