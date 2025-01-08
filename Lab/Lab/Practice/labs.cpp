#include <iostream>

using namespace std;
int x;
int area(int l, int w)
{
    return l * w;
}
float area(int l, float w)
{
    return l * w ;
}

int main()
{
    int x = 20;
    int y = 15.5;
    int z = 10;
    int rec;
    float sqr;
    rec = area(x, z); //200
    sqr = area(x, y); //155
    cout << rec << endl;
    cout << sqr << endl;
    return 0;
}
