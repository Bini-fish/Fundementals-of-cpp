#include <iostream>
#include <string.h>
using namespace std;
int sub(int x,int &y);
/*
static int x=65;
void fun(){
    static int x = 20;
    int y = 10;
    x=x+y;
    ::x = ::x+x;
    y=y+::x;
    cout<<x<<",";
    cout<<y<<endl;
}
*/
int fact(int n){
    if (n==1 || n==0){
        return 1;
    }
    return n * fact(n-1);
}
int main(){
    
    //fun();
    //fun();
    /*
int a=5,b,c=5,d;
b=a++ + ++a;
d = c++ + c++;
cout<<a<<b<<c<<d;

    
    int f = 3, g = 4, h, k;
    h = (2 * 34 / 2 + (g++)) - 4 * f + (++f) + 4 / (++g);
    k = ++f+g++;
cout<<"The value of f is: "<<f<<endl; 
cout<<"The value of g is: "<<g<<endl; 
cout<<"The value of h is: "<<h<<endl; 
cout<<"The value of k is: "<<k<<endl;


int i,j;
for(i=1;i<10;i++){
    for(j=1;j<i;j++){
        if(j%2 == 0)
            cout<<"*"<<" ";
        cout<<j*i<<"";
    }
    cout<<endl;
}
cout<<bool(1<1);

*/

/*

int arr1[3][2];



for( int i=0; i<3; i++)
{
    for(int j=0; j<2;j++)
    {
 cin>>arr1[i][j];
    } 
}
for(int i=0; i<3;i++)
{
    for(int j=0; j<2; j++)
{
    cout<<arr1[i][j];
    cout<<" ";
}
cout<<endl;
}

int a,b;
a = 15;
b=8;
cout<<"Value of a before: "<<a;
cout<<"Value of b before: "<<b;
int result = sub(a, b);
cout<<"Value of a after: "<<a;
cout<<"Value of b after: "<<b;
cout<<"\n Value of result: "<<result;
*/

int factorial = fact(6);
cout<<factorial;
    return 0;

}

int sub(int x,int &y)
{
int z;
x-=2;
y--;
z=x-y;
return z;
}

    
  
    