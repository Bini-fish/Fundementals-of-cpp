#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    float a;
    int rounded;

    cout << "Enter a number: ";
    cin >> a;
    rounded = static_cast<int>(round(a));
    // rounded = round(a);
    cout << typeid(a);
    cout << a << " converted to an int is: " << rounded;
    return 0;
}