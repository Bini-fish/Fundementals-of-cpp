#include <iostream>
#include <string.h>
using namespace std;

struct Marks{
    string name; 
    int roll_num;
    float chem_marks;
    float maths_marks;
    float phy_marks;
};
const int index = 1;
void display_marks(Marks *student, int index);
int main(){
    Marks student[index];
    for (int i=0; i<index;i++){ 
        cout<<"Enter Name: "<<endl;
        cin>>student[i].name;
        cout<<"Enter Roll_num: "<<endl;
        cin>>student[i].roll_num;
        cout<<"Enter Chemistry Mark: "<<endl;
        cin>>student[i].chem_marks;
        cout<<"Enter Maths Mark: "<<endl;
        cin>>student[i].maths_marks;
        cout<<"Enter Physics Mark: "<<endl;
        cin>>student[i].phy_marks;
    }
    display_marks(student, index);
    return 0;
}
void display_marks(Marks *student, int index){
    for (int i=0; i<index; i++){
        cout<<"Profile of Student "<<i+1<<"is: "<<endl;
        cout<<"Name: "<<student[i].name<<endl;
        cout<<"Roll_num: "<<student[i].roll_num<<endl;
        cout<<"Chemistry Mark: "<<student[i].chem_marks<<endl;
        cout<<"Maths Mark: "<<student[i].maths_marks<<endl;
        cout<<"Physics Mark: "<<student[i].phy_marks<<endl;
        cout<<"Average: "<<(student[i].phy_marks+student[i].maths_marks+student[i].chem_marks)/3<<endl;
    }
}