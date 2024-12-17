#include <iostream>
#include <string.h>
#include <cstring>
#include <cmath>

using namespace std;
void mularr(int arr[], int len);

int main(){
// student id holder
/*
char adufamily[9]; //c string 


for(int i=0; i<=8; i++)
{
    cout<<"enter the name: ";
    cin>>adufamily[i];
}
for( int i=0; i<=8;i++){
cout<<adufamily[i];

}
*/
//cin.getline(adufamily,9," ");
//cout<<adufamily;

//for(int i=0; i<20;)

/*
string s1 = "Cascading style sheet";
   string s2;
   s2 += s1[0];
   for (int i=1; i < s1.length(); i++){
    if(s1[i] == ' '){
        s2 += s1[i+1];
    }
   }
   cout<<s2;
*/

/*
void sub(const char* str) {
    char word[100];  // Temporary array to store individual words
    int wordIndex = 0;  // Index for the word array

    cout << "Substrings = ";
    for (int i = 0; str[i] != '\0'; ++i) {//didn't finish looping through the loop
        if (str[i] != ' ') {  // Add characters to the word until a space is found
            word[wordIndex++] = str[i];
        } else {
            // End the current word and print it
            if (wordIndex > 0) {
                word[wordIndex] = '\0';  // Null-terminate the word
                cout << "\"" << word << "\"";
                wordIndex = 0;  // Reset for the next word
            }
        }
    }
    // Print the last word if there is one
    if (wordIndex > 0) {
        word[wordIndex] = '\0';
        cout << "\"" << word << "\"";
    }

    cout << endl;
    }
*/

int arr[5]={1,20,3,4,5};
    int max=0;
    for (int i=0;i<5;i++) {
        if (arr[i]>max)
            max=arr[i];
    }
    cout<<max<<endl;
/*
for(int i=0; i<=6;i++){
    cout<<"What's your name?";
    cin>>adufamily[i]; //(idividual character)
}
for(int i=0; i<=6;i++){
    cout<<adufamily[i];
}

cin.getline(adufamily, 7, '\n'); //input string
cout<<"The output is: "<<adufamily;
*/
/*
 // string class
string name;
cout<<"what's your name? ";
cin>>name;
cout<<name;


string last_name;
getline(cin, last_name, '.');
cout<<last_name;
*/
/*
char last_name[21];
cin.getline(last_name,20," ");
cpy = strcpy(name, last_name);//copy
cat = strcat(name, last_name);//concatinate
comp = strcomp(name, last_name);//compare
cout<<cpy<<endl;
cout<<cat<<endl;
cout<<comp<<endl;


int array1[] = {10,20,50,11,50,22};
int len = sizeof(array1)/sizeof(array1[0])
mularr(array1, len);
*/
cout<<sqrt(25);
    return 0;

}
/*
void mularr(int arr[], int l){
    int holdarr[l];
    for(int i=0; i<l;i++){
        holdarr[i] = arr[i]*4;
    }
    for (int j=0; j<l;j++){
        cout<<holdarr[j]<<", ";
    }
}
*/
