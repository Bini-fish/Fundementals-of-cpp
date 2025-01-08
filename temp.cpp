#include <iostream>
#include<string.h>
using namespace std;

int number(int y){
y-=10;
return y;

}
int number2(int &y){
y-=10;
return y;
}

int main()
{
  int x = 35; 
  int r = number2(x);//25
  int v = number(x); 
  
  cout<<r<<endl;
  cout<<v<<endl;
return 0;
}
