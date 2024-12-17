#include <iostream>
using namespace std;

struct complex
{
 int realP;
 int imagP;
};

complex sum(complex, complex);

int main(){
    complex a,b;
    cout<<"Enter a Real Number: ";
    cin>>a.realP;
    cout<<"Enter an Imaginary Number: ";
    cin>>a.imagP;
    cout<<"Enter The second Real Number: ";
    cin>>b.realP;
    cout<<"Enter The second Imaginary Number: ";
    cin>>b.imagP;
    complex c = sum(a,b);
    cout<<"Real: "<<c.realP<<endl;
    cout<<"Imaginary: "<<c.imagP<<endl;
    return 0;
}
complex sum(complex x, complex y){
    complex sum;
    sum.realP = x.realP + y.realP;
    sum.imagP = x.imagP + y.imagP;
    return sum;
}