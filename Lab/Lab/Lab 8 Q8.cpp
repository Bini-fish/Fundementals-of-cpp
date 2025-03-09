#include <iostream>
using namespace std;
void increment(int i, int *pi);
int main()
{
    int a = 1, b = 2;
    cout << "The value of a & b is:" << a << " " << b << endl;
    increment(a, &b);
    cout << "The value of a & b is:" << a << " " << b << endl;
    return 0;
}
void increment(int i, int *pi)
{
    i = i + 1;
    *pi = *pi + 1;
    cout << "The value of i & pi is:" << i << " " << *pi << endl;
}
